#include <iostream>
#include <fstream>
#include "Bitmap.h"

Bitmap::Bitmap(int width, int height) : _width(width), _height(height)
{
	_pixels_p = new int[pixel_count_rgb()]{ 0 };
	if (!_pixels_p)
		std::cout << "allocating _pixels_p failed" << std::endl;
}

Bitmap::~Bitmap() 
{
	delete[] _pixels_p;
}

bool Bitmap::write(std::string filename)
{
	BitmapFileHeader file_header;
	BitmapInfoHeader info_header;

	file_header.file_size = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + pixel_count_rgb();
	file_header.data_offset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	info_header.width = _width;
	info_header.height = _height;

	std::fstream fs(filename, std::ios::out|std::ios::binary);
	if (!fs)
		return false;

	fs.write((char*)& file_header, sizeof(file_header));
	fs.write((char*)& info_header, sizeof(info_header));
	fs.write((char*)_pixels_p, pixel_count_rgb());

	fs.close();

	return true;
}

void Bitmap::set_pixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
}

