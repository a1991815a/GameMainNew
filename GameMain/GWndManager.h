#ifndef __GWNDMANAGER__
#define __GWNDMANAGER__
#include "SingleInstance.h"
#include "GWnd.h"
#include <unordered_set>

#define _gwndManager				GWndManager::getInstance()

class GWndManager: public SingleInstance<GWndManager>{
	DEFINE_PRIVATE_INSTANCE(GWndManager);
public:
	void pushWindow(GWnd* wnd);
	void popWindow(GWnd* wnd);
private:
	std::unordered_set<GWnd*> m_wndList;
};
#endif