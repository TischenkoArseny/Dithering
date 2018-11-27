#ifndef IDITHER_H
#define IDITHER_H
#include "palette.h"


class IDither
{
public:
    virtual void execute (QImage &image, palette &p)=0;
};


#endif // IDITHER_H
