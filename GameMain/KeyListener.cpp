#include "KeyListener.h"

KeyListener::KeyListener()
	:Listener(ET_KEY), OnKeyDown(nullptr), OnKeyUp(nullptr)
{

}

KeyListener::~KeyListener()
{

}

bool KeyListener::trigger(Event* _event)
{
	switch (_event->getParam())
	{
	case KET_KEYDOWN:
		if (OnKeyDown != nullptr)
			return OnKeyDown(_event);
		break;
	case KET_KEYUP:
		if (OnKeyUp != nullptr)
			return OnKeyUp(_event);
		break;
	default:
		break;
	}

	return false;
}
