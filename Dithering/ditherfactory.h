#ifndef DITHERFACTORY_H
#define DITHERFACTORY_H
#include "idither.h"
#include <memory>

enum DitherMethodId{
	NULL_DITHER,
	FLOYD_STEINBERG_DITHER,
    ATKINSON_DITHER,
	SIERRA_LITE_DITHER,
	TWO_ROW_SIERRA_DITHER,
	SIERRA_DITHER
};

class DitherFactory
{
public:
   static std::shared_ptr<IDither> getMethod(DitherMethodId MethodId);

};

#endif // DITHERFACTORY_H
