options gen2
options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module dashv_boost shared public

require dashv public

require rtti
require daslib/ast_boost


class HvWebSocketClient {
    client : WebSocketClient?
    def init(url : string) : int {
        client = make_web_socket_client(unsafe(addr(self)), class_info(self))
        return open(*client, url)
    }
    def operator delete {
        if (client != null) {
            unsafe {
                delete client
            }
        }
    }
    def abstract onOpen : void
    def abstract onClose : void
    def abstract onMessage(msg : string#) : void
    def is_connected : bool {
        return is_connected(*client)
    }
    def process_event_que {
        tick(*client)
    }
    def send(text : string) {
        send(*client, text)
    }
}

class HvWebServer {
    server : WebSocketServer?
    def init(port : int) {
        server = make_web_socket_server(port, 0, "", unsafe(addr(self)), class_info(self))
        onInit()
    }
    def init_wss(port,httpsPort : int) {
        server = make_web_socket_server(port, httpsPort, "{get_das_root()}/modules/dasHV/dashv", unsafe(addr(self)), class_info(self))
        onInit()
    }
    def start : int {
        return start(server)
    }
    def stop : int {
        return stop(server)
    }
    def tick : void {
        tick(server)
    }
    def abstract onWsOpen(channel : WebSocketChannel?; url : string#) : void
    def abstract onWsClose(channel : WebSocketChannel?) : void
    def abstract onWsMessage(channel : WebSocketChannel?; msg : string#) : void
    def abstract onTick : void
    def onInit : void {}
    def GET(uri : string; lmb : lambda<(var req : HttpRequest; var resp : HttpResponse) : int>) : void {
        unsafe(GET(server, uri, lmb))
    }
    def POST(uri : string; lmb : lambda<(var req : HttpRequest; var resp : HttpResponse) : int>) : void {
        unsafe(POST(server, uri, lmb))
    }
}

def get_body_bytes(resp : HttpResponse?) : array<uint8> {
    var bytes : array<uint8>
    if (resp == null || resp.status_code != http_status.OK || resp.content_length == 0) {
        return <- bytes
    }
    bytes |> resize(resp.content_length)
    peek(resp.body) <| $(bodybytes) {
        unsafe {
            memcpy(addr(bytes[0]), reinterpret<void?> bodybytes, resp.content_length)
        }
    }
    return <- bytes
}