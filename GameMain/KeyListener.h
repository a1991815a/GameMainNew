#ifndef __KEYLISTENER__
#define __KEYLISTENER__
#include "Listener.h"

class KeyListener: public Listener{
public:
	KeyListener();
	~KeyListener();

	virtual bool trigger(Event* _event) override;


public:
	ListenerFunc OnKeyDown;
	ListenerFunc OnKeyUp;
};
#endif