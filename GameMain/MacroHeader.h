#ifndef __MACROHEADER__
#define __MACROHEADER__

#define SAFE_DELETE(p)				do{if(p) delete p; p = nullptr;} while(0)

#define SAFE_RETAIN(p)				do{if(p) p->retain();} while(0)
#define SAFE_RELEASE(p)				do{if(p) p->release(); p = nullptr;} while(0)

#define SAFE_RETAIN_COM(p)			do{if(p) p->Retain();} while(0)
#define SAFE_RELEASE_COM(p)			do{if(p) p->Release(); p = nullptr;} while(0)

#endif