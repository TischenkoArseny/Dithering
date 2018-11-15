#ifndef ATKINSONDITHER_H
#define ATKINSONDITHER_H

#include "idither.h"



class AtkinsonDither: public IDither
{
public:
    int* execute(int* image, palette* p);
};

#endif // ATKINSONDITHER_H
