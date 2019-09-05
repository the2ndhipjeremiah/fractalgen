#include "Mandelbrot.h"
#include <complex>

int Mandelbrot::get_iterations(double x, double y, int max_iterations)
{
	std::complex<double> z{ 0 };
	std::complex<double> c(x, y);

	int iterations{ 0 };

	while (iterations < max_iterations) 
	{
		z = z * z + c;
		if (std::norm(z) > 2) 
		{
			break;
		}
		++iterations;
	}
	return iterations;
}
