#include "ditherfactory.h"
#include "floydsteinbergdither.h"
#include "atkinsondither.h"
#include "nulldither.h"
#include "sierralitedither.h"
#include "tworowsierradither.h"
#include "sierradither.h"

std::shared_ptr<IDither> DitherFactory::getMethod(DitherMethodId MethodId)
{
    switch(MethodId)
    {
   
	case (NULL_DITHER):
        return std::shared_ptr<NullDither>(new NullDither());


	case (FLOYD_STEINBERG_DITHER):
        return std::shared_ptr<FloydSteinbergDither>(new FloydSteinbergDither());


    case (ATKINSON_DITHER):
        return std::shared_ptr<AtkinsonDither>(new AtkinsonDither());


	case (SIERRA_LITE_DITHER):
        return std::shared_ptr<SierraLiteDither>(new SierraLiteDither());


	case (TWO_ROW_SIERRA_DITHER):
        return std::shared_ptr<TwoRowSierraDither>(new TwoRowSierraDither());

	case (SIERRA_DITHER):
        return std::shared_ptr<SierraDither>(new SierraDither());

    }
}
