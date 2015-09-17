#include "D3DXRenderEngine.h"
#include "GMAssert.h"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

D3DXRenderEngine::D3DXRenderEngine()
	:RenderObject(RenderObject::DIRECT3D), m_d3pp(nullptr), m_device(nullptr)
{

}

void D3DXRenderEngine::init(HWND hWnd)
{
	m_d3pp = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS parameters = { 0 };
	parameters.Windowed = TRUE;
	parameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	parameters.hDeviceWindow = hWnd;
	
	HRESULT result = D3D_OK;

	result = m_d3pp->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&parameters,
		&m_device
		);
	

	GMASSERT(result == D3D_OK);
}

void D3DXRenderEngine::destroy()
{
	if(m_device)
	{
		m_device->Release();
		m_device = nullptr;
	}
	if(m_d3pp)
	{
		m_d3pp->Release();
		m_d3pp = nullptr;
	}
}

void D3DXRenderEngine::render()
{
	m_device->Clear(0, nullptr, D3DCLEAR_TARGET, 0xFF000000, 1.0f, 0);
	m_device->BeginScene();

	m_device->EndScene();
	m_device->Present(0, 0, 0, 0);
}
