#include <node.h>
#include "execute.h"

using namespace v8;

void Init(Handle<Object> exports, Handle<Object> module) {
    exports->Set(String::NewSymbol("execute"),
        FunctionTemplate::New(Execute)->GetFunction());
}

NODE_MODULE(zorba, Init)

