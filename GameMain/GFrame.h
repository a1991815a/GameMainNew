#ifndef __GFRAME__
#define __GFRAME__
#include <windows.h>
#include "GuiObject.h"
#include "Vec.h"

class GFrame: public Ref{
public:
	GFrame(
		GuiObjId id,
		float x, float y,
		float width, float height);
	~GFrame();

private:
	GuiObjId m_id;
	IDirect3DSwapChain9* m_d3SwapChain;
	Vec2 m_v2Position;
	Vec2 m_v2ContentSize;
};
#endif