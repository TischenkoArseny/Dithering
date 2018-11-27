#ifndef PALETTE_H
#define PALETTE_H
#include "rgbcolor.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <QImage>

using namespace std;

class palette
{
public:
    palette();
    ~palette();
    vector<RgbColor>* getPalette();
    void setPalette(vector<RgbColor>* _plt);
    void load(string *path);
    void save(string *path);
    void createPalette(const QImage *img);
    void reducePalette(int n);
    void devide();
	RgbColor nearestColor(RgbColor);
    void makeUnique();
private:
    vector<RgbColor> *plt;
    class Block
    {
    private:
        vector<vector<uint>> *colors;
        vector<vector<uint>> *part1;
        vector<vector<uint>> *part2;
        uint medianPoint;
        int longestSideIndex;
    public:
        Block(vector<uint> &red, vector<uint> &green, vector<uint> &blue)
        {
            colors = new vector<vector<uint>>(3);
            (*colors)[0].assign(red.begin(), red.end());
            (*colors)[1].assign(green.begin(), green.end());
            (*colors)[2].assign(blue.begin(), blue.end());

            uint maxR = (*std::max_element((*colors)[0].begin(),(*colors)[0].end()));
            uint minR = (*std::min_element((*colors)[0].begin(),(*colors)[0].end()));
            uint maxG = (*std::max_element((*colors)[1].begin(),(*colors)[1].end()));
            uint minG = (*std::min_element((*colors)[1].begin(),(*colors)[1].end()));
            uint maxB = (*std::max_element((*colors)[2].begin(),(*colors)[2].end()));
            uint minB = (*std::min_element((*colors)[2].begin(),(*colors)[2].end()));

            uint lenghtR = maxR-minR;
            uint lenghtG = maxG-minG;
            uint lenghtB = maxB-minB;

            if(lenghtR>=lenghtG && lenghtR>=lenghtB)
            {
                longestSideIndex = 0;
                medianPoint = minR + lenghtR/2;
            }else
            if(lenghtG>=lenghtR && lenghtG>=lenghtB)
            {
                longestSideIndex = 1;
                medianPoint = minG + lenghtG/2;
            }else
            if(lenghtB>=lenghtR && lenghtB>=lenghtG)
            {
                longestSideIndex = 2;
                medianPoint = minB + lenghtB/2;
            }
        }
        Block(vector<vector<uint> > *tmp)
        {
            colors = tmp;

            uint maxR = (*std::max_element((*colors)[0].begin(),(*colors)[0].end()));
            uint minR = (*std::min_element((*colors)[0].begin(),(*colors)[0].end()));
            uint maxG = (*std::max_element((*colors)[1].begin(),(*colors)[1].end()));
            uint minG = (*std::min_element((*colors)[1].begin(),(*colors)[1].end()));
            uint maxB = (*std::max_element((*colors)[2].begin(),(*colors)[2].end()));
            uint minB = (*std::min_element((*colors)[2].begin(),(*colors)[2].end()));
            uint lenghtR = maxR-minR;
            uint lenghtG = maxG-minG;
            uint lenghtB = maxB-minB;

            if(lenghtR>=lenghtG && lenghtR>=lenghtB)
            {
                longestSideIndex = 0;
                medianPoint = minR + lenghtR/2;
            }else
            if(lenghtG>=lenghtR && lenghtG>=lenghtB)
            {
                longestSideIndex = 1;
                medianPoint = minG + lenghtG/2;
            }else
            if(lenghtB>=lenghtR && lenghtB>=lenghtG)
            {
                longestSideIndex = 2;
                medianPoint = minB + lenghtB/2;
            }
        }

        ~Block()
        {

        }

        uint getLongestSideSize() const
        {
             return medianPoint;
        }
        int getLongestSideIndex() const
        {
            return longestSideIndex;
        }
        uint getBlockSize()
        {
            return (*colors)[0].size();
        }
        vector<vector<uint>>* getPart1()
        {
            return part1;
        }
        vector<vector<uint>>* getPart2()
        {
            return part2;
        }
        void makeParts()
        {
            if((*colors)[0].size() > 1 )
            {
                uint i = 0;
                part1 = new vector<vector<uint>>(3);
                part2 = new vector<vector<uint>>(3);
                for(auto it = (*colors)[static_cast<uint>(longestSideIndex)].begin(); it !=(*colors)[static_cast<uint>(longestSideIndex)].end();it++)
                {
                    if((*it) < medianPoint)
                    {
                        (*part1)[0].push_back((*colors)[0][i]);
                        (*part1)[1].push_back((*colors)[1][i]);
                        (*part1)[2].push_back((*colors)[2][i]);
                    }
                    else
                    {
                        (*part2)[0].push_back((*colors)[0][i]);
                        (*part2)[1].push_back((*colors)[1][i]);
                        (*part2)[2].push_back((*colors)[2][i]);
                    }
                    i++;
                }
            }
        }
        RgbColor* createColor()
        {
            uint maxR = (*std::max_element((*colors)[0].begin(),(*colors)[0].end()));
            uint minR = (*std::min_element((*colors)[0].begin(),(*colors)[0].end()));
            uint maxG = (*std::max_element((*colors)[1].begin(),(*colors)[1].end()));
            uint minG = (*std::min_element((*colors)[1].begin(),(*colors)[1].end()));
            uint maxB = (*std::max_element((*colors)[2].begin(),(*colors)[2].end()));
            uint minB = (*std::min_element((*colors)[2].begin(),(*colors)[2].end()));

            RgbColor *tmp = new RgbColor((maxR+minR)/2, (maxG+minG)/2, (maxB+minB)/2);
            return tmp;
        }
    };
    queue<Block*> blocks;
    int division_count;
};

#endif // PALETTE_H
