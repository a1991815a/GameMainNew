#ifndef __SPRITEFRAMECACHE__
#define __SPRITEFRAMECACHE__
#include "GameMainHeader.h"
#include "SingleInstance.h"

#define _spriteFrameCache			SpriteFrameCache::getInstance()

class SpriteFrameCache: public SingleInstance<SpriteFrameCache>{
	DEFINE_PRIVATE_INSTANCE(SpriteFrameCache);
public:
	void init();


private:
	
};
#endif