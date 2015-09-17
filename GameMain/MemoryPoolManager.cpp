#include "MemoryPoolManager.h"

MemoryPoolManager::MemoryPoolManager()
{
	m_poolList.reserve(10);
}

MemoryPoolManager::~MemoryPoolManager()
{
	delete m_poolList.front();
	m_poolList.clear();
}

void MemoryPoolManager::push(MemoryPool* pool)
{
	m_poolList.push_back(pool);
}

void MemoryPoolManager::pop()
{
	m_poolList.pop_back();
}

MemoryPool* MemoryPoolManager::getCurrentPool()
{
	return m_poolList.back();
}
