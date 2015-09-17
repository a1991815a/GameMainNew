#ifndef __QUADCOMMANDMANAGER__
#define __QUADCOMMANDMANAGER__
#include "GameMainHeader.h"
#include "SingleInstance.h"
#include "Vector.h"
#include "Node.h"

#define _quadCommandManager				QuadCommandManager::getInstance()

class QuadCommandManager: public SingleInstance<QuadCommandManager>{
	DEFINE_PRIVATE_INSTANCE(QuadCommandManager);
public:
	void init();
	void mainloop();

private:
	Vector<Node*> m_localNode;
	Vector<Node*> m_globalNode;
};
#endif