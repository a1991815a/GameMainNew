#ifndef __UIDATASTRUCT__
#define __UIDATASTRUCT__
#include <windows.h>

struct WindowStyleExA {
	WNDCLASSEXA		wnd_class;
	DWORD			dwExStyle;
	DWORD			dwStyle;
	HMENU			hMenu;
};

#endif