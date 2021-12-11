class HvWebSocketClient_Adapter {
protected:
  enum {
    __fn_init = 0,
    __fn_onOpen = 1,
    __fn_onClose = 2,
    __fn_onMessage = 3,
  };
protected:
  int _das_class_method_offset[4];
public:
  HvWebSocketClient_Adapter ( const StructInfo * info ) {
      _das_class_method_offset[__fn_init] = adapt_field_offset("init",info);
      _das_class_method_offset[__fn_onOpen] = adapt_field_offset("onOpen",info);
      _das_class_method_offset[__fn_onClose] = adapt_field_offset("onClose",info);
      _das_class_method_offset[__fn_onMessage] = adapt_field_offset("onMessage",info);
  }
  __forceinline Func get_init ( void * self ) const {
    return getDasClassMethod(self,_das_class_method_offset[__fn_init]);
  }
  __forceinline void invoke_init ( Context * __context__, Func __funcCall__, void * self ) const {
    das_invoke_function<void>::invoke
      <void *>
        (__context__,nullptr,__funcCall__,
          self);
  }
  __forceinline Func get_onOpen ( void * self ) const {
    return getDasClassMethod(self,_das_class_method_offset[__fn_onOpen]);
  }
  __forceinline void invoke_onOpen ( Context * __context__, Func __funcCall__, void * self ) const {
    das_invoke_function<void>::invoke
      <void *>
        (__context__,nullptr,__funcCall__,
          self);
  }
  __forceinline Func get_onClose ( void * self ) const {
    return getDasClassMethod(self,_das_class_method_offset[__fn_onClose]);
  }
  __forceinline void invoke_onClose ( Context * __context__, Func __funcCall__, void * self ) const {
    das_invoke_function<void>::invoke
      <void *>
        (__context__,nullptr,__funcCall__,
          self);
  }
  __forceinline Func get_onMessage ( void * self ) const {
    return getDasClassMethod(self,_das_class_method_offset[__fn_onMessage]);
  }
  __forceinline void invoke_onMessage ( Context * __context__, Func __funcCall__, void * self, char * const  msg ) const {
    das_invoke_function<void>::invoke
      <void *,char * const >
        (__context__,nullptr,__funcCall__,
          self,msg);
  }
};

class HvWebSocketServer_Adapter {
protected:
  enum {
    __fn_init = 0,
    __fn_run = 1,
    __fn_onOpen = 2,
    __fn_onClose = 3,
    __fn_onMessage = 4,
    __fn_onTick = 5,
  };
protected:
  int _das_class_method_offset[6];
public:
  HvWebSocketServer_Adapter ( const StructInfo * info ) {
      _das_class_method_offset[__fn_init] = adapt_field_offset("init",info);
      _das_class_method_offset[__fn_run] = adapt_field_offset("run",info);
      _das_class_method_offset[__fn_onOpen] = adapt_field_offset("onOpen",info);
      _das_class_method_offset[__fn_onClose] = adapt_field_offset("onClose",info);
      _das_class_method_offset[__fn_onMessage] = adapt_field_offset("onMessage",info);
      _das_class_method_offset[__fn_onTick] = adapt_field_offset("onTick",info);
  }
  __forceinline Func get_init ( void * self ) const {
    return getDasClassMethod(self,_das_class_method_offset[__fn_init]);
  }
  __forceinline void invoke_init ( Context * __context__, Func __funcCall__, void * self, int32_t port ) const {
    das_invoke_function<void>::invoke
      <void *,int32_t>
        (__context__,nullptr,__funcCall__,
          self,port);
  }
  __forceinline Func get_run ( void * self ) const {
    return getDasClassMethod(self,_das_class_method_offset[__fn_run]);
  }
  __forceinline int32_t invoke_run ( Context * __context__, Func __funcCall__, void * self, bool wait ) const {
    return das_invoke_function<int32_t>::invoke
      <void *,bool>
        (__context__,nullptr,__funcCall__,
          self,wait);
  }
  __forceinline Func get_onOpen ( void * self ) const {
    return getDasClassMethod(self,_das_class_method_offset[__fn_onOpen]);
  }
  __forceinline void invoke_onOpen ( Context * __context__, Func __funcCall__, void * self, hv::WebSocketChannel * const  channel, char * const  url ) const {
    das_invoke_function<void>::invoke
      <void *,hv::WebSocketChannel * const ,char * const >
        (__context__,nullptr,__funcCall__,
          self,channel,url);
  }
  __forceinline Func get_onClose ( void * self ) const {
    return getDasClassMethod(self,_das_class_method_offset[__fn_onClose]);
  }
  __forceinline void invoke_onClose ( Context * __context__, Func __funcCall__, void * self, hv::WebSocketChannel * const  channel ) const {
    das_invoke_function<void>::invoke
      <void *,hv::WebSocketChannel * const >
        (__context__,nullptr,__funcCall__,
          self,channel);
  }
  __forceinline Func get_onMessage ( void * self ) const {
    return getDasClassMethod(self,_das_class_method_offset[__fn_onMessage]);
  }
  __forceinline void invoke_onMessage ( Context * __context__, Func __funcCall__, void * self, hv::WebSocketChannel * const  channel, char * const  msg ) const {
    das_invoke_function<void>::invoke
      <void *,hv::WebSocketChannel * const ,char * const >
        (__context__,nullptr,__funcCall__,
          self,channel,msg);
  }
  __forceinline Func get_onTick ( void * self ) const {
    return getDasClassMethod(self,_das_class_method_offset[__fn_onTick]);
  }
  __forceinline void invoke_onTick ( Context * __context__, Func __funcCall__, void * self ) const {
    das_invoke_function<void>::invoke
      <void *>
        (__context__,nullptr,__funcCall__,
          self);
  }
};

