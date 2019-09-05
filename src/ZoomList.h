#pragma once
#include <vector>

class ZoomList
{
public:
	struct Zoom_info
	{
		int x{ 0 };
		int y{ 0 };
		double scale{ 0.0 };
	};
private:
	std::vector<Zoom_info> _zoom_list;
	int _width{ 0 };
	int _height{ 0 };
	double _x_center{ 0 };
	double _y_center{ 0 };
	double _scale{ 1.0 };

public:
	__forceinline ZoomList(int width, int height) : _width(width), _height(height) {}
	Zoom_info create_zoom(int x, int y, double scale);
	std::pair<double, double> zoom(int x, int y);
	void add(const Zoom_info& zoom);
};

