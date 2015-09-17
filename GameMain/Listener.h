#ifndef __LISTENER__
#define __LISTENER__
#include "Ref.h"
#include "GameMainHeader.h"
#include <functional>
#include "Event.h"

typedef std::function<bool(Event*)> ListenerFunc;

class Listener: public Ref{
public:
	Listener(EventTypes type);
	virtual ~Listener();

	inline EventTypes getType() const { return m_type; };

	virtual bool trigger(Event* _event) = 0;
private:
	const EventTypes m_type;
};
#endif