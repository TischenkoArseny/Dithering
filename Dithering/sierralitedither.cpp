#include "sierralitedither.h"

void SierraLiteDither::execute(QImage &img, palette &plt)
{
	RgbColor offsetPixel;
	RgbColor oldcolor;
	RgbColor newcolor;
	int redError;
	int blueError;
	int greenError;
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

			//calculate color matching error for each channel
            redError = static_cast<int>(oldcolor.getRed() - newcolor.getRed());
            greenError = static_cast<int>(oldcolor.getGreen() - newcolor.getGreen());
            blueError = static_cast<int>(oldcolor.getBlue() - newcolor.getBlue());

			//replace current pixel color with new color
			img.setPixel(x, y, newcolor.getRgb());

			if (x + 1 < img.width())
			{
				offsetPixel = img.pixel(x + 1, y);

                offsetPixel.setRed((static_cast<int>(offsetPixel.getRed()) + ((redError << 1) >> 2)));
                offsetPixel.setGreen((static_cast<int>(offsetPixel.getGreen()) + ((greenError << 1) >> 2)));
                offsetPixel.setBlue((static_cast<int>(offsetPixel.getBlue()) + ((blueError << 1) >> 2)));

				img.setPixel(x + 1, y, offsetPixel.getRgb());
			}
			if (y + 1 < img.height())
			{
				offsetPixel = img.pixel(x, y + 1);

                offsetPixel.setRed((static_cast<int>(offsetPixel.getRed()) + (redError >> 2)));
                offsetPixel.setGreen((static_cast<int>(offsetPixel.getGreen()) + (greenError >> 2)));
                offsetPixel.setBlue((static_cast<int>(offsetPixel.getBlue()) + (blueError >> 2)));

				img.setPixel(x, y + 1, offsetPixel.getRgb());

				if (x - 1 >= 0)
				{
					offsetPixel = img.pixel(x - 1, y + 1);

                    offsetPixel.setRed((static_cast<int>(offsetPixel.getRed()) + (redError >> 2)));
                    offsetPixel.setGreen((static_cast<int>(offsetPixel.getGreen()) + (greenError >> 2)));
                    offsetPixel.setBlue((static_cast<int>(offsetPixel.getBlue()) + (blueError >> 2)));

					img.setPixel(x - 1, y + 1, offsetPixel.getRgb());
				}
			}
		}
	}
	delete p;
}
