#include "GuiObject.h"
#include "GuiObjectManager.h"



GuiObject::GuiObject(GuiObjId id, GuiTypes type)
	: Node(NT_GUIOBJECT), m_iId(id), m_uiType(type)
{
	_guiObjectManager->insertGuiObject(id, this);
}

GuiObject::~GuiObject()
{
	_guiObjectManager->removeGuiObject(m_iId);
}
