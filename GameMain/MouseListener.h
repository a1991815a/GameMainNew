#ifndef __MOUSELISTENER__
#define __MOUSELISTENER__
#include "Listener.h"

class MouseListener: public Listener{
public:
	MouseListener();
	~MouseListener();

	virtual bool trigger(Event* _event) override;

public:
	ListenerFunc OnMouseDown;
	ListenerFunc OnMouseUp;
	ListenerFunc OnMouseMove;
};
#endif