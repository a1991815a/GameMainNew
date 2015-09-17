#include "GWndManager.h"

GWndManager::GWndManager()
{
	
}

GWndManager::~GWndManager()
{

}

void GWndManager::pushWindow(GWnd* wnd)
{
	m_wndList.insert(wnd);
}

void GWndManager::popWindow(GWnd* wnd)
{
	m_wndList.erase(wnd);
}
