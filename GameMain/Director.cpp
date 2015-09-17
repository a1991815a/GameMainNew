#include "Director.h"
#include "Win32Utils.h"
#include "MainloopModule.h"
#include "IndependentModule.h"
#include "D3DXRenderEngine.h"

Director::Director()
{

}

Director::~Director()
{

}

void Director::init()
{
	HWND hwnd = Win32Utils::getInstance()->createWindow(
		m_windowName.c_str(),
		(int)m_size.width, 
		(int)m_size.height);

	RenderEngine::getInstance()->setRenderObject(new D3DXRenderEngine());
	RenderEngine::getInstance()->init(hwnd);


	/*
	游戏主循环模块初始化
	********************/
	_messageDispatcher->init();
	_schedulerSystem->init();
	_actionSystem->init();
	_memoryPoolSystem->init();
	
	/********************/
	
	/*
	游戏独立模块初始化
	*********************/
	_animationCache->init();
	_spriteFrameCache->init();
	_textureCache->init();
	_observerSystem->init();
	_coordSystem->init();
	/********************/

}

void Director::mainloop()
{
	_messageDispatcher->mainloop();
	_schedulerSystem->mainloop();
	_actionSystem->mainloop();
	RenderEngine::getInstance()->render();
	_memoryPoolSystem->getCurrentPool()->clear();
}

void Director::destroy()
{
	RenderEngine::getInstance()->destroy();
}

const Size& Director::getWindowSize() const
{
	return m_size;
}

void Director::setDesignStyle(
	const GString& window_text,
	float width,
	float height,
	unsigned int frames,
	int style)
{
	m_windowName = window_text;
	m_size.width = width;
	m_size.height = height;
	m_frame = frames;
	m_delay = 1000 / frames;
	m_style = style;
}
