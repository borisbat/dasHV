/*
 * json rpc client
 *
 * @build   make jsonrpc
 * @server  bin/jsonrpc_server 1234
 * @client  bin/jsonrpc_client 127.0.0.1 1234 add 1 2
 *
 */

#include "hloop.h"
#include "hatomic.h"
#include "hbase.h"
#include "hsocket.h"

#include "cJSON.h"

// hloop_create_tcp_client -> on_connect -> hio_write -> hio_read -> on_recv

static int verbose = 0;
static unpack_setting_t jsonrpc_unpack_setting;

static void on_close(hio_t* io) {
    printf("on_close fd=%d error=%d\n", hio_fd(io), hio_error(io));
    cJSON* jreq = (cJSON*)(hevent_userdata(io));
    if (jreq) {
        cJSON_Delete(jreq);
        hevent_set_userdata(io, NULL);
    }

    hloop_stop(hevent_loop(io));
}

static void on_recv(hio_t* io, void* readbuf, int readbytes) {
    // printf("on_recv fd=%d readbytes=%d\n", hio_fd(io), readbytes);
    if (verbose) {
        char localaddrstr[SOCKADDR_STRLEN] = {0};
        char peeraddrstr[SOCKADDR_STRLEN] = {0};
        printf("[%s] <=> [%s]\n",
                SOCKADDR_STR(hio_localaddr(io), localaddrstr),
                SOCKADDR_STR(hio_peeraddr(io), peeraddrstr));
    }

    char* resp_str = (char*)readbuf;
    printf("< %s\n", resp_str);
    // cJSON_Parse
    cJSON* jres = cJSON_Parse(resp_str);
    cJSON* jerror = cJSON_GetObjectItem(jres, "error");
    cJSON* jresult = cJSON_GetObjectItem(jres, "result");
    // ...
    cJSON_Delete(jres);

    hio_close(io);
}

static void on_connect(hio_t* io) {
    printf("on_connect fd=%d\n", hio_fd(io));
    if (verbose) {
        char localaddrstr[SOCKADDR_STRLEN] = {0};
        char peeraddrstr[SOCKADDR_STRLEN] = {0};
        printf("connect connfd=%d [%s] => [%s]\n", hio_fd(io),
            SOCKADDR_STR(hio_localaddr(io), localaddrstr),
            SOCKADDR_STR(hio_peeraddr(io), peeraddrstr));
    }

    hio_setcb_read(io, on_recv);
    hio_set_unpack(io, &jsonrpc_unpack_setting);
    hio_read(io);

    cJSON* jreq = (cJSON*)(hevent_userdata(io));
    hevent_set_userdata(io, NULL);
    assert(jreq != NULL);

    // cJSON_Print -> hio_write
    char* req_str = cJSON_PrintUnformatted(jreq);
    printf("> %s\n", req_str);
    // NOTE: +1 for \0
    hio_write(io, req_str, strlen(req_str) + 1);

    cJSON_Delete(jreq);
    cJSON_free(req_str);
}

static int jsonrpc_call(hloop_t* loop, const char* host, int port, const char* method, const char* param1, const char* param2) {
    hio_t* connio = hio_create_socket(loop, host, port, HIO_TYPE_TCP, HIO_CLIENT_SIDE);
    if (connio == NULL) {
        return -1;
    }
    // printf("connfd=%d\n", hio_fd(connio));

    // construct request
    cJSON* jreq = cJSON_CreateObject();
    static hatomic_t s_id = HATOMIC_VAR_INIT(0);
    cJSON_AddItemToObject(jreq, "id", cJSON_CreateNumber(++s_id));
    cJSON_AddItemToObject(jreq, "method", cJSON_CreateString(method));
    cJSON* jparams = cJSON_CreateArray();
    cJSON_AddItemToArray(jparams, cJSON_CreateNumber(atoi(param1)));
    cJSON_AddItemToArray(jparams, cJSON_CreateNumber(atoi(param2)));
    cJSON_AddItemToObject(jreq, "params", jparams);
    hevent_set_userdata(connio, jreq);

    hio_setcb_connect(connio, on_connect);
    hio_setcb_close(connio, on_close);
    hio_connect(connio);
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 6) {
        printf("Usage: %s host port method param1 param2\n", argv[0]);
        printf("method = [add, sub, mul, div]\n");
        printf("Examples:\n");
        printf("  %s 127.0.0.1 1234 add 1 2\n", argv[0]);
        printf("  %s 127.0.0.1 1234 div 1 0\n", argv[0]);
        return -10;
    }
    const char* host = argv[1];
    int port = atoi(argv[2]);
    const char* method = argv[3];
    const char* param1 = argv[4];
    const char* param2 = argv[5];

    // init jsonrpc_unpack_setting
    memset(&jsonrpc_unpack_setting, 0, sizeof(unpack_setting_t));
    jsonrpc_unpack_setting.mode = UNPACK_BY_DELIMITER;
    jsonrpc_unpack_setting.package_max_length = DEFAULT_PACKAGE_MAX_LENGTH;
    jsonrpc_unpack_setting.delimiter[0] = '\0';
    jsonrpc_unpack_setting.delimiter_bytes = 1;

    hloop_t* loop = hloop_new(0);

    jsonrpc_call(loop, host, port, method, param1, param2);

    hloop_run(loop);
    hloop_free(&loop);
    return 0;
}
