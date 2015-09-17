#include "Event.h"
#include "DispatchMessageSystem.h"

Event::Event(EventTypes type, EventParam param, void* data)
	:m_type(type), m_param(param), m_key(0), m_data(data)
{

}

Event::~Event()
{

}

const std::vector<char>& Event::getKeys() const
{
	return _messageDispatcher->m_keyList;
}

const Vec2& Event::getLocation() const
{
	return _messageDispatcher->m_location;
}

const char& Event::getKey() const
{
	return m_key;
}

void Event::setData(void* data)
{
	m_data = data;
}
