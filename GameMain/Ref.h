#ifndef __REF__
#define __REF__
#include "MemoryPoolSystem.h"
#include "GMAssert.h"

class Ref{
public:
	Ref()
		:referenceCount(0), isAutorelease(false)
	{};
	virtual ~Ref() {};

	inline void autorelease() {
		_memoryPoolSystem->getCurrentPool()->push(this);
		++referenceCount;
		isAutorelease = true;
	};

	inline void release() {
		if (isAutorelease && --referenceCount == 0) {
			GMASSERT(referenceCount == 0);
			delete this;
		}
	};

	inline void retain() {
		if (isAutorelease)
			++referenceCount;
	};


private:
	size_t referenceCount;
	bool isAutorelease;
};
#endif