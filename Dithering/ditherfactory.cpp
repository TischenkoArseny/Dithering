#include "ditherfactory.h"
#include "floydsteinbergdither.h"
#include "atkinsondither.h"


std::shared_ptr<IDither> DitherFactory::getMethod(DitherMethodId MethodId)
{
    switch(MethodId)
    {
    case (FLOYD_STEINBERG_DITHER):
        return std::shared_ptr<FloydSteinbergDither>();
        break;


    case (ATKINSON_DITHER):
        return std::shared_ptr<AtkinsonDither>();
        break;
    }
}
