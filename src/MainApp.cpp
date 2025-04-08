
#include <iostream>

#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"

using namespace std;
using namespace caveofprogramming;

int main() {
	FractalCreator fractalCreator(800, 600);

	/*
	fractalCreator.addRange(0.0, RGB(5, 10, 15));
	fractalCreator.addRange(0.3, RGB(100, 0, 100));
	fractalCreator.addRange(0.5, RGB(100, 100, 0));
	fractalCreator.addRange(1.0, RGB(100, 100, 100));
	*/

	fractalCreator.addRange(0.0, RGB(10, 0, 0));
	fractalCreator.addRange(0.3, RGB(150, 0, 0));
	fractalCreator.addRange(0.2, RGB(150, 0, 0));
	fractalCreator.addRange(1.0, RGB(25, 0, 0));


	// testing rang 
	cout <<" getRange :  " << fractalCreator.getRange(999) << endl;

	fractalCreator.addZoom(Zoom(295, 202, 0.1));
	fractalCreator.addZoom(Zoom(312, 304, 0.1));
	fractalCreator.run("testBitmap.bmp");

	cout << "Finished." << endl;
	return 0;
}
