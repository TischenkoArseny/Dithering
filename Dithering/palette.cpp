#include "palette.h"
#include <fstream>

using namespace std;

palette::palette()
{

}

palette::~palette()
{

}

vector<RGB_Color>* palette::get_palette()
{
    return plt;
}

void palette::set_palette(vector<RGB_Color> *_plt)
{
    plt=_plt;
}

void palette::load(char *path)
{
    ifstream file;
    file.open(path);
    unsigned int tmp;
    while(!file.eof())
    {
       file >> tmp;
       plt->push_back(RGB_Color(tmp));
    }

}

void palette::save(char *path)
{
    ofstream file;
    file.open(path);

    for(int i=0; i<plt->size(); i++)
    {
        file << (*plt)[i].getColor();
    }
    file.close();
}

void palette::reduce_palette(int n)
{

}
