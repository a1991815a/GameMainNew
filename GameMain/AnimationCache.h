#ifndef __ANIMATIONCACHE__
#define __ANIMATIONCACHE__
#include "GameMainHeader.h"
#include "SingleInstance.h"

#define _animationCache			AnimationCache::getInstance()

class AnimationCache: public SingleInstance<AnimationCache>{
	DEFINE_PRIVATE_INSTANCE(AnimationCache);
public:
	void init();
private:
	
};
#endif