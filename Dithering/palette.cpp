#include <iostream>
#include "palette.h"
#include <fstream>
#include <QImage>
#include <vector>
#include <set>
#include <iterator>
#include <limits>
#include <cmath>
#include <algorithm>

typedef unsigned int uint;
using namespace std;

palette::palette()
{

}

palette::~palette()
{

}

vector<RgbColor>* palette::getPalette()
{
    return plt;
}

void palette::setPalette(vector<RgbColor> *_plt)
{
    plt=_plt;
}

void palette::load(string *path)
{
    ifstream file;
    file.open(path->c_str());
    unsigned int tmp;
    while(!file.eof())
    {
       file >> tmp;
       plt->push_back(RgbColor(tmp));
    }

}

void palette::save(string *path)
{
    ofstream file;
    file.open(path->c_str());
    for(auto it = plt->begin(); it != plt->end(); it++)
    {
        file << (*it).getRgb();
    }
    file.close();
}

void palette::createPalette(const QImage *img)
{
    plt = new vector<RgbColor>();
    for (int i = 0; i < img->width(); i++)
    {
        for(int j = 0; j < img->height(); j++)
        {
            plt->push_back(RgbColor(img->pixel(i,j)));
        }
    }
	auto it = unique(plt->begin(), plt->end());
	plt->erase(it, plt->end());
}

void palette::reducePalette(int n)
{
    division_count=n;
    vector<uint> red ;
    vector<uint> green;
    vector<uint> blue;
    for(auto it =plt->begin();it!=plt->end();it++)
    {
        red.push_back((*it).getRed());
        green.push_back((*it).getGreen());
        blue.push_back((*it).getBlue());
    }
    blocks.push(new Block(red, green, blue));
    devide();
    plt->clear();
    plt = new vector<RgbColor>();
    /*cout << "Blocks count = " << blocks.size() << endl;*/
    while(!blocks.empty())
    {
        plt->push_back(*blocks.front()->createColor());
        blocks.pop();
    }
    cout << "Palette reduced to " << plt->size() << " colors" << endl;
}

void palette::devide()
{
    if(blocks.size() < static_cast<uint>(division_count))
    {
        uint size = blocks.size();
        for(uint i = 0; i < size; i++)
        {
            Block *tmp = blocks.front();
            if(tmp->getBlockSize() > 1)
            {
                blocks.pop();
                tmp->makeParts();
                if(tmp->getPart1()->size() > 0 && blocks.size() < static_cast<uint>(division_count)) blocks.push(new Block(tmp->getPart1()));
                if(tmp->getPart2()->size() > 0 && blocks.size() < static_cast<uint>(division_count)) blocks.push(new Block(tmp->getPart2()));
            }
            else blocks.push(tmp);
        }
        devide();
    }
}

RgbColor palette::nearestColor(RgbColor rgbc)
{
	RgbColor nearest = plt->front();
	double distanceTemp = numeric_limits<double>::max();
	for (auto it = plt->begin(); it != plt->end(); ++it)
	{
		RgbColor tempCycle = *it;
		double distanceCycle = sqrt((tempCycle.getRed() - rgbc.getRed())*(tempCycle.getRed() - rgbc.getRed()) +
			(tempCycle.getGreen() - rgbc.getGreen())*(tempCycle.getGreen() - rgbc.getGreen())
			+ (tempCycle.getBlue() - rgbc.getBlue())*(tempCycle.getBlue() - rgbc.getBlue()));
		if (distanceCycle < distanceTemp)
		{
			distanceTemp = distanceCycle;
			nearest = tempCycle;
		};
	}
	return nearest;

}

void palette::makeUnique()
{
    set<RgbColor> *tmp = new set<RgbColor>();
    unsigned size = plt->size();
    for( unsigned i = 0; i < size; ++i ) tmp->insert((*plt)[i]);
    plt->assign( tmp->begin(), tmp->end());
    delete tmp;
}

