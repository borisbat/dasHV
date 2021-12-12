options persistent_heap
options gc

require dashv/dashv_boost

require fio

class ExampleWebServer : HvWebServer
    channels:table<WebSocketChannel?;string>
    ptime:clock
    def ExampleWebSocketServer
        ptime = get_clock()
    def override onInit
        GET("/ping") <| @ ( var req:HttpRequest; var resp:HttpResponse ) : int
            print("ping\n")
            return resp |> TEXT_PLAIN("pong")
        POST("/echo") <| @ ( var req:HttpRequest; var resp:HttpResponse ) : int
            print("echo\n")
            return resp |> TEXT_PLAIN(string(req.body))
    def override onWsOpen ( channel:WebSocketChannel?; url:string# ) : void
        print("onWsOpen: {intptr(channel)}, {url}\n")
        channels[channel] := url
    def override onWsClose ( channel:WebSocketChannel? ): void
        print("onWsClose: {intptr(channel)}\n")
        erase(channels, channel)
    def override onWsMessage ( channel:WebSocketChannel?; msg:string# ) : void
        print("onWsMessage: {intptr(channel)}, {msg}\n")
    def override onTick : void
        let ntime = get_clock()
        if ntime-ptime > 1.
            ptime = ntime
            for ch in keys(channels)
                send(ch, "tick at {ptime}", ws_opcode WS_OPCODE_TEXT, true)

[export]
def main()
    print("server on port 9999\n")
    var wss = new ExampleWebServer()
    wss->init(9999)
    wss->start()
    while true
        wss->tick()
        sleep(0u)
    wss->stop()
    unsafe
        delete wss
