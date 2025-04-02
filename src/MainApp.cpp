#include<iostream>
#include<cstdint>
#include"Bitmap.h"
#include "Mandelbrot.h"

using namespace caveofprogramming;
using namespace std;

int main()
{
	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);
	Mandelbrot mandelbrot;
	double min = 999999;
	double max = -999999;

	//bitmap.setPixel(WIDTH / 2, 100, 255, 255, 255);

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			//bitmap.setPixel(x, y, 0, 0, 255);// blue
			//bitmap.setPixel(x, y, 255, 0, 0); // Set the color to red
			double xFractal = (x - WIDTH / 2) * 2.0 / WIDTH;
			double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

			int iterations = mandelbrot.getIterations(xFractal, yFractal);
			uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

			color = color * color * color;

			bitmap.setPixel(x, y, color, 0, 0);

			if (xFractal < min) min = xFractal;
			if (xFractal > max) max = xFractal;
		}
	}
	cout << min << ", " << max << endl;

	bitmap.write("mbarek2.bmp");
	std::cout << "Finished" << std::endl;

	return 0;
}