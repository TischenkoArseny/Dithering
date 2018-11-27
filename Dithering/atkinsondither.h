#ifndef ATKINSONDITHER_H
#define ATKINSONDITHER_H

#include "idither.h"



class AtkinsonDither: public IDither
{
public:
	void execute(QImage &img, palette &plt) override;
};

#endif // ATKINSONDITHER_H
