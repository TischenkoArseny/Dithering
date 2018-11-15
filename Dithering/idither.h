#ifndef IDITHER_H
#define IDITHER_H
#include "palette.h"


class IDither
{
    virtual int* execute (int *image, palette *p)=0;

};


#endif // IDITHER_H
