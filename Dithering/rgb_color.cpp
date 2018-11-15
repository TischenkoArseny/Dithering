#include "rgb_color.h"
#include <iostream>

using namespace std;

RGB_Color::RGB_Color():color(0), alpha(0), r(0), g(0), b(0)
{
}

RGB_Color::RGB_Color(unsigned int x)
{
    color = x;
    unsigned char res;
    res = (unsigned char)x;
    b = res;
    x = x >> 8;
    res = (unsigned char)x;
    g = res;
    x = x >> 8;
    res = (unsigned char)x;
    r = res;
    x = x >>8;
    res = (unsigned char)x;
    alpha = res;
}

RGB_Color::~RGB_Color()
{
}

unsigned char RGB_Color::getRed()
{
    return r;
}

unsigned char RGB_Color::getGreen()
{
    return g;
}

unsigned char RGB_Color::getBlue()
{
    return b;
}

unsigned char RGB_Color::getALpha()
{
    return alpha;
}


void RGB_Color::setRed(unsigned char red)
{
}

void RGB_Color::setGreen(unsigned char green)
{

}

void RGB_Color::setBlue(unsigned char blue)
{

}

void RGB_Color::setAlpha(unsigned char alpha)
{

}

unsigned int RGB_Color::getColor()
{
    return color;
}
