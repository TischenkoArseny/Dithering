#pragma once

typedef unsigned int uint;
typedef unsigned char uchar;

class RgbColor
{
	uint rgb;
public:
	RgbColor() = default;
	RgbColor(uint red, uint green, uint blue, uint alpha = 255)
	{
        this->rgb = static_cast<uint>(static_cast<uchar>(alpha) << 24 | static_cast<uchar>(red) << 16 | static_cast<uchar>(green) << 8 | static_cast<uchar>(blue));

	}

	RgbColor(uint rgb)
	{
		this->rgb = rgb;
	}

	RgbColor operator*() 
	{
		return *this;
	}
	
	bool operator<(const RgbColor &v)const
    {
        return this->rgb < v.rgb;
    }


	bool operator==(const RgbColor &rgbc) 
	{
		if (this->rgb == rgbc.rgb)
			return true;
		else 
			return false;
	}

	uint getRgb() const
    {
        return rgb;
    }
    uint getAlpha()
	{
        return static_cast<uchar>(rgb >> 24);
	}
    uint getRed()
	{
        return static_cast<uchar>(rgb >> 16);
	}
    uint getGreen()
	{
        return static_cast<uchar>(rgb >> 8);
	}
    uint getBlue()
	{
        return static_cast<uchar>(rgb);
	}
	void setAlpha(int alpha)
	{
		if (alpha < 256 && alpha >= 0)
            this->rgb = (this->rgb & 0x00ffffff) | static_cast<uint>(alpha) << 24;
		else if (alpha < 0) 
		{
			alpha = 0;
            this->rgb = (this->rgb & 0x00ffffff) | static_cast<uint>(alpha) << 24;
		}
		else if (alpha > 255) 
		{
			alpha = 255;
            this->rgb = (this->rgb & 0x00ffffff) | static_cast<uint>(alpha) << 24;
		}
	}
	void setRed(int red)
	{
        if(red<256 && red >=0)
            this->rgb = (this->rgb & 0xff00ffff) | static_cast<uint>(red) << 16;
		else if (red < 0) 
		{
			red = 0;
            this->rgb = (this->rgb & 0xff00ffff) | static_cast<uint>(red) << 16;
		}
		else if(red>255)
		{
			red = 255;
            this->rgb = (this->rgb & 0xff00ffff) | static_cast<uint>(red) << 16;
		}
	}
	void setGreen(int green)
	{
		if(green<256 && green >=0)
            this->rgb = (this->rgb & 0xffff00ff) | static_cast<uint>(green) << 8;
		else if (green < 0) 
		{
			green = 0;
            this->rgb = (this->rgb & 0xffff00ff) | static_cast<uint>(green) << 8;
		}
		else if (green > 255) 
		{
			green = 255;
            this->rgb = (this->rgb & 0xffff00ff) | static_cast<uint>(green) << 8;
		}
	}
	void setBlue(int blue)
	{
		if (blue<256 && blue>=0)
            this->rgb = (this->rgb & 0xffffff00) | static_cast<uchar>(blue);
		else if (blue < 0) 
		{
			blue = 0;
            this->rgb = (this->rgb & 0xffffff00) | static_cast<uchar>(blue);
		}
		else if (blue > 255) 
		{
			blue = 255;
            this->rgb = (this->rgb & 0xffffff00) | static_cast<uchar>(blue);
		}
	}
};
