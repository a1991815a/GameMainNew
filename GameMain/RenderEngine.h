#ifndef __RENDERENGINE__
#define __RENDERENGINE__
#include "SingleInstance.h"
#include "RenderObject.h"

class RenderEngine: public SingleInstance<RenderEngine>{
	DEFINE_PRIVATE_INSTANCE(RenderEngine);
public:
	void setRenderObject(RenderObject* object);
	void init(HWND hWnd);
	void render();
	void destroy();

private:
	RenderObject* m_render;
};
#endif