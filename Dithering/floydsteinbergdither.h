#ifndef FLOYDSTEINBERGDITHER_H
#define FLOYDSTEINBERGDITHER_H

#include "idither.h"



class FloydSteinbergDither: public IDither
{
public:
    int* execute(int *image, palette* p);
};

#endif // FLOYDSTEINBERGDITHER_H
