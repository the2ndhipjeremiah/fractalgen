#include <iostream>
#include "Bitmap.h"

int main()
{
	const int WIDTH = 1920, HEIGHT = 1080;
	Bitmap test_bitmap = Bitmap(WIDTH, HEIGHT);
	for (int x = 0; x < WIDTH; ++x) 
	{
		for (int y = 0; y < HEIGHT/2; ++y) 
		{
			test_bitmap.set_pixel(x, y, 0, 255, 70);
		}
	}
	test_bitmap.write("test.bmp");
    std::cout << "Done" << std::endl;
}
