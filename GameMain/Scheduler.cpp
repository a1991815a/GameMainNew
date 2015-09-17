#include "Scheduler.h"
#include "SchedulerSystem.h"


Scheduler::Scheduler()
{

}

Scheduler::~Scheduler()
{
	_schedulerSystem->removeScheduler(this);
}

void Scheduler::scheduleUpdate(
	time_type delay /*= 0*/,
	int priority /*= 0*/,
	int count /*= -1*/
	)
{
	_schedulerSystem->pushScheduler(GMCALLFUNC_1(Scheduler::Update, this), delay, count, priority, this);
}

void Scheduler::scheduleUpdateOnce(time_type delay /*= 0*/, int priority /*= 0*/)
{
	_schedulerSystem->pushScheduler(GMCALLFUNC_1(Scheduler::Update, this), delay, 1, priority, this);
}

void Scheduler::schedule(SchedulerFunc func, time_type delay /*= 0*/, int priority /*= 0 */, int count /*= -1*/)
{
	_schedulerSystem->pushScheduler(func, delay, count, priority, this);
}

void Scheduler::scheduleOnce(SchedulerFunc func, time_type delay /*= 0*/, int priority /*= 0*/)
{
	_schedulerSystem->pushScheduler(func, delay, 1, priority, this);
}
