#ifndef FLOYDSTEINBERGDITHER_H
#define FLOYDSTEINBERGDITHER_H

#include "idither.h"
#include "RgbColor.h"
#include <QImage>
#include "palette.h"



class FloydSteinbergDither: public IDither
{
public:
    void execute(QImage &img, palette &plt) override;
};

#endif // FLOYDSTEINBERGDITHER_H
