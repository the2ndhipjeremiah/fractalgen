#include <cmath>
#include "Fractal.h"
#include "Mandelbrot.h"

void Fractal::zoom_in(int x, int y, double scale)
{
	_zoom_list.add(_zoom_list.create_zoom(x, _height - y, scale));
}

void Fractal::zoom_in_y0_bottom(int x, int y, double scale)
{
	_zoom_list.add(_zoom_list.create_zoom(x, y, scale));
}

void Fractal::add_colour_range(double start_point, double end_point, const Rgb& colour)
{
	int number_of_ranges = colour_ranges.size();
	int pixels_with_iterations{ 0 };
	int start_iteration = (int)(start_point * _max_iterations);
	int end_iteration = (int)(end_point * _max_iterations);

	if (end_iteration == _max_iterations)
	{
		pixels_with_iterations = _cumulative_histogram[end_iteration-1] - _cumulative_histogram[start_iteration];
	}
	else
	{
		pixels_with_iterations = _cumulative_histogram[end_iteration] - _cumulative_histogram[start_iteration];
	}

	std::tuple<int, int, int, Rgb> range = std::make_tuple(start_iteration, end_iteration, pixels_with_iterations, colour);
	colour_ranges.push_back(range);
}

int Fractal::get_colour_range(int iterations) const
{
	int count{ 0 };
	for (auto& ele : colour_ranges)
	{
		int ele_iterations = std::get<1>(ele);
		int pixels = std::get<2>(ele);
		Rgb colour = std::get<3>(ele);
		if (iterations <= ele_iterations) 
		{
			return count;
		}
		count++;
	}
	return 0;
}

Fractal::Fractal(int width, int height, int max_iterations): _width(width), _height(height), _max_iterations(max_iterations)
{
	_histogram = new int[_max_iterations];
	_cumulative_histogram = new int[_max_iterations];
	_fractal_data = new int[_width * _height];
	std::fill(_histogram, _histogram + _max_iterations, 0);
	std::fill(_cumulative_histogram, _cumulative_histogram + _max_iterations, 0);
	std::fill(_fractal_data, _fractal_data + (_width * _height), 0);
	_zoom_list.add(_zoom_list.create_zoom(_width / 2, _height / 2, 4.0 / _width));
}

Fractal::~Fractal()
{
	delete[] this->_histogram;
	delete[] this->_fractal_data;
	delete[] this->_cumulative_histogram;
}

void Fractal::compute()
{
	std::pair<double, double> xy_fractal{ 0.0, 0.0 };
	int iterations{ 0 };
	int total_iterations{ 0 };

	for (int y = 0; y < _height; ++y)
	{
		for (int x = 0; x < _width; ++x)
		{
			xy_fractal = _zoom_list.zoom(x, y);
			iterations = Mandelbrot::get_iterations(xy_fractal.first, xy_fractal.second, _max_iterations);

			_fractal_data[y * _width + x] = iterations;

			if (iterations < _max_iterations)
				_histogram[iterations]++;
		}
	}

	for (int i = 0; i < _max_iterations; ++i)
	{
		if (i == 0) 
		{
			_cumulative_histogram[i] = _histogram[i];
		}
		else 
		{
			_cumulative_histogram[i] = _histogram[i] + _cumulative_histogram[i - 1];
		}

	}
}

void Fractal::draw()
{
	int colour_range{ 0 };
	int colour_end_iterations{ 0 };
	int colour_start_iterations{ 0 };
	int colour_pixels{ 0 };
	uint8_t red{ 0 }, green{ 0 }, blue{ 0 };
	double hue{ 0.0 };
	int iterations{ 0 };

	for (int y = 0; y < _height; ++y)
	{
		for (int x = 0; x < _width; ++x)
		{
			iterations = _fractal_data[y * _width + x];

			colour_range = get_colour_range(iterations);
			std::tuple<int, int, int, Rgb> range_info = colour_ranges[colour_range];
			std::tuple<int, int, int, Rgb> next_range_info = colour_ranges[colour_range + 1];
			colour_end_iterations = std::get<1>(range_info);
			colour_start_iterations = std::get<0>(range_info);
			colour_pixels = std::get<2>(range_info);
			Rgb colour = std::get<3>(range_info);

			Rgb next_colour = std::get<3>(next_range_info);

			Rgb start_colour_value = colour;
			Rgb end_colour_value = next_colour;
			Rgb colour_difference = end_colour_value - start_colour_value;

			red = 0;
			green = 0;
			blue = 0;

			if (iterations != _max_iterations)
			{
				hue = 0.0;

				for (int i = colour_start_iterations; i <= iterations; ++i)
					hue += (double)_histogram[i] / _cumulative_histogram[_max_iterations - 1];

				red = start_colour_value.red + colour_difference.red * hue;
				green = start_colour_value.green + colour_difference.green * hue;
				blue = start_colour_value.blue + colour_difference.blue * hue;
			}
			bitmap.set_pixel(x, y, red, green, blue);
		}
	}
}

void Fractal::write_to_bitmap(std::string filename)
{
	bitmap.write(filename);
}
