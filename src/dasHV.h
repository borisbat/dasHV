#pragma once

#include "aot_hv.h"

#include "daScript/simulate/bind_enum.h"

MAKE_EXTERNAL_TYPE_FACTORY(WebSocketClient,hv::WebSocketClient)
MAKE_EXTERNAL_TYPE_FACTORY(WebSocketServer,hv::WebSocketServer)
MAKE_EXTERNAL_TYPE_FACTORY(WebSocketChannel,hv::WebSocketChannel)
MAKE_EXTERNAL_TYPE_FACTORY(HttpMessage,HttpMessage)
MAKE_EXTERNAL_TYPE_FACTORY(HttpRequest,HttpRequest)
MAKE_EXTERNAL_TYPE_FACTORY(HttpResponse,HttpResponse)
MAKE_EXTERNAL_TYPE_FACTORY(HttpContext,hv::HttpContext)

DAS_BIND_ENUM_CAST(ws_opcode)
DAS_BASE_BIND_ENUM_GEN(ws_opcode,ws_opcode)

DAS_BIND_ENUM_CAST(ws_session_type)
DAS_BASE_BIND_ENUM_GEN(ws_session_type,ws_session_type)

DAS_BIND_ENUM_CAST(http_method)
DAS_BASE_BIND_ENUM_GEN(http_method,http_method)

DAS_BIND_ENUM_CAST(http_status)
DAS_BASE_BIND_ENUM_GEN(http_status,http_status)

namespace das {

hv::WebSocketClient * makeWebSocketClient ( const void * pClass, const StructInfo * info, Context * context );
int das_wsc_open ( hv::WebSocketClient & client, const char* url );
int das_wsc_send ( hv::WebSocketClient & client, const char* msg );
int das_wsc_send_buf ( hv::WebSocketClient & client, const char* msg, int32_t len, ws_opcode opcode );
bool das_wsc_is_connected ( hv::WebSocketClient & client );
void das_wsc_tick ( hv::WebSocketClient & client );

hv::WebSocketServer * makeWebSocketServer ( int port, int httpsPort, const char * pathToCert, const void * pClass, const StructInfo * info, Context * context, LineInfoArg * at );
int das_wss_send ( hv::WebSocketChannel * channel, const char * msg, ws_opcode opcode, bool fin );
int das_wss_send_buf ( hv::WebSocketChannel * channel, const char * buf, int32_t len, ws_opcode opcode, bool fin );
int das_wss_send_fragment ( hv::WebSocketChannel * channel, const char * buf, int32_t len, int32_t fragment, ws_opcode opcode );
int das_wss_start ( hv::WebSocketServer * server );
void das_wss_tick ( hv::WebSocketServer * server );
int das_wss_stop ( hv::WebSocketServer * server );
void das_wss_get ( hv::WebSocketServer * server, const char * url, Lambda lmb, Context * context, LineInfoArg * at );
void das_wss_post ( hv::WebSocketServer * server, const char * url, Lambda lmb, Context * context, LineInfoArg * at );

int das_resp_string ( HttpResponse & resp, const char * msg );

void das_httpr_set_header ( HttpRequest & req, const char * key, const char * value );

http_headers das_req_table_to_headers ( const TTable<char *,char *> & tab );
void das_req_GET ( const char * url, const TBlock<void,HttpResponse*> & block, Context * context, LineInfoArg * at );
void das_req_GET_H ( const char * url, const TTable<char *,char *> & tab, const TBlock<void,HttpResponse*> & block, Context * context, LineInfoArg * at );
void das_req_POST ( const char * url, const char * text, const TBlock<void,HttpResponse*> & block, Context * context, LineInfoArg * at );
void das_req_POST_H ( const char * url, const char * text, const TTable<char *,char *> & tab, const TBlock<void,HttpResponse*> & block, Context * context, LineInfoArg * at );
void das_req_POST_HF ( const char * url, const char * text, const TTable<char *,char *> & tab, const TTable<char *,char *> & from, const TBlock<void,HttpResponse*> & block, Context * context, LineInfoArg * at );

}
