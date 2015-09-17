#include "DispatchMessageSystem.h"

DispatchMessageSystem::DispatchMessageSystem()
	:m_location()
{

}

DispatchMessageSystem::~DispatchMessageSystem()
{

}

void DispatchMessageSystem::init()
{
	m_listenerList.reserve(60);
	m_eventList.reserve(160);
}

void DispatchMessageSystem::mainloop()
{
//	键盘消息分发
	auto itor = m_keyList.begin();
	for (; itor != m_keyList.end(); ++itor)
	{
		Event e = Event(ET_KEY, KET_KEYDOWN);
		e.m_key = *itor;
		auto k_itor = m_listenerList.begin();
		for (; k_itor != m_listenerList.end(); ++k_itor)
		{
			Listener* listener = *k_itor;
			if (listener->trigger(&e))
				break;
		}
	}
/*************************************/

//其他消息分发
	auto e_itor = m_eventList.begin();
	for (;e_itor != m_eventList.end(); ++e_itor)
	{
		Event* event = *e_itor;
		auto k_itor = m_listenerList.begin();
		for (; k_itor != m_listenerList.end(); ++k_itor)
		{
			Listener* listener = *k_itor;
			if(listener->trigger(event))
				break;
		}
	}
/**************************************/
}

void DispatchMessageSystem::sendKeyMessage(const char& key, KeyEventTypes key_type)
{
	switch (key_type)
	{
	case KET_KEYDOWN:
	{
		auto itor = m_keyList.begin();
		for (; itor != m_keyList.end(); ++itor)
			if (*itor == key)
				return;
		m_keyList.push_back(key);
	}
		break;
	case KET_KEYUP:
	{
		auto itor = m_keyList.begin();
		for (; itor != m_keyList.end(); ++itor)
			if (*itor == key)
			{
				m_keyList.erase(itor);
				break;
			}
		Event* event = new Event(ET_KEY, KET_KEYUP);
		event->m_key = key;
		m_eventList.push_back(event);
	}
		break;
	default:
		break;
	}
}

void DispatchMessageSystem::sendMouseMessage(float x, float y, MouseEventTypes mouse_type)
{
	m_location.x = x;
	m_location.y = y;
	sendMessage(ET_MOUSE, mouse_type);
}

void DispatchMessageSystem::sendMessage(EventTypes type, EventParam param /*= 0*/, void* data /*= nullptr*/)
{
	Event* event = new Event(type, param, data);
	m_eventList.push_back(event);
}
