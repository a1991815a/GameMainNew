#ifndef __ACTIONSYSTEM__
#define __ACTIONSYSTEM__
#include "GameMainHeader.h"
#include "SingleInstance.h"

#define _actionSystem			ActionSystem::getInstance()

class ActionSystem: public SingleInstance<ActionSystem>{
	DEFINE_PRIVATE_INSTANCE(ActionSystem);
public:
	void init();
	void mainloop();

private:
	
};
#endif