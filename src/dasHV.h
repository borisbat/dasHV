#pragma once

#include "aot_hv.h"

#include "daScript/simulate/bind_enum.h"

MAKE_EXTERNAL_TYPE_FACTORY(WebSocketClient,hv::WebSocketClient)
MAKE_EXTERNAL_TYPE_FACTORY(WebSocketServer,hv::WebSocketServer)
MAKE_EXTERNAL_TYPE_FACTORY(WebSocketChannel,hv::WebSocketChannel)

DAS_BIND_ENUM_CAST(ws_opcode)
DAS_BASE_BIND_ENUM_GEN(ws_opcode,ws_opcode)

DAS_BIND_ENUM_CAST(ws_session_type)
DAS_BASE_BIND_ENUM_GEN(ws_session_type,ws_session_type)


namespace das {

hv::WebSocketClient * makeWebSocketClient ( const void * pClass, const StructInfo * info, Context * context );
int das_wsc_open ( hv::WebSocketClient & client, const char* url );
int das_wsc_send ( hv::WebSocketClient & client, const char* msg );
int das_wsc_send_buf ( hv::WebSocketClient & client, const char* msg, int32_t len, ws_opcode opcode );
bool das_wsc_is_connected ( hv::WebSocketClient & client );
void das_wsc_tick ( hv::WebSocketClient & client );

hv::WebSocketServer * makeWebSocketServer ( int port, const void * pClass, const StructInfo * info, Context * context );
int das_wss_send ( hv::WebSocketChannel * channel, const char * msg, ws_opcode opcode, bool fin );
int das_wss_send_buf ( hv::WebSocketChannel * channel, const char * buf, int32_t len, ws_opcode opcode, bool fin );
int das_wss_send_fragment ( hv::WebSocketChannel * channel, const char * buf, int32_t len, int32_t fragment, ws_opcode opcode );
int das_wss_start ( hv::WebSocketServer * server );
void das_wss_tick ( hv::WebSocketServer * server );
int das_wss_stop ( hv::WebSocketServer * server );

}
