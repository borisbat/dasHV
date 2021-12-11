#include "daScript/misc/platform.h"

#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/ast/ast_handle.h"

#include "../../../src/builtin/module_builtin_rtti.h"

#include "dasHV.h"

IMPLEMENT_EXTERNAL_TYPE_FACTORY(WebSocketClient,hv::WebSocketClient)
IMPLEMENT_EXTERNAL_TYPE_FACTORY(WebSocketServer,hv::WebSocketServer)
IMPLEMENT_EXTERNAL_TYPE_FACTORY(WebSocketChannel,hv::WebSocketChannel)

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


#include "dashv_gen.inc"

class WebSocketClient_Adapter : public hv::WebSocketClient, public HvWebSocketClient_Adapter {
public:
    WebSocketClient_Adapter ( char * pClass, const StructInfo * info, Context * ctx )
        : HvWebSocketClient_Adapter(info), classPtr(pClass), context(ctx) {
        onopen = [=]() {
            if ( auto fnOnOpen = get_onOpen(classPtr) ) {
                invoke_onOpen(context,fnOnOpen,classPtr);
            }
        };
        onclose = [=]() {
            if ( auto fnOnClose = get_onClose(classPtr) ) {
                invoke_onClose(context,fnOnClose,classPtr);
            }
        };
        onmessage = [=]( const string & msg ) {
            if ( auto fnOnMessage = get_onMessage(classPtr) ) {
                invoke_onMessage(context,fnOnMessage,classPtr,(char *)msg.c_str());
            }
        };
    }
protected:
    void *      classPtr;
    Context *   context;
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

class WebSocketServer_Adapter : public hv::WebSocketServer, public HvWebSocketServer_Adapter {
public:
    WebSocketServer_Adapter ( char * pClass, const StructInfo * info, Context * ctx )
        : HvWebSocketServer_Adapter(info), classPtr(pClass), context(ctx) {
        registerWebSocketService(&service);
        service.onopen = [=](const WebSocketChannelPtr& channel, const std::string& url) {
            lock_guard<mutex> guard(lock);
            if ( auto fnOnOpen = get_onOpen(classPtr) ) {
                invoke_onOpen(context,fnOnOpen,classPtr,channel.get(),(char *)url.c_str());
            }
        };
        service.onclose = [=](const WebSocketChannelPtr& channel) {
            lock_guard<mutex> guard(lock);
            if ( auto fnOnClose = get_onClose(classPtr) ) {
                invoke_onClose(context,fnOnClose,classPtr,channel.get());
            }
        };
        service.onmessage = [=](const WebSocketChannelPtr& channel, const std::string&msg) {
            lock_guard<mutex> guard(lock);
            if ( auto fnOnMessage = get_onMessage(classPtr) ) {
                invoke_onMessage(context,fnOnMessage,classPtr,channel.get(),(char *)msg.c_str());
            }
        };
    }
    void tick() {
        lock_guard<mutex> guard(lock);
        if ( auto fnOnTick = get_onTick(classPtr) ) {
            invoke_onTick(context,fnOnTick,classPtr);
        }
    }
protected:
    WebSocketService service;
    void *      classPtr;
    Context *   context;
    mutex       lock;
};

hv::WebSocketServer * makeWebSocketServer ( int port, const void * pClass, const StructInfo * info, Context * context ) {
    auto adapter = new WebSocketServer_Adapter((char *)pClass,info,context);
    adapter->port = port;
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

int das_wss_run ( hv::WebSocketServer * server ) {
    auto adapter = (WebSocketServer_Adapter *) server;
    adapter->start();
    for ( ;; ) {
        adapter->tick();
        hv_sleep(0);
    }
    adapter->stop();
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
        addExtern<DAS_CALL_METHOD(hv_ws_close)>(*this, lib, "close", SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(hv::WebSocketClient::close))
	        ->args({"self"});
        // server
        addAnnotation(make_smart<WebSocketServerAnnotation>(lib));
        addAnnotation(make_smart<WebSocketChannelAnnotation>(lib));
        addExtern<DAS_BIND_FUN(makeWebSocketServer)> (*this, lib, "make_web_socket_server",
            SideEffects::worstDefault, "makeWebSocketServer")
                ->args({"port","class","info","context"});
        addExtern<DAS_BIND_FUN(das_wss_send)> (*this, lib, "send",
            SideEffects::worstDefault, "das_wss_send")
                ->args({"channel","msg","opcode","fin"});
        addExtern<DAS_BIND_FUN(das_wss_send_buf)> (*this, lib, "send",
            SideEffects::worstDefault, "das_wss_send_buf")
                ->args({"channel","msg","len","opcode","fin"});
        addExtern<DAS_BIND_FUN(das_wss_send_fragment)> (*this, lib, "send",
            SideEffects::worstDefault, "das_wss_send_fragment")
                ->args({"channel","msg","len","fragment","opcode"});


        addExtern<DAS_BIND_FUN(das_wss_run)> (*this, lib, "run_server",
            SideEffects::worstDefault, "das_wss_run")
                ->args({"server"});
    }
    virtual ModuleAotType aotRequire ( TextWriter & tw ) const override {
        tw << "#include \"../modules/dasHV/src/aot_hv.h\"\n";
        return ModuleAotType::cpp;
    }
};

}

REGISTER_MODULE_IN_NAMESPACE(Module_HV,das);

