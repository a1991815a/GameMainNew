#ifndef __RENDEROBJECT__
#define __RENDEROBJECT__
#include "windows.h"


class RenderObject{
public:
	enum RenderTypes{
		DIRECT3D,
		OPENGL
	};
public:
	RenderObject(RenderTypes rennder_type)
		:m_type(rennder_type)
	{}
	virtual ~RenderObject(){};
	virtual void render() = 0;
	virtual void init(HWND hWnd) = 0;
	virtual void destroy() = 0;

	
	inline RenderTypes getType() const{
		return m_type;
	};

private:
	RenderTypes m_type;
};
#endif