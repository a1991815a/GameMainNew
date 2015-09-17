#ifndef __SCHEDULERSYSTEM__
#define __SCHEDULERSYSTEM__
#include "GameMacroHeader.h"
#include "SingleInstance.h"
#include "Scheduler.h"
#include "Prority_List.h"
#include "IteratorSolutioner.h"

#define _schedulerSystem ScheduleSystem::getInstance()

class ScheduleSystem: public SingleInstance<ScheduleSystem>{
	friend class Scheduler;
private:
	struct SchedulerNode{
		Scheduler* scheduler;
		SchedulerFunc func;
		Timer timer;
		time_type delay;
		int id;
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

	struct COMP_PTR {
		bool operator()(const Scheduler* scheduler, SchedulerNode& node) {
			return scheduler == node.scheduler;
		};
	} comp_ptr;

	struct COMP_ID
	{
		bool operator()(const int& _Left, SchedulerNode& _Right) {
			return _Left == _Right.id;
		};
	} comp_id;

	struct COMP_PRIORITY
	{
		bool operator()(const int& _Left, SchedulerNode& _Right) {
			return _Left == _Right.priority;
		};
	} comp_priority;

public:
	ScheduleSystem();
	~ScheduleSystem();

	void init();
	void destroy();
	void pushScheduler(
		SchedulerFunc func,
		time_type delay = 0,
		int excuteCount = GM_INFINITE,
		int priority = 0,
		Scheduler* scheduler = nullptr,
		int scheduler_id = 0);

	void removeScheduler(Scheduler* scheduler);
	void removeSchedulerById(int id);
	void removeSchedulerByPriority(int priority);


	void mainloop();

private:
	Prority_List<SchedulerNode, PriorityComp> m_schedulerList;
	IteratorSolutioner<Prority_List<SchedulerNode, PriorityComp>> m_iterator;
};


#endif