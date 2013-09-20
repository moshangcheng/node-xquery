#include <node.h>
#include "zorba/zorba.h"
#include "execute.h"
using namespace v8;

zorba::Zorba* GetZorbaInstance() {
    static void* store = NULL;
    if (store==NULL) {
        store = zorba::StoreManager::getStore();
    }
    static zorba::Zorba* lZorbaInstance = NULL;
    if(lZorbaInstance==NULL) {
        lZorbaInstance = zorba::Zorba::getInstance(store);
    }
    return lZorbaInstance;
}

Handle<Value> Execute(const Arguments& args) {
    HandleScope scope;
    zorba::XQuery_t lQuery = GetZorbaInstance()->createQuery();

    v8::String::Utf8Value lParam1(args[0]->ToString());
    std::ostringstream lOutputStream;
    std::string lQueryStr(*lParam1);
    try {
        lQuery->compile(lQueryStr);
        lQuery->execute(lOutputStream);
    } catch(zorba::ZorbaException e) {
        ThrowException(Exception::Error(String::New(e.what())));
    }
    return scope.Close(String::New(lOutputStream.str().c_str()));
}


