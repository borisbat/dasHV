options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module dashv_boost shared public

require dashv public

require rtti

class HvWebSocketClient
    client:WebSocketClient?
    def init(url:string) : int
        client = make_web_socket_client(unsafe(addr(self)), class_info(self))
        return open(*client, url)
    def operator delete
        if client != null
            unsafe
                delete client
    def abstract onOpen : void
    def abstract onClose : void
    def abstract onMessage ( msg:string# ) : void
    def is_connected : bool
        return is_connected(*client)
    def process_event_que
        process_event_que(*client)
    def send(text:string)
        send(*client,text)

class HvWebSocketServer
    server:WebSocketServer?
    def init(port:int)
        server = make_web_socket_server(port, unsafe(addr(self)), class_info(self))
    def run : int
        return run_server(server)
    def abstract onOpen ( channel:WebSocketChannel?; url:string# ): void
    def abstract onClose ( channel:WebSocketChannel? ): void
    def abstract onMessage ( channel:WebSocketChannel?; msg:string# ) : void
    def abstract onTick : void

