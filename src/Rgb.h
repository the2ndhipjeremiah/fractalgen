#pragma once
struct Rgb
{
	double red{ 0.0 };
	double green{ 0.0 };
	double blue{ 0.0 };

	__forceinline Rgb(double red, double green, double blue) : red(red), green(green), blue(blue) {}
	__forceinline Rgb(const Rgb& rgb):red(rgb.red), green(rgb.green), blue(rgb.blue) {}
	__forceinline Rgb operator-(const Rgb& rhs){return Rgb(this->red - rhs.red, this->green - rhs.green, this->blue - rhs.blue);}
	__forceinline Rgb operator=(const Rgb& rhs) { return Rgb(rhs); }
};


