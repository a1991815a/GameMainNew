#ifndef __SCHEDULER__
#define __SCHEDULER__
#include "Ref.h"
#include "Timer.h"
#include <functional>
#include "GMCALLFUNC.h"

typedef std::function<void(time_type)> SchedulerFunc;

class Scheduler{
public:
	Scheduler();
	virtual ~Scheduler();
	void scheduleUpdate(
		time_type delay = 0,
		int priority = 0,
		int count = -1
		);
	void scheduleUpdateOnce(time_type delay = 0, int priority = 0);
	void schedule(
		SchedulerFunc func,
		time_type delay = 0,
		int priority = 0,
		int count = -1
		);
	void scheduleOnce(SchedulerFunc func, time_type delay = 0, int priority = 0);

	virtual void Update(time_type delta) {};
};
#endif