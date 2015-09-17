#ifndef __TIMER__
#define __TIMER__

typedef unsigned long time_type;

class Timer{
	friend class TimerSystem;
public:
	Timer();
	~Timer();
	inline time_type getDelta() const {
		return m_delta;
	};
	void reset();
	void setTimerFactor(float factor);
private:
	time_type m_delta;
	float m_factor;
};
#endif