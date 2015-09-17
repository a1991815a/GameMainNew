#ifndef __SCHEDULERMANAGER__
#define __SCHEDULERMANAGER__
#include "SingleInstance.h"
#include "Scheduler.h"
#include "Prority_List.h"

class SchedulerManager: public SingleInstance<SchedulerManager>{
	friend class Scheduler;
private:
	struct SchedulerNode{
		Scheduler* scheduler;
		SchedulerFunc func;
		Timer timer;
		time_type delay;
		int excuteCount;
		int priority;
		bool operator==(const SchedulerNode& obj){
			return scheduler == obj.scheduler;
		}
	};

	struct PriorityComp{
		bool operator()(const SchedulerNode& _Left, const SchedulerNode& _Right){
			return _Left.priority > _Right.priority;
		};
	};

public:
	void pushScheduler(SchedulerNode);
	void popScheduler(Scheduler* scheduler);
	void mainloop();

private:
	Prority_List<SchedulerNode, PriorityComp> m_schedulerList;
};
#endif