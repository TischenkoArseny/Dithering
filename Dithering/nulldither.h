#pragma once

#include "idither.h"
#include "RgbColor.h"
#include <QImage>
#include "palette.h"

class NullDither : public IDither 
{
public:
	void execute(QImage &img, palette &plt) override
	{
		RgbColor oldcolor;
		RgbColor newcolor;
		std::map<RgbColor, RgbColor> *p = new map<RgbColor, RgbColor>;
		for (unsigned short y = 0; y < img.height(); ++y)
		{
			for (unsigned short x = 0; x < img.width(); ++x)
			{
				//get current pixel color
				oldcolor = img.pixel(x, y);
				
				//if color occur not first time using linked color instead of searching in palette
				auto it = p->find(oldcolor);
				if (it != p->end())
				{
					newcolor = *it->second;
				}
				
				//or save current color if it occurs first time and gettin new from palette
				else
				{
					newcolor = plt.nearestColor(oldcolor);
					p->emplace(oldcolor, newcolor);
				}
				
				//replace current pixel color with new color
				img.setPixel(x, y, newcolor.getRgb());
			}
		}
		delete p;
	}
};