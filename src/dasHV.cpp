#include "daScript/misc/platform.h"


#include "../../../src/builtin/module_builtin_rtti.h"

#include "dasHV.h"

IMPLEMENT_EXTERNAL_TYPE_FACTORY(WebSocketClient,hv::WebSocketClient)
IMPLEMENT_EXTERNAL_TYPE_FACTORY(WebSocketServer,hv::WebSocketServer)
IMPLEMENT_EXTERNAL_TYPE_FACTORY(WebSocketChannel,hv::WebSocketChannel)
IMPLEMENT_EXTERNAL_TYPE_FACTORY(HttpMessage,HttpMessage)
IMPLEMENT_EXTERNAL_TYPE_FACTORY(HttpRequest,HttpRequest)
IMPLEMENT_EXTERNAL_TYPE_FACTORY(HttpResponse,HttpResponse)
IMPLEMENT_EXTERNAL_TYPE_FACTORY(HttpContext,hv::HttpContext)

namespace das {

class Enumeration_ws_opcode : public das::Enumeration {
public:
    Enumeration_ws_opcode() : das::Enumeration("ws_opcode") {
        external = true;
        cppName = "ws_opcode";
        baseType = (das::Type) das::ToBasicType< das::underlying_type< ws_opcode >::type >::type;
		addIEx("WS_OPCODE_CONTINUE",    "WS_OPCODE_CONTINUE",   int64_t(ws_opcode::WS_OPCODE_CONTINUE), das::LineInfo());
		addIEx("WS_OPCODE_TEXT",        "WS_OPCODE_TEXT",       int64_t(ws_opcode::WS_OPCODE_TEXT), das::LineInfo());
		addIEx("WS_OPCODE_BINARY",      "WS_OPCODE_BINARY",     int64_t(ws_opcode::WS_OPCODE_BINARY), das::LineInfo());
		addIEx("WS_OPCODE_CLOSE",       "WS_OPCODE_CLOSE",      int64_t(ws_opcode::WS_OPCODE_CLOSE), das::LineInfo());
		addIEx("WS_OPCODE_PING",        "WS_OPCODE_PING",       int64_t(ws_opcode::WS_OPCODE_PING), das::LineInfo());
		addIEx("WS_OPCODE_PONG",        "WS_OPCODE_PONG",       int64_t(ws_opcode::WS_OPCODE_PONG), das::LineInfo());
	}
};

class Enumeration_ws_session_type : public das::Enumeration {
public:
    Enumeration_ws_session_type() : das::Enumeration("ws_session_type") {
        external = true;
        cppName = "ws_session_type";
        baseType = (das::Type) das::ToBasicType< das::underlying_type< ws_session_type >::type >::type;
		addIEx("WS_CLIENT", "WS_CLIENT",    int64_t(ws_session_type::WS_CLIENT), das::LineInfo());
		addIEx("WS_SERVER", "WS_SERVER",    int64_t(ws_session_type::WS_SERVER), das::LineInfo());
	}
};

class Enumeration_http_method : public das::Enumeration {
public:
    Enumeration_http_method() : das::Enumeration("http_method") {
        external = true;
        cppName = "http_method";
        baseType = (das::Type) das::ToBasicType< das::underlying_type< http_method >::type >::type;
        addIEx("DELETE",        "HTTP_DELETE",       int64_t(http_method::HTTP_DELETE),      das::LineInfo());
        addIEx("GET",           "HTTP_GET",          int64_t(http_method::HTTP_GET),         das::LineInfo());
        addIEx("HEAD",          "HTTP_HEAD",         int64_t(http_method::HTTP_HEAD),        das::LineInfo());
        addIEx("POST",          "HTTP_POST",         int64_t(http_method::HTTP_POST),        das::LineInfo());
        addIEx("PUT",           "HTTP_PUT",          int64_t(http_method::HTTP_PUT),         das::LineInfo());
        addIEx("CONNECT",       "HTTP_CONNECT",      int64_t(http_method::HTTP_CONNECT),     das::LineInfo());
        addIEx("OPTIONS",       "HTTP_OPTIONS",      int64_t(http_method::HTTP_OPTIONS),     das::LineInfo());
        addIEx("TRACE",         "HTTP_TRACE",        int64_t(http_method::HTTP_TRACE),       das::LineInfo());
        addIEx("COPY",          "HTTP_COPY",         int64_t(http_method::HTTP_COPY),        das::LineInfo());
        addIEx("LOCK",          "HTTP_LOCK",         int64_t(http_method::HTTP_LOCK),        das::LineInfo());
        addIEx("MKCOL",         "HTTP_MKCOL",        int64_t(http_method::HTTP_MKCOL),       das::LineInfo());
        addIEx("MOVE",          "HTTP_MOVE",         int64_t(http_method::HTTP_MOVE),        das::LineInfo());
        addIEx("PROPFIND",      "HTTP_PROPFIND",     int64_t(http_method::HTTP_PROPFIND),    das::LineInfo());
        addIEx("PROPPATCH",     "HTTP_PROPPATCH",    int64_t(http_method::HTTP_PROPPATCH),   das::LineInfo());
        addIEx("SEARCH",        "HTTP_SEARCH",       int64_t(http_method::HTTP_SEARCH),      das::LineInfo());
        addIEx("UNLOCK",        "HTTP_UNLOCK",       int64_t(http_method::HTTP_UNLOCK),      das::LineInfo());
        addIEx("BIND",          "HTTP_BIND",         int64_t(http_method::HTTP_BIND),        das::LineInfo());
        addIEx("REBIND",        "HTTP_REBIND",       int64_t(http_method::HTTP_REBIND),      das::LineInfo());
        addIEx("UNBIND",        "HTTP_UNBIND",       int64_t(http_method::HTTP_UNBIND),      das::LineInfo());
        addIEx("ACL",           "HTTP_ACL",          int64_t(http_method::HTTP_ACL),         das::LineInfo());
        addIEx("REPORT",        "HTTP_REPORT",       int64_t(http_method::HTTP_REPORT),      das::LineInfo());
        addIEx("MKACTIVITY",    "HTTP_MKACTIVITY",   int64_t(http_method::HTTP_MKACTIVITY),  das::LineInfo());
        addIEx("CHECKOUT",      "HTTP_CHECKOUT",     int64_t(http_method::HTTP_CHECKOUT),    das::LineInfo());
        addIEx("MERGE",         "HTTP_MERGE",        int64_t(http_method::HTTP_MERGE),       das::LineInfo());
        addIEx("MSEARCH",       "HTTP_MSEARCH",      int64_t(http_method::HTTP_SEARCH),      das::LineInfo());
        addIEx("NOTIFY",        "HTTP_NOTIFY",       int64_t(http_method::HTTP_NOTIFY),      das::LineInfo());
        addIEx("SUBSCRIBE",     "HTTP_SUBSCRIBE",    int64_t(http_method::HTTP_SUBSCRIBE),   das::LineInfo());
        addIEx("UNSUBSCRIBE",   "HTTP_UNSUBSCRIBE",  int64_t(http_method::HTTP_UNSUBSCRIBE), das::LineInfo());
        addIEx("PATCH",         "HTTP_PATCH",        int64_t(http_method::HTTP_PATCH),       das::LineInfo());
        addIEx("PURGE",         "HTTP_PURGE",        int64_t(http_method::HTTP_PURGE),       das::LineInfo());
        addIEx("MKCALENDAR",    "HTTP_MKCALENDAR",   int64_t(http_method::HTTP_MKCALENDAR),  das::LineInfo());
        addIEx("LINK",          "HTTP_LINK",         int64_t(http_method::HTTP_LINK),        das::LineInfo());
        addIEx("UNLINK",        "HTTP_UNLINK",       int64_t(http_method::HTTP_UNLINK),      das::LineInfo());
        addIEx("SOURCE",        "HTTP_SOURCE",       int64_t(http_method::HTTP_SOURCE),      das::LineInfo());

	}
};

class Enumeration_http_status : public das::Enumeration {
public:
    Enumeration_http_status() : das::Enumeration("http_status") {
        external = true;
        cppName = "http_status";
        baseType = (das::Type) das::ToBasicType< das::underlying_type< http_status >::type >::type;
        addIEx("CONTINUE",                          "CONTINUE",                         int64_t(http_status::HTTP_STATUS_CONTINUE), das::LineInfo());
        addIEx("SWITCHING_PROTOCOLS",               "SWITCHING_PROTOCOLS",              int64_t(http_status::HTTP_STATUS_SWITCHING_PROTOCOLS),  das::LineInfo());
        addIEx("PROCESSING",                        "PROCESSING",                       int64_t(http_status::HTTP_STATUS_PROCESSING),   das::LineInfo());
        addIEx("OK",                                "OK",                               int64_t(http_status::HTTP_STATUS_OK),   das::LineInfo());
        addIEx("CREATED",                           "CREATED",                          int64_t(http_status::HTTP_STATUS_CREATED),  das::LineInfo());
        addIEx("ACCEPTED",                          "ACCEPTED",                         int64_t(http_status::HTTP_STATUS_ACCEPTED), das::LineInfo());
        addIEx("NON_AUTHORITATIVE_INFORMATION",     "NON_AUTHORITATIVE_INFORMATION",    int64_t(http_status::HTTP_STATUS_NON_AUTHORITATIVE_INFORMATION),    das::LineInfo());
        addIEx("NO_CONTENT",                        "NO_CONTENT",                       int64_t(http_status::HTTP_STATUS_NO_CONTENT),   das::LineInfo());
        addIEx("RESET_CONTENT",                     "RESET_CONTENT",                    int64_t(http_status::HTTP_STATUS_RESET_CONTENT),    das::LineInfo());
        addIEx("PARTIAL_CONTENT",                   "PARTIAL_CONTENT",                  int64_t(http_status::HTTP_STATUS_PARTIAL_CONTENT),  das::LineInfo());
        addIEx("MULTI_STATUS",                      "MULTI_STATUS",                     int64_t(http_status::HTTP_STATUS_MULTI_STATUS), das::LineInfo());
        addIEx("ALREADY_REPORTED",                  "ALREADY_REPORTED",                 int64_t(http_status::HTTP_STATUS_ALREADY_REPORTED), das::LineInfo());
        addIEx("IM_USED",                           "IM_USED",                          int64_t(http_status::HTTP_STATUS_IM_USED),  das::LineInfo());
        addIEx("MULTIPLE_CHOICES",                  "MULTIPLE_CHOICES",                 int64_t(http_status::HTTP_STATUS_MULTIPLE_CHOICES), das::LineInfo());
        addIEx("MOVED_PERMANENTLY",                 "MOVED_PERMANENTLY",                int64_t(http_status::HTTP_STATUS_MOVED_PERMANENTLY),    das::LineInfo());
        addIEx("FOUND",                             "FOUND",                            int64_t(http_status::HTTP_STATUS_FOUND),    das::LineInfo());
        addIEx("SEE_OTHER",                         "SEE_OTHER",                        int64_t(http_status::HTTP_STATUS_SEE_OTHER),    das::LineInfo());
        addIEx("NOT_MODIFIED",                      "NOT_MODIFIED",                     int64_t(http_status::HTTP_STATUS_NOT_MODIFIED), das::LineInfo());
        addIEx("USE_PROXY",                         "USE_PROXY",                        int64_t(http_status::HTTP_STATUS_USE_PROXY),    das::LineInfo());
        addIEx("TEMPORARY_REDIRECT",                "TEMPORARY_REDIRECT",               int64_t(http_status::HTTP_STATUS_TEMPORARY_REDIRECT),   das::LineInfo());
        addIEx("PERMANENT_REDIRECT",                "PERMANENT_REDIRECT",               int64_t(http_status::HTTP_STATUS_PERMANENT_REDIRECT),   das::LineInfo());
        addIEx("BAD_REQUEST",                       "BAD_REQUEST",                      int64_t(http_status::HTTP_STATUS_BAD_REQUEST),  das::LineInfo());
        addIEx("UNAUTHORIZED",                      "UNAUTHORIZED",                     int64_t(http_status::HTTP_STATUS_UNAUTHORIZED), das::LineInfo());
        addIEx("PAYMENT_REQUIRED",                  "PAYMENT_REQUIRED",                 int64_t(http_status::HTTP_STATUS_PAYMENT_REQUIRED), das::LineInfo());
        addIEx("FORBIDDEN",                         "FORBIDDEN",                        int64_t(http_status::HTTP_STATUS_FORBIDDEN),    das::LineInfo());
        addIEx("NOT_FOUND",                         "NOT_FOUND",                        int64_t(http_status::HTTP_STATUS_NOT_FOUND),    das::LineInfo());
        addIEx("METHOD_NOT_ALLOWED",                "METHOD_NOT_ALLOWED",               int64_t(http_status::HTTP_STATUS_METHOD_NOT_ALLOWED),   das::LineInfo());
        addIEx("NOT_ACCEPTABLE",                    "NOT_ACCEPTABLE",                   int64_t(http_status::HTTP_STATUS_NOT_ACCEPTABLE),   das::LineInfo());
        addIEx("PROXY_AUTHENTICATION_REQUIRED",     "PROXY_AUTHENTICATION_REQUIRED",    int64_t(http_status::HTTP_STATUS_PROXY_AUTHENTICATION_REQUIRED),    das::LineInfo());
        addIEx("REQUEST_TIMEOUT",                   "REQUEST_TIMEOUT",                  int64_t(http_status::HTTP_STATUS_REQUEST_TIMEOUT),  das::LineInfo());
        addIEx("CONFLICT",                          "CONFLICT",                         int64_t(http_status::HTTP_STATUS_CONFLICT), das::LineInfo());
        addIEx("GONE",                              "GONE",                             int64_t(http_status::HTTP_STATUS_GONE), das::LineInfo());
        addIEx("LENGTH_REQUIRED",                   "LENGTH_REQUIRED",                  int64_t(http_status::HTTP_STATUS_LENGTH_REQUIRED),  das::LineInfo());
        addIEx("PRECONDITION_FAILED",               "PRECONDITION_FAILED",              int64_t(http_status::HTTP_STATUS_PRECONDITION_FAILED),  das::LineInfo());
        addIEx("PAYLOAD_TOO_LARGE",                 "PAYLOAD_TOO_LARGE",                int64_t(http_status::HTTP_STATUS_PAYLOAD_TOO_LARGE),    das::LineInfo());
        addIEx("URI_TOO_LONG",                      "URI_TOO_LONG",                     int64_t(http_status::HTTP_STATUS_URI_TOO_LONG), das::LineInfo());
        addIEx("UNSUPPORTED_MEDIA_TYPE",            "UNSUPPORTED_MEDIA_TYPE",           int64_t(http_status::HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE),   das::LineInfo());
        addIEx("RANGE_NOT_SATISFIABLE",             "RANGE_NOT_SATISFIABLE",            int64_t(http_status::HTTP_STATUS_RANGE_NOT_SATISFIABLE),    das::LineInfo());
        addIEx("EXPECTATION_FAILED",                "EXPECTATION_FAILED",               int64_t(http_status::HTTP_STATUS_EXPECTATION_FAILED),   das::LineInfo());
        addIEx("MISDIRECTED_REQUEST",               "MISDIRECTED_REQUEST",              int64_t(http_status::HTTP_STATUS_MISDIRECTED_REQUEST),  das::LineInfo());
        addIEx("UNPROCESSABLE_ENTITY",              "UNPROCESSABLE_ENTITY",             int64_t(http_status::HTTP_STATUS_UNPROCESSABLE_ENTITY), das::LineInfo());
        addIEx("LOCKED",                            "LOCKED",                           int64_t(http_status::HTTP_STATUS_LOCKED),   das::LineInfo());
        addIEx("FAILED_DEPENDENCY",                 "FAILED_DEPENDENCY",                int64_t(http_status::HTTP_STATUS_FAILED_DEPENDENCY),    das::LineInfo());
        addIEx("UPGRADE_REQUIRED",                  "UPGRADE_REQUIRED",                 int64_t(http_status::HTTP_STATUS_UPGRADE_REQUIRED), das::LineInfo());
        addIEx("PRECONDITION_REQUIRED",             "PRECONDITION_REQUIRED",            int64_t(http_status::HTTP_STATUS_PRECONDITION_REQUIRED),    das::LineInfo());
        addIEx("TOO_MANY_REQUESTS",                 "TOO_MANY_REQUESTS",                int64_t(http_status::HTTP_STATUS_TOO_MANY_REQUESTS),    das::LineInfo());
        addIEx("REQUEST_HEADER_FIELDS_TOO_LARGE",   "REQUEST_HEADER_FIELDS_TOO_LARGE",  int64_t(http_status::HTTP_STATUS_REQUEST_HEADER_FIELDS_TOO_LARGE),  das::LineInfo());
        addIEx("UNAVAILABLE_FOR_LEGAL_REASONS",     "UNAVAILABLE_FOR_LEGAL_REASONS",    int64_t(http_status::HTTP_STATUS_UNAVAILABLE_FOR_LEGAL_REASONS),    das::LineInfo());
        addIEx("INTERNAL_SERVER_ERROR",             "INTERNAL_SERVER_ERROR",            int64_t(http_status::HTTP_STATUS_INTERNAL_SERVER_ERROR),    das::LineInfo());
        addIEx("NOT_IMPLEMENTED",                   "NOT_IMPLEMENTED",                  int64_t(http_status::HTTP_STATUS_NOT_IMPLEMENTED),  das::LineInfo());
        addIEx("BAD_GATEWAY",                       "BAD_GATEWAY",                      int64_t(http_status::HTTP_STATUS_BAD_GATEWAY),  das::LineInfo());
        addIEx("SERVICE_UNAVAILABLE",               "SERVICE_UNAVAILABLE",              int64_t(http_status::HTTP_STATUS_SERVICE_UNAVAILABLE),  das::LineInfo());
        addIEx("GATEWAY_TIMEOUT",                   "GATEWAY_TIMEOUT",                  int64_t(http_status::HTTP_STATUS_GATEWAY_TIMEOUT),  das::LineInfo());
        addIEx("HTTP_VERSION_NOT_SUPPORTED",        "HTTP_VERSION_NOT_SUPPORTED",       int64_t(http_status::HTTP_STATUS_HTTP_VERSION_NOT_SUPPORTED),   das::LineInfo());
        addIEx("VARIANT_ALSO_NEGOTIATES",           "VARIANT_ALSO_NEGOTIATES",          int64_t(http_status::HTTP_STATUS_VARIANT_ALSO_NEGOTIATES),  das::LineInfo());
        addIEx("INSUFFICIENT_STORAGE",              "INSUFFICIENT_STORAGE",             int64_t(http_status::HTTP_STATUS_INSUFFICIENT_STORAGE), das::LineInfo());
        addIEx("LOOP_DETECTED",                     "LOOP_DETECTED",                    int64_t(http_status::HTTP_STATUS_LOOP_DETECTED),    das::LineInfo());
        addIEx("NOT_EXTENDED",                      "NOT_EXTENDED",                     int64_t(http_status::HTTP_STATUS_NOT_EXTENDED), das::LineInfo());
        addIEx("NETWORK_AUTHENTICATION_REQUIRED",   "NETWORK_AUTHENTICATION_REQUIRED",  int64_t(http_status::HTTP_STATUS_NETWORK_AUTHENTICATION_REQUIRED),  das::LineInfo());
	}
};

#include "dashv_gen.inc"

class WebSocketClient_Adapter : public hv::WebSocketClient, public HvWebSocketClient_Adapter {
public:
    WebSocketClient_Adapter ( char * pClass, const StructInfo * info, Context * ctx )
        : HvWebSocketClient_Adapter(info), classPtr(pClass), context(ctx) {
        onopen = [=]() {
            lock_guard<mutex> guard(lock);
            que.emplace_back([=](){
                onOpen();
            });
        };
        onclose = [=]() {
            lock_guard<mutex> guard(lock);
            que.emplace_back([=](){
                onClose();
            });
        };
        onmessage = [=]( const string & msg ) {
            lock_guard<mutex> guard(lock);
            que.emplace_back([=](){
                onMessage(msg);
            });
        };
    }
    void onOpen() {
        if ( auto fnOnOpen = get_onOpen(classPtr) ) {
            invoke_onOpen(context,fnOnOpen,classPtr);
        }
    }
    void onClose() {
        if ( auto fnOnClose = get_onClose(classPtr) ) {
            invoke_onClose(context,fnOnClose,classPtr);
        }
    }
    void onMessage ( const string & msg ) {
        if ( auto fnOnMessage = get_onMessage(classPtr) ) {
            invoke_onMessage(context,fnOnMessage,classPtr,(char *)msg.c_str());
        }
    }
    void tick() {
        vector<function<void()>> q;
        {
            lock_guard<mutex> guard(lock);
            swap(q, que);
        }
        for ( auto & ev : q ) ev();
    }
protected:
    void *      classPtr;
    Context *   context;
    mutex       lock;
    vector<function<void()>>    que;
};

struct WebSocketClientAnnotation : ManagedStructureAnnotation<hv::WebSocketClient> {
    WebSocketClientAnnotation(ModuleLibrary & ml)
        : ManagedStructureAnnotation ("WebSocketClient", ml, "hv::WebSocketClient") {
    }
};

hv::WebSocketClient * makeWebSocketClient ( const void * pClass, const StructInfo * info, Context * context ) {
    return new WebSocketClient_Adapter((char *)pClass,info,context);
}

int das_wsc_open ( hv::WebSocketClient & client, const char* url ) {
    return client.open(url);
}

int das_wsc_send ( hv::WebSocketClient & client, const char* msg ) {
    return client.send(msg);
}

int das_wsc_send_buf ( hv::WebSocketClient & client, const char* msg, int32_t len, ws_opcode opcode ) {
    return client.send(msg, len, opcode);
}

bool das_wsc_is_connected ( hv::WebSocketClient & client ) {
    return client.isConnected();
}

void das_wsc_tick ( hv::WebSocketClient & client ) {
    auto adapter = (WebSocketClient_Adapter *) &client;
    adapter->tick();
}

struct WebSocketServerAnnotation : ManagedStructureAnnotation<hv::WebSocketServer> {
    WebSocketServerAnnotation(ModuleLibrary & ml)
        : ManagedStructureAnnotation ("WebSocketServer", ml, "hv::WebSocketServer") {
    }
};

struct WebSocketChannelAnnotation : ManagedStructureAnnotation<hv::WebSocketChannel> {
    WebSocketChannelAnnotation(ModuleLibrary & ml)
        : ManagedStructureAnnotation ("WebSocketChannel", ml, "hv::WebSocketChannel") {
    }
};


struct HttpMessageAnnotation : ManagedStructureAnnotation<HttpMessage> {
    HttpMessageAnnotation(ModuleLibrary & ml)
        : ManagedStructureAnnotation ("HttpMessage", ml, "HttpMessage") {
    }
};

struct HttpRequestAnnotation : ManagedStructureAnnotation<HttpRequest> {
    HttpRequestAnnotation(ModuleLibrary & ml)
        : ManagedStructureAnnotation ("HttpRequest", ml, "HttpRequest") {
        addField<DAS_BIND_MANAGED_FIELD(method)>("method");
        addField<DAS_BIND_MANAGED_FIELD(url)>("url");
        addField<DAS_BIND_MANAGED_FIELD(scheme)>("scheme");
        addField<DAS_BIND_MANAGED_FIELD(host)>("host");
        addField<DAS_BIND_MANAGED_FIELD(port)>("port");
        addField<DAS_BIND_MANAGED_FIELD(path)>("path");
        addField<DAS_BIND_MANAGED_FIELD(timeout)>("timeout");
        addField<DAS_BIND_MANAGED_FIELD(body)>("body");
    }
};

struct HttpResponseAnnotation : ManagedStructureAnnotation<HttpResponse> {
    HttpResponseAnnotation(ModuleLibrary & ml)
        : ManagedStructureAnnotation ("HttpResponse", ml, "HttpResponse") {
        addField<DAS_BIND_MANAGED_FIELD(body)>("body");
        addField<DAS_BIND_MANAGED_FIELD(status_code)>("status_code");
        addField<DAS_BIND_MANAGED_FIELD(content)>("content");
        addProperty<DAS_BIND_MANAGED_PROP(IntContentLength)>("content_length", "IntContentLength");
        from("HttpMessage");
    }
};

struct HttpContextAnnotation : ManagedStructureAnnotation<hv::HttpContext> {
    HttpContextAnnotation(ModuleLibrary & ml)
        : ManagedStructureAnnotation ("HttpContext", ml, "hv::HttpContext") {
    }
};

class WebServer_Adapter : public hv::WebSocketServer, public HvWebServer_Adapter {
public:
    WebServer_Adapter ( char * pClass, const StructInfo * info, Context * ctx )
        : HvWebServer_Adapter(info), classPtr(pClass), context(ctx) {
        registerWebSocketService(&service);
        registerHttpService(&router);
        service.onopen = [=](const WebSocketChannelPtr& channel, const HttpRequestPtr& url) {
            lock_guard<mutex> guard(lock);
            que.emplace_back([=](){
                onWsOpen(channel,url);
            });
        };
        service.onclose = [=](const WebSocketChannelPtr& channel) {
            lock_guard<mutex> guard(lock);
            que.emplace_back([=](){
                onWsClose(channel);
            });
        };
        service.onmessage = [=](const WebSocketChannelPtr& channel, const std::string&msg) {
            lock_guard<mutex> guard(lock);
            que.emplace_back([=](){
                onWsMessage(channel,msg);
            });
        };
    }
    void onWsOpen ( const WebSocketChannelPtr& channel, const HttpRequestPtr& url) {
        lock_guard<mutex> guard(lock);
        if ( auto fnOnOpen = get_onWsOpen(classPtr) ) {
            invoke_onWsOpen(context,fnOnOpen,classPtr,channel.get(),(char *)url->url.c_str());
        }
    }
    void onWsClose ( const WebSocketChannelPtr& channel ) {
        lock_guard<mutex> guard(lock);
        if ( auto fnOnClose = get_onWsClose(classPtr) ) {
            invoke_onWsClose(context,fnOnClose,classPtr,channel.get());
        }
    }
    void onWsMessage (const WebSocketChannelPtr& channel, const std::string&msg) {
        lock_guard<mutex> guard(lock);
        if ( auto fnOnMessage = get_onWsMessage(classPtr) ) {
            invoke_onWsMessage(context,fnOnMessage,classPtr,channel.get(),(char *)msg.c_str());
        }
    }
    void tick() {
        vector<function<void()>> q;
        {
            lock_guard<mutex> guard(lock);
            swap(q, que);
        }
        for ( auto & ev : q ) ev();
        lock_guard<mutex> guard(lock);
        if ( auto fnOnTick = get_onTick(classPtr) ) {
            invoke_onTick(context,fnOnTick,classPtr);
        }
    }
    void GET ( const char * relative_path, Lambda lmb, Context * context, LineInfoArg * at ) {
        lock_guard<mutex> guard(lock);
        router.GET(relative_path,[=](HttpRequest * req,HttpResponse * resp){
            lock_guard<mutex> guard(lock);
            return das_invoke_lambda<int>::invoke<HttpRequest*,HttpResponse*>(context,at,lmb,req,resp);
        });
    }
    void POST ( const char * relative_path, Lambda lmb, Context * context, LineInfoArg * at ) {
        lock_guard<mutex> guard(lock);
        router.POST(relative_path,[=](HttpRequest * req,HttpResponse * resp){
            lock_guard<mutex> guard(lock);
            return das_invoke_lambda<int>::invoke<HttpRequest*,HttpResponse*>(context,at,lmb,req,resp);
        });
    }
protected:
    HttpService router;
    WebSocketService service;
    void *      classPtr;
    Context *   context;
    mutex       lock;
    vector<function<void()>>    que;
};

string getDasRoot ( void );

hv::WebSocketServer * makeWebSocketServer ( int port, int httpsPort, const char * pathToCert, const void * pClass, const StructInfo * info, Context * context, LineInfoArg * at ) {
    auto adapter = new WebServer_Adapter((char *)pClass,info,context);
    adapter->port = port;
    adapter->https_port = httpsPort;
    if ( httpsPort ) {
        hssl_ctx_init_param_t param;
        memset(&param, 0, sizeof(param));
        string crt_root = pathToCert ? pathToCert : getDasRoot() + "/modules/dasHV/libhv/cert";
        auto crt_file = crt_root + "/server.crt";
        auto key_file = crt_root + "/server.key";
        param.crt_file = crt_file.c_str();
        param.key_file = key_file.c_str();
        param.endpoint = HSSL_SERVER;
        if (hssl_ctx_init(&param) == NULL) {
            context->throw_error_at(at, "libHV: hssl_ctx_init failed! Please check the certificate files `%s` and `%s`.", crt_file.c_str(), key_file.c_str());
        }
    }
    return adapter;
}

int das_wss_send ( hv::WebSocketChannel * channel, const char * msg, ws_opcode opcode, bool fin ) {
    return channel->send(string(msg), opcode, fin);
}

int das_wss_send_buf ( hv::WebSocketChannel * channel, const char * buf, int32_t len, ws_opcode opcode, bool fin ) {
    return channel->send(buf, len, opcode, fin);
}

int das_wss_send_fragment ( hv::WebSocketChannel * channel, const char * buf, int32_t len, int32_t fragment, ws_opcode opcode ) {
    return channel->send(buf, len, fragment, opcode);
}

int das_wss_start ( hv::WebSocketServer * server ) {
    auto adapter = (WebServer_Adapter *) server;
    return adapter->start();
}

void das_wss_tick ( hv::WebSocketServer * server ) {
    auto adapter = (WebServer_Adapter *) server;
    adapter->tick();
}

int das_wss_stop ( hv::WebSocketServer * server ) {
    auto adapter = (WebServer_Adapter *) server;
    return adapter->stop();
}

void das_wss_get ( hv::WebSocketServer * server, const char * url, Lambda lmb, Context * context, LineInfoArg * at ) {
    auto adapter = (WebServer_Adapter *) server;
    adapter->GET(url, lmb, context, at);
}

void das_wss_post ( hv::WebSocketServer * server, const char * url, Lambda lmb, Context * context, LineInfoArg * at ) {
    auto adapter = (WebServer_Adapter *) server;
    adapter->POST(url, lmb, context, at);
}

int das_resp_string ( HttpResponse & resp, const char * msg ) {
    return resp.String(msg ? msg : "");
}

void das_httpr_set_header ( HttpRequest & req, const char * key, const char * value ) {
    req.SetHeader(key ? key : "", value ? value : value);
}

http_headers das_req_table_to_headers ( const TTable<char *,char *> & tab) {
    http_headers headers;
    char ** keys = (char **)tab.keys;
    char ** values = (char **)tab.data;
    auto * hashes = (TableHashKey *)tab.hashes;
    for ( uint32_t i=0; i!=tab.capacity; ++i ) {
        if ( hashes[i]!=HASH_EMPTY64 && hashes[i]!=HASH_KILLED64 ) {
            headers[keys[i]] = values[i];
        }
    }
    return headers;
}

void das_req_GET ( const char * url, const TBlock<void,HttpResponse*> & block, Context * context, LineInfoArg * at ) {
    auto resp = requests::get(url ? url : "");
    das_invoke<void>::invoke<HttpResponse*>(context,at,block,resp.get());
}

void das_req_GET_H ( const char * url, const TTable<char *,char *> & tab, const TBlock<void,HttpResponse*> & block, Context * context, LineInfoArg * at ) {
    auto headers = das_req_table_to_headers(tab);
    auto resp = requests::get(url ? url : "", headers);
    das_invoke<void>::invoke<HttpResponse*>(context,at,block,resp.get());
}

void das_req_POST ( const char * url, const char * text, const TBlock<void,HttpResponse*> & block, Context * context, LineInfoArg * at ) {
    auto resp = requests::post(url ? url : "", text ? text : "");
    das_invoke<void>::invoke<HttpResponse*>(context,at,block,resp.get());
}

void das_req_POST_H ( const char * url, const char * text, const TTable<char *,char *> & tab, const TBlock<void,HttpResponse*> & block, Context * context, LineInfoArg * at ) {
    auto headers = das_req_table_to_headers(tab);
    auto resp = requests::post(url ? url : "", text ? text : "",headers);
    das_invoke<void>::invoke<HttpResponse*>(context,at,block,resp.get());
}

void das_req_POST_HF ( const char * url, const char * text, const TTable<char *,char *> & tab, const TTable<char *,char *> & from,
        const TBlock<void,HttpResponse*> & block, Context * context, LineInfoArg * at ) {
    using namespace requests;
    Request req(new HttpRequest);
    req->method = HTTP_POST;
    req->url = url ? url : "";
    req->headers =das_req_table_to_headers(tab);
    req->body = text ? text : "";
    char ** keys = (char **)from.keys;
    char ** values = (char **)from.data;
    auto * hashes = (TableHashKey *)from.hashes;
    for ( uint32_t i=0; i!=from.capacity; ++i ) {
        if ( hashes[i]!=HASH_EMPTY64 && hashes[i]!=HASH_KILLED64 ) {
            hv::FormData data;
            auto value = values[i];
            if ( value != nullptr ) {
                if (*value == '@') {
                    data.filename = value+1;
                } else {
                    data.content = value;
                }
            }
            req->form[keys[i] ? keys[i] : ""] = data;
        }
    }
    auto resp = request(req);
    das_invoke<void>::invoke<HttpResponse*>(context,at,block,resp.get());
}

class Module_HV : public Module {
public:
    Module_HV() : Module("dashv") {
        ModuleLibrary lib;
        lib.addModule(this);
        lib.addBuiltInModule();
        lib.addModule(Module::require("rtti"));
        addEnumeration(make_smart<Enumeration_ws_opcode>());
        addEnumeration(make_smart<Enumeration_ws_session_type>());
        addEnumeration(make_smart<Enumeration_http_method>());
        addEnumeration(make_smart<Enumeration_http_status>());
        // client
        addAnnotation(make_smart<WebSocketClientAnnotation>(lib));
        addExtern<DAS_BIND_FUN(makeWebSocketClient)> (*this, lib, "make_web_socket_client",
            SideEffects::worstDefault, "makeWebSocketClient")
                ->args({"class","info","context"});
        addExtern<DAS_BIND_FUN(das_wsc_open)> (*this, lib, "open",
            SideEffects::worstDefault, "das_wsc_open")
                ->args({"self","url"});
        addExtern<DAS_BIND_FUN(das_wsc_send)> (*this, lib, "send",
            SideEffects::worstDefault, "das_wsc_send")
                ->args({"self","msg"});
        addExtern<DAS_BIND_FUN(das_wsc_send_buf)> (*this, lib, "send",
            SideEffects::worstDefault, "das_wsc_send_buf")
                ->args({"self","msg","len","opcode"});
        using hv_ws_close = DAS_CALL_MEMBER(hv::WebSocketClient::close);
        addExtern<DAS_CALL_METHOD(hv_ws_close)>(*this, lib, "close",
            SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(hv::WebSocketClient::close))
    	        ->args({"self"});
        addExtern<DAS_BIND_FUN(das_wsc_is_connected)>(*this, lib, "is_connected",
            SideEffects::worstDefault,"das_wsc_is_connected")
	            ->args({"self"});
        addExtern<DAS_BIND_FUN(das_wsc_tick)>(*this, lib, "tick",
            SideEffects::worstDefault,"das_tick")
	            ->args({"self"});
        // server
        addAnnotation(make_smart<WebSocketServerAnnotation>(lib));
        addAnnotation(make_smart<WebSocketChannelAnnotation>(lib));
        addAnnotation(make_smart<HttpRequestAnnotation>(lib));
        addAnnotation(make_smart<HttpMessageAnnotation>(lib));
        addAnnotation(make_smart<HttpResponseAnnotation>(lib));
        addAnnotation(make_smart<HttpContextAnnotation>(lib));
        addExtern<DAS_BIND_FUN(makeWebSocketServer)> (*this, lib, "make_web_socket_server",
            SideEffects::worstDefault, "makeWebSocketServer")
                ->args({"port","https_port","pathToCert","class","info","context","at"});
        addExtern<DAS_BIND_FUN(das_wss_send)> (*this, lib, "send",
            SideEffects::worstDefault, "das_wss_send")
                ->args({"channel","msg","opcode","fin"});
        addExtern<DAS_BIND_FUN(das_wss_send_buf)> (*this, lib, "send",
            SideEffects::worstDefault, "das_wss_send_buf")
                ->args({"channel","msg","len","opcode","fin"});
        addExtern<DAS_BIND_FUN(das_wss_send_fragment)> (*this, lib, "send",
            SideEffects::worstDefault, "das_wss_send_fragment")
                ->args({"channel","msg","len","fragment","opcode"});
        addExtern<DAS_BIND_FUN(das_wss_start)> (*this, lib, "start",
            SideEffects::worstDefault, "das_wss_start")
                ->args({"server"});
        addExtern<DAS_BIND_FUN(das_wss_tick)> (*this, lib, "tick",
            SideEffects::worstDefault, "das_wss_tick")
                ->args({"server"});
        addExtern<DAS_BIND_FUN(das_wss_stop)> (*this, lib, "stop",
            SideEffects::worstDefault, "das_wss_stop")
                ->args({"server"});
        addExtern<DAS_BIND_FUN(das_wss_get)> (*this, lib, "GET",
            SideEffects::worstDefault, "das_wss_get")
                ->args({"server","url","lambda","context","at"})->unsafeOperation = true;
        addExtern<DAS_BIND_FUN(das_wss_post)> (*this, lib, "POST",
            SideEffects::worstDefault, "das_wss_post")
                ->args({"server","url","lambda","context","at"})->unsafeOperation = true;
        // response
        addExtern<DAS_BIND_FUN(das_resp_string)> (*this, lib, "TEXT_PLAIN",
            SideEffects::worstDefault, "das_resp_string")
                ->args({"response","test"});
        // request
        addExtern<DAS_BIND_FUN(das_httpr_set_header)> (*this, lib, "set_header",
            SideEffects::worstDefault, "das_httpr_set_header")
                ->args({"request","key","value"});
        // requests
        addExtern<DAS_BIND_FUN(das_req_GET)> (*this, lib, "GET",
            SideEffects::worstDefault, "das_req_GET")
                ->args({"url","block","context","at"});
        addExtern<DAS_BIND_FUN(das_req_GET_H)> (*this, lib, "GET",
            SideEffects::worstDefault, "das_req_GET_H")
                ->args({"url","headers","block","context","at"});
        addExtern<DAS_BIND_FUN(das_req_POST)> (*this, lib, "POST",
            SideEffects::worstDefault, "das_req_POST")
                ->args({"url","text","block","context","at"});
        addExtern<DAS_BIND_FUN(das_req_POST_H)> (*this, lib, "POST",
            SideEffects::worstDefault, "das_req_POST_H")
                ->args({"url","text","headers","block","context","at"});
        addExtern<DAS_BIND_FUN(das_req_POST_HF)> (*this, lib, "POST",
            SideEffects::worstDefault, "das_req_POST_HF")
                ->args({"url","text","headers","from","block","context","at"});

    }
    virtual ModuleAotType aotRequire ( TextWriter & tw ) const override {
        tw << "#include \"../modules/dasHV/src/aot_hv.h\"\n";
        return ModuleAotType::cpp;
    }
};

}

REGISTER_MODULE_IN_NAMESPACE(Module_HV,das);

