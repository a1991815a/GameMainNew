#ifndef __GMCALLFUNC__
#define __GMCALLFUNC__
#include <functional>

#define GMCALLFUNC_0(FUNC, INS) std::bind(&FUNC, INS)
#define GMCALLFUNC_1(FUNC, INS) std::bind(&FUNC, INS, std::placeholders::_1)
#define GMCALLFUNC_2(FUNC, INS) std::bind(&FUNC, INS, std::placeholders::_1, std::placeholders::_2)
#define GMCALLFUNC_3(FUNC, INS) std::bind(&FUNC, INS, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)
#define GMCALLFUNC_4(FUNC, INS) std::bind(&FUNC, INS, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)
#define GMCALLFUNC_5(FUNC, INS) std::bind(&FUNC, INS, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5)

#endif