#include <iostream>
#include "Fractal.h"

int main()
{
	Fractal fractal = Fractal(3840, 2160, 1000);
	fractal.zoom_in(1800, 350, 0.1);
	fractal.zoom_in(946, 564, 0.1);
	fractal.compute();
	fractal.add_colour_range(0.00, 0.12, Rgb(0, 0, 0));
	fractal.add_colour_range(0.12, 0.13, Rgb(127, 0, 100));
	fractal.add_colour_range(0.13, 0.15, Rgb(147, 0, 120));
	fractal.add_colour_range(0.15, 0.2, Rgb(200, 100, 150));
	fractal.add_colour_range(0.2, 1.0, Rgb(225, 200, 220));
	fractal.add_colour_range(1.0, 1.0, Rgb(255, 255, 255));
	fractal.draw();
	fractal.write_to_bitmap("fractal.bmp");
	std::cout << "Done" << std::endl;
}
