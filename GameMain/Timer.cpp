#include "Timer.h"
#include "GMAssert.h"
#include "TimerSystem.h"

Timer::Timer()
	:m_delta(0), m_factor(1)
{
	TimerSystem::getInstance()->insertTimer(this);
}

Timer::~Timer()
{
	TimerSystem::getInstance()->removeTimer(this);
}

void Timer::reset()
{
	m_delta = 0;
}

void Timer::setTimerFactor(float factor)
{
	GMASSERT(factor >= 0);
	m_factor = factor;
}
