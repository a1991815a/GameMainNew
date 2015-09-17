#include "SchedulerSystem.h"

ScheduleSystem::ScheduleSystem()
	:m_iterator(m_schedulerList)
{

}

ScheduleSystem::~ScheduleSystem()
{

}

void ScheduleSystem::init()
{

}

void ScheduleSystem::destroy()
{

}

void ScheduleSystem::pushScheduler(
	SchedulerFunc func, 
	time_type delay /*= 0*/,
	int excuteCount /*= INFINITE*/, 
	int priority /*= 0*/,
	Scheduler* scheduler /*= nullptr*/,
	int scheduler_id /*= 0*/)
{
	SchedulerNode node;
	node.scheduler = scheduler;
	node.func = func;
	node.delay = delay;
	node.id = scheduler_id;
	node.excuteCount = excuteCount;
	node.priority = priority;
	m_schedulerList.push_back(node);
}

void ScheduleSystem::removeScheduler(Scheduler* scheduler)
{
	m_iterator.updateItor(m_schedulerList.erase_if(scheduler, comp_ptr, true));
}

void ScheduleSystem::removeSchedulerById(int id)
{
	m_iterator.updateItor(m_schedulerList.erase_if(id, comp_id));
}

void ScheduleSystem::removeSchedulerByPriority(int priority)
{
	m_iterator.updateItor(m_schedulerList.erase_if(priority, comp_priority));
}

void ScheduleSystem::mainloop()
{
	auto itor = m_iterator.begin();
	for (; itor != m_iterator.end(); )
	{
		auto& node = *itor;
		if (node.timer.getDelta() >= node.delay) {
			node.func(node.timer.getDelta());
			if (node.excuteCount > GM_INFINITE)
				if (--node.excuteCount <= 0)
					m_iterator.updateItor(m_schedulerList.erase(itor));
			
			node.timer.reset();
		}
		itor = m_iterator.nextItor();
	}
}
