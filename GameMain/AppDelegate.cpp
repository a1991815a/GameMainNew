#include "AppDelegate.h"
#include "Director.h"
#include "TimerSystem.h"

AppDelegate::AppDelegate()
{
	
}

AppDelegate::~AppDelegate()
{

}

int AppDelegate::run()
{
	
	Director* director = Director::getInstance();
	director->setDesignStyle("ÎÒµÄ´°¿Ú", 800, 600, 60);
	director->init();
	
	return mainloop();
}

int AppDelegate::mainloop()
{
	Director* director = Director::getInstance();
	MSG msg = { 0 };
	_timerSystem->init();
	while (msg.message != WM_QUIT)
	{
		if (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageA(&msg);
		}
		else if (director->getDelta() >= director->getDelay())
		{
			director->mainloop();
			director->getLoopTimer().reset();
		}
		else
			Sleep(1);
		_timerSystem->refresh();
	}
	return msg.wParam;
}
