#ifndef __GUIOBJECT__
#define __GUIOBJECT__
#include "Node.h"
#include <windows.h>
#include "UIDataStruct.h"

#define gm_msg				virtual

typedef unsigned int GuiObjId;

enum GuiTypes : unsigned int
{
	GT_GWND,
	GT_GFRAME,
	GT_GICON,
	GT_GEDITOR_BOX,
	GT_GGROUP_BOX,
	GT_GPROCESS_CONTROL,
	GT_GSCROLL_CONTROL,
	GT_GSLIDE_CONTROL,
	GT_GSTATIC_TEXT
};


class GuiObject: public Node{
public:
	GuiObject(GuiObjId id, GuiTypes type);
	~GuiObject();

	inline bool getFocus() const { return m_focus; }
	inline void setFocus(bool val) { m_focus = val; }
	inline const GString& getCaption() const { return m_gsCaption; }
	inline void setCaption(const GString& val) { m_gsCaption = val; }

	inline GuiObjId getId() const { return m_iId; }
	inline void setId(GuiObjId val) { m_iId = val; }

	GuiTypes getGuiType() const { return m_uiType; };
private:
	bool m_focus;
	GuiObjId m_iId;
	GString m_gsCaption;
	GuiTypes m_uiType;
};
#endif