#include<iostream>
#include"Bitmap.h"

using namespace caveofprogramming;
using namespace std;

int main()
{
	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	//bitmap.setPixel(WIDTH / 2, 100, 255, 255, 255);

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			bitmap.setPixel(x, y, 0, 0, 255);
		}
	}

	bitmap.write("mbarek.bmp");

	std::cout << "Finished" << std::endl;

	return 0;
}