#ifndef __EVENT__
#define __EVENT__
#include "GameMainHeader.h"
#include "Vec.h"
#include "Ref.h"

typedef unsigned long EventParam;

enum EventTypes: EventParam
{
	ET_UNKNOWN,
	ET_MOUSE,
	ET_KEY,
	ET_CREATE,
	ET_DESTROY,
	ET_CUSTOM
};

enum MouseEventTypes: EventParam
{
	MET_LBDOWN,
	MET_LBUP,
	MET_MOVE
};

enum KeyEventTypes: EventParam
{
	KET_KEYDOWN,
	KET_KEYUP
};

class Event: public Ref{
	friend class DispatchMessageSystem;
public:
	Event(EventTypes type, EventParam param = 0, void* data = nullptr);
	~Event();

	inline EventTypes getEventType() const { return m_type; };
	const std::vector<char>& getKeys() const;
	const Vec2& getLocation() const;
	const char& getKey() const;

	void setData(void* data);
	inline void* getDate() { return m_data; };
	inline const void* getDate() const { return m_data; }
	inline EventParam getParam() const { return m_param; };
private:
	const EventTypes m_type;
	const EventParam m_param;
	char m_key;
	void* m_data;
};
#endif