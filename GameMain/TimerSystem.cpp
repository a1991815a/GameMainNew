#include "TimerSystem.h"
#include "GameMainHeader.h"
#include "Timer.h"

TimerSystem::TimerSystem()
	:m_factor(1)
{
	m_startTime = m_curTime = m_preTime = 0;
}

TimerSystem::~TimerSystem()
{}

void TimerSystem::init()
{
	m_startTime = m_curTime = m_preTime = GetTickCount();
}

void TimerSystem::refresh()
{
	m_preTime = m_curTime;
	m_curTime = GetTickCount();
	time_type delta = (time_type)((m_curTime - m_preTime) * m_factor);

	auto itor = m_timerList.begin();
	for (; itor != m_timerList.end(); ++itor)
	{
		Timer* timer = *itor;
		timer->m_delta += (time_type)(timer->m_factor * delta);
	}
}

void TimerSystem::setTimerFactor(float factor)
{
	GMASSERT(factor >= 0);
	m_factor = factor;
}

void TimerSystem::insertTimer(Timer* timer)
{
	m_timerList.insert(timer);
}

void TimerSystem::removeTimer(Timer* timer)
{
	m_timerList.erase(timer);
}

