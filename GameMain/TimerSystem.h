#ifndef __TIMERSYSTEM__
#define __TIMERSYSTEM__
#include <windows.h>
#include "SingleInstance.h"
#include <set>
#include "Timer.h"

#define _timerSystem		TimerSystem::getInstance()

class TimerSystem: public SingleInstance<TimerSystem>{
	DEFINE_PRIVATE_INSTANCE(TimerSystem);
	friend class Timer;
public:
	void init();
	void refresh();
	void setTimerFactor(float factor);
private:
	void insertTimer(Timer* timer);
	void removeTimer(Timer* timer);

private:
	time_type m_startTime;
	time_type m_preTime;
	time_type m_curTime;
	float m_factor;
	std::set<Timer*> m_timerList;
};
#endif