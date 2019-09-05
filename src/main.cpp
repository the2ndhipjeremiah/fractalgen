#include <iostream>
#include "Fractal.h"

int main()
{
	Fractal fractal = Fractal(800, 600, 1000);
	fractal.zoom_in(378, 125, 0.025);
	fractal.compute();
	fractal.add_colour_range(0.0, 0.3, Rgb(0, 0, 100));
	fractal.add_colour_range(0.3, 1.0, Rgb(100, 100, 255));
	fractal.add_colour_range(1.0, 1.0, Rgb(255, 255, 255));
	fractal.draw();
	fractal.write_to_bitmap("fractal.bmp");
    std::cout << "Done" << std::endl;
}
