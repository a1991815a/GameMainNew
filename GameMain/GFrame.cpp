#include "GFrame.h"



GFrame::GFrame(
	GuiObjId id,
	float x, float y, 
	float width, float height)
	:m_d3SwapChain(nullptr), m_v2Position(x, y), m_v2ContentSize(width, height)
{
}

GFrame::~GFrame()
{

}
