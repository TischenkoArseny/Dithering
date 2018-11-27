#include <iostream>
#include <QImage>
#include "Rgbcolor.h"
#include "ditherfactory.h"
#include <atkinsondither.h>
using namespace std;

int main()
{

//    palette *pal=new palette("1.png");
//    pal->save("palette.txt");
//    pal->make_unique();
//    pal->save("unique_palette.txt");
    QImage img;
    img.load("image.png");
    palette pal;
    pal.createPalette(&img);
    pal.reducePalette(32);
    DitherFactory::getMethod(FLOYD_STEINBERG_DITHER).get()->execute(img,pal);
    img.save("res.png");
    system("pause");
    return 1;
}
