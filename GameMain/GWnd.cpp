#include "GWnd.h"
#include "MacroHeader.h"
#include "GWndManager.h"

GWnd::GWnd(
	GuiObjId id,
	float width, float height,
	const GString& caption, 
	GWnd* parent_wnd,
	DWORD style)
	:GuiObject(id, GT_GWND), m_hWnd(nullptr), m_gfFrame(nullptr),
	m_hParentWnd(parent_wnd),
	m_dwStyle(style)
{
	setCaption(caption);
	_gwndManager->pushWindow(this);
}

GWnd::~GWnd()
{
	SAFE_RELEASE(m_gfFrame);
	destroyWindow();
	_gwndManager->popWindow(this);
}

void GWnd::createWindow()
{
	GMASSERT(m_hWnd == nullptr);

	//窗口样式准备
	WindowStyleExA style = { 0 };
	
/*	memset(&style.wnd_class, 0, sizeof(style.wnd_class));*/
	style.wnd_class.cbSize = sizeof(style.wnd_class);
	style.wnd_class.hInstance = ::GetModuleHandleA(nullptr);
	style.wnd_class.lpfnWndProc = GWnd::WndProc;
	style.wnd_class.lpszMenuName = "GWnd";
	style.wnd_class.style = CS_HREDRAW | CS_VREDRAW;
	style.dwStyle = m_dwStyle;

	OnPrepareStyle(style);

	//注册
	::RegisterClassExA(&style.wnd_class);

	
	HWND parent_wnd = nullptr;
	if (m_hParentWnd)
		parent_wnd = m_hParentWnd->m_hWnd;

	//创建
	m_hWnd = ::CreateWindowExA(
		NULL,
		"GWnd",
		getCaption().c_str(),
		style.dwStyle,
		getPosition().x, getPosition().y,
		getContentSize().width, getContentSize().height,
		parent_wnd,
		style.hMenu,
		::GetModuleHandleA(nullptr),
		nullptr
		);
	::UnregisterClassA("GWnd", ::GetModuleHandleA(nullptr));

	SetWindowLongA(m_hWnd, GWL_USERDATA, (long)this);
}

void GWnd::destroyWindow()
{
	if (m_hWnd) {
		::DestroyWindow(m_hWnd);
		::CloseHandle(m_hWnd);
		m_hWnd = nullptr;
	}
}

void GWnd::showWindow(int sw /* =SW_SHOWNORMAL*/)
{
	::ShowWindow(m_hWnd, sw);
	updateWindow();
}

void GWnd::updateWindow()
{
	::UpdateWindow(m_hWnd);
}

void GWnd::setParentWindow(GWnd* parent)
{
	SAFE_RELEASE(m_hParentWnd);
	m_hParentWnd = parent;
	SAFE_RETAIN(m_hParentWnd);
	if (m_hParentWnd)
	{
		::SetParent(m_hWnd, m_hParentWnd->m_hWnd);
		showWindow();
	}
}

void GWnd::setFrame(GFrame* frame)
{
	GMASSERT(m_gfFrame == nullptr);
	m_gfFrame = frame;
	SAFE_RETAIN(m_gfFrame);
}

HWND GWnd::getWin32Window() const
{
	return m_hWnd;
}

GWnd* GWnd::getParentWnd()
{
	return m_hParentWnd;
}

const GWnd* GWnd::getParentWnd() const
{
	return m_hParentWnd;
}

LRESULT GWnd::OnEvent(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		this->OnCreate(m_hWnd);
		break;
	case WM_DESTROY:
		this->OnDestroy(m_hWnd);
		break;
	case WM_CHAR:
		this->OnChar(wParam);
		break;
	case WM_KEYDOWN:

		break;
	default:
		break;
	}

	return 0;
}

LRESULT CALLBACK GWnd::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	GWnd* wnd = nullptr;

	wnd = (GWnd*)GetWindowLongA(hwnd, GWL_USERDATA);
	if(wnd == nullptr)
		return ::DefWindowProcA(hwnd, message, wParam, lParam);
	
	return wnd->OnEvent(message, wParam, lParam);
}
