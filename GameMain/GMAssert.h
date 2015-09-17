#ifndef __GMASSERT__
#define __GMASSERT__
#include <assert.h>

#define GM_ASSERT(COND) assert(COND)

#define GMASSERT(COND) GM_ASSERT(COND)

#endif