#ifndef __MEMORYPOOLMANAGER__
#define __MEMORYPOOLMANAGER__
#include "SingleInstance.h"
#include "MemoryPool.h"

#define _memoryPoolManager				MemoryPoolManager::getInstance()

class MemoryPoolManager: public SingleInstance<MemoryPoolManager>{
	DEFINE_PRIVATE_INSTANCE(MemoryPoolManager);
public:
	void push(MemoryPool* pool);
	void pop();
	MemoryPool* getCurrentPool();
private:
	std::vector<MemoryPool*> m_poolList;
};
#endif