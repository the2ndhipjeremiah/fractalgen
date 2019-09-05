#pragma once

class Mandelbrot
{
public:
	static int get_iterations(double x, double y, int max_iterations);
	Mandelbrot() {};
	virtual ~Mandelbrot() {};
};

