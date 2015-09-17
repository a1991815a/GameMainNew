#ifndef __TEXTURECACHE__
#define __TEXTURECACHE__
#include "GameMainHeader.h"
#include "SingleInstance.h"

#define _textureCache			TextureCache::getInstance()

class TextureCache: public SingleInstance<TextureCache>{
	DEFINE_PRIVATE_INSTANCE(TextureCache);
public:
	void init();
private:
	
};
#endif