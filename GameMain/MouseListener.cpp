#include "MouseListener.h"

MouseListener::MouseListener()
	:Listener(ET_MOUSE), 
	OnMouseDown(nullptr), OnMouseUp(nullptr), 
	OnMouseMove(nullptr)
{

}

MouseListener::~MouseListener()
{

}

bool MouseListener::trigger(Event* _event)
{
	switch (_event->getParam())
	{
	case MET_LBDOWN:
		if (OnMouseDown)
			return OnMouseDown(_event);
		break;
	case MET_LBUP:
		if (OnMouseUp)
			return OnMouseUp(_event);
		break;
	case MET_MOVE:
		if (OnMouseMove)
			return OnMouseMove(_event);
		break;
	default:
		break;
	}
	return false;
}
