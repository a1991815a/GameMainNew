#include "RenderEngine.h"
#include "GMAssert.h"

RenderEngine::RenderEngine()
	:m_render(nullptr)
{

}

RenderEngine::~RenderEngine()
{

}

void RenderEngine::setRenderObject(RenderObject* object)
{
	m_render = object;
}

void RenderEngine::init(HWND hWnd)
{
	GMASSERT(m_render != nullptr);
	m_render->init(hWnd);
}

void RenderEngine::render()
{
	m_render->render();
}

void RenderEngine::destroy()
{
	m_render->destroy();
}
