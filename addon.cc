#include <node.h>

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Function;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "native banana"));
}

void MethodWithCallback(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Function> cb = Local<Function>::Cast(args[0]);
  const unsigned argc = 1;
  Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "have a banana") };
  cb->Call(Null(isolate), argc, argv);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "banana", Method);
  NODE_SET_METHOD(exports, "curiousBanana", MethodWithCallback);
}

NODE_MODULE(addon, init)

}