#pragma once
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include <string>
class Bitmap
{
private:
	int _width{ 0 };
	int _height{ 0 };
	uint8_t *_pixels_p{ nullptr };

public:
	Bitmap(int width, int height);
	__forceinline int pixel_count_rgb() { return this->_height * this->_width * 3; };
	bool write(std::string filename);
	void set_pixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	virtual ~Bitmap();
};

