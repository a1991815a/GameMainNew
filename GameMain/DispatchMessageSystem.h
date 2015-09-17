#ifndef __DISPATCHMESSAGESYSTEM__
#define __DISPATCHMESSAGESYSTEM__
#include "GameMainHeader.h"
#include "SingleInstance.h"
#include "Vec.h"
#include "Vector.h"
#include "Listener.h"
#include "Event.h"

#define _messageDispatcher		DispatchMessageSystem::getInstance()

class DispatchMessageSystem: public SingleInstance<DispatchMessageSystem>{
	DEFINE_PRIVATE_INSTANCE(DispatchMessageSystem);
	friend class Event;
public:
	void init();
	void mainloop();
	void sendKeyMessage(const char& key, KeyEventTypes key_type);
	void sendMouseMessage(float x, float y, MouseEventTypes mouse_type);
	void sendMessage(EventTypes type, EventParam param = 0, void* data = nullptr);


private:
	Vector<Listener*> m_listenerList;
	Vector<Event*> m_eventList;
	std::vector<char> m_keyList;
	Vec2 m_location;
};
#endif