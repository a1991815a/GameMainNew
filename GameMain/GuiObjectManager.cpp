#include "GuiObjectManager.h"
#include "GMAssert.h"



GuiObjectManager::GuiObjectManager()
{

}

GuiObjectManager::~GuiObjectManager()
{

}

void GuiObjectManager::insertGuiObject(GuiObjId id, GuiObject* obj)
{
	GMASSERT(m_GuiIdMap.find(id) != m_GuiIdMap.end());
	m_GuiIdMap.insert(id, obj);
}

void GuiObjectManager::removeGuiObject(GuiObjId id)
{
	m_GuiIdMap.erase(id);
}
