#ifndef __DIRECTOR__
#define __DIRECTOR__
#include "SingleInstance.h"
#include "UtilsHeader.h"
#include "Vec.h"
#include "Timer.h"

#define FILL_SCREEN 0

#define _director		Director::getInstance()

class Director: public SingleInstance<Director>{
	DEFINE_PRIVATE_INSTANCE(Director);
public:
	void init();
	void mainloop();
	void destroy();

	const Size& getWindowSize() const;
	void setDesignStyle(
		const GString& window_text,
		float width,
		float height, 
		unsigned int frames = 60, 
		int style = FILL_SCREEN);

	time_type getDelay() const { return m_delay; };
	time_type getDelta() const { return m_loopTimer.getDelta(); };
	Timer& getLoopTimer() { return m_loopTimer; };

	inline unsigned int getFrames() const { return m_frame; }
	inline void setFrames(const unsigned int& val) { m_frame = val; }
private:
	GString m_windowName;
	Size m_size;
	int m_style;
	unsigned int m_frame;
	time_type m_delay;
	Timer m_loopTimer;
};
#endif