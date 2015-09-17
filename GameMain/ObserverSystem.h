#ifndef __OBSERVERSYSTEM__
#define __OBSERVERSYSTEM__
#include "GameMainHeader.h"
#include "SingleInstance.h"

#define _observerSystem			ObserverSystem::getInstance()

class ObserverSystem: public SingleInstance<ObserverSystem>{
	DEFINE_PRIVATE_INSTANCE(ObserverSystem);
public:
	void init();
private:
	
};
#endif