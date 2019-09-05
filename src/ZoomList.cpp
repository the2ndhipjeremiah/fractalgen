#include "ZoomList.h"

void ZoomList::add(const Zoom_info& zoom)
{
	_zoom_list.push_back(zoom);
	_x_center += ((double)zoom.x - _width / 2) * _scale;
	_y_center += ((double)zoom.y - _height / 2) * _scale;
	_scale *= zoom.scale;
}

std::pair<double, double> ZoomList::zoom(int x, int y)
{
	double x_fractal = ((double)x - _width / 2.0) * _scale + _x_center;
	double y_fractal = ((double)y - _height / 2.0) * _scale + _y_center;

	return std::pair<double, double>(x_fractal, y_fractal);
}

ZoomList::Zoom_info ZoomList::create_zoom(int x, int y, double scale)
{
	Zoom_info zoom;
	zoom.x = x;
	zoom.y = y;
	zoom.scale = scale;
	return zoom;
}

