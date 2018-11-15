#ifndef RGB_COLOR_H
#define RGB_COLOR_H

class RGB_Color
{
public:

    RGB_Color();
    RGB_Color(unsigned int x);
    ~RGB_Color();

    unsigned char getRed();
    unsigned char getGreen();
    unsigned char getBlue();
    unsigned char getALpha();

    void setRed(unsigned char red);
    void setGreen(unsigned char green);
    void setBlue(unsigned char blue);
    void setAlpha(unsigned char alpha);

    unsigned int getColor();

private:

    unsigned int color;
    unsigned char alpha;
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

#endif // RGB_COLOR_H
