#include <node.h>

using namespace v8;


Handle<Value> 

void Init(Handle<Object> exports, Handle<Object> module) {
    module->Set(String::NewSymbol("exports"),
        FunctionTemplate::New(RunCallback)->GetFunction());
}

NODE_MODULE(zorba, Init)

