#ifndef __D3DXRENDERENGINE__
#define __D3DXRENDERENGINE__
#include "RenderObject.h"
#include <d3d9.h>
#include <d3dx9.h>

class D3DXRenderEngine: public RenderObject{
public:
	D3DXRenderEngine();
	virtual void render() override;

	virtual void init(HWND hWnd) override;

	virtual void destroy() override;
private:
	IDirect3D9* m_d3pp;
	IDirect3DDevice9* m_device;

//友元全局函数
public:
	friend IDirect3DDevice9* dxGetDevice();

};
#endif