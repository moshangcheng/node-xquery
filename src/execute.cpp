#include <node.h>
#include "zorba/zorba.h"
#include "execute.h"
#include <string>
#include <sstream>
using namespace v8;

static void* gpStore = NULL;
static zorba::Zorba* gpZorba = NULL;
static zorba::StaticContext_t gStaticContext;

class A {
public:
	~A() {
		gStaticContext = NULL;
		gpZorba->shutdown();
		zorba::StoreManager::shutdownStore(gpStore);
	}
};

static A a;

void InitZorba() {
    if (gpStore==NULL) {
        gpStore = zorba::StoreManager::getStore();
    }
    
    if(gpZorba==NULL) {
        gpZorba = zorba::Zorba::getInstance(gpStore);
    }
	if(gStaticContext.isNull()) {
		gStaticContext = gpZorba->createStaticContext();
	}
}

Handle<Value> Execute(const Arguments& args) {
    HandleScope scope;

	InitZorba();

    v8::String::Utf8Value lParam1(args[0]->ToString());
    std::string lQueryStr(*lParam1);
	std::string resultStr;

	{		
		std::ostringstream lOutputStream;
		try {
			zorba::XQuery_t lQuery = gpZorba->compileQuery(lQueryStr);
			lQuery->execute(lOutputStream);
		} catch(zorba::ZorbaException e) {
			ThrowException(Exception::Error(String::New(e.what())));
		}
		resultStr = lOutputStream.str().c_str();
	}
	return scope.Close(String::New(resultStr.c_str()));
}


