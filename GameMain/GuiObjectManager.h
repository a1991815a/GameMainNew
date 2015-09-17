#ifndef __GUIOBJECTMANAGER__
#define __GUIOBJECTMANAGER__
#include "SingleInstance.h"
#include "Map.h"
#include "GuiObject.h"

#define _guiObjectManager			GuiObjectManager::getInstance()

class GuiObjectManager: public SingleInstance<GuiObjectManager>{
	DEFINE_PRIVATE_INSTANCE(GuiObjectManager);
public:
	void insertGuiObject(GuiObjId id, GuiObject* obj);
	void removeGuiObject(GuiObjId id);
	GuiObject* getGuiObject(GuiObjId id) { return m_GuiIdMap.at(id); };
	const GuiObject* getGuiObject(GuiObjId id) const { return m_GuiIdMap.at(id); };

private:
	Map<GuiObjId, GuiObject*> m_GuiIdMap;
};
#endif