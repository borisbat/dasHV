options persistent_heap
options gc

require dashv/dashv_boost

require fio

class ExampleWebSocketServer : HvWebSocketServer
    channels:table<WebSocketChannel?;string>
    ptime:clock
    def ExampleWebSocketServer
        ptime = get_clock()
    def override onOpen ( channel:WebSocketChannel?; url:string# ) : void
        print("onOpen: {intptr(channel)}, {url}\n")
        channels[channel] := url
    def override onClose ( channel:WebSocketChannel? ): void
        print("onClose: {intptr(channel)}\n")
        erase(channels, channel)
    def override onMessage ( channel:WebSocketChannel?; msg:string# ) : void
        print("onMessage: {intptr(channel)}, {msg}\n")
    def override onTick : void
        let ntime = get_clock()
        if ntime-ptime > 1.
            ptime = ntime
            for ch in keys(channels)
                send(ch, "tick at {ptime}", ws_opcode WS_OPCODE_TEXT, true)

[export]
def main()
    var wss = new ExampleWebSocketServer()
    wss->init(9999)
    wss->start()
    while true
        wss->tick()
        sleep(0u)
    wss->stop()
    unsafe
        delete wss
