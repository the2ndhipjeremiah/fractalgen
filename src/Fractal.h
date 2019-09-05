#pragma once
#include <string>
#include "ZoomList.h"
#include "Bitmap.h"
#include "Rgb.h"
#include <tuple>

class Fractal
{
private:
	int _width{800};
	int _height{600};
	int _max_iterations{ 1000 };
	int* _histogram{ nullptr };
	int* _cumulative_histogram{ nullptr };
	int* _fractal_data{ nullptr };
	Bitmap bitmap = Bitmap(_width, _height);
	ZoomList _zoom_list = ZoomList(_width, _height);
	std::vector<std::tuple<int, int, int, Rgb>> colour_ranges;

public:
	void zoom_in(int x, int y, double scale);
	void zoom_in_y0_bottom(int x, int y, double scale);
	void add_colour_range(double endpoint, double end_point, const Rgb& colour);
	int get_colour_range(int iterations) const;
	Fractal(int width, int height, int max_iterations);
	virtual ~Fractal();
	void compute();
	void draw();
	void write_to_bitmap(std::string filename);
};

