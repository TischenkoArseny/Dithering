#ifndef PALETTE_H
#define PALETTE_H
#include "rgb_color.h"
#include <vector>

using namespace std;

class palette
{
public:
    palette();
    ~palette();
    vector<RGB_Color>* get_palette();
    void set_palette(vector<RGB_Color>* _plt);
    void load(char* path);
    void save(char* path);
    void reduce_palette(int n);
private:
    vector<RGB_Color> *plt;
};

#endif // PALETTE_H
