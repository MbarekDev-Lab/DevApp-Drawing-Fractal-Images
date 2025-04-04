#include <iostream>
#include <cstdint>
#include "Bitmap.h"
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

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS + 1] {0});
    unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT] {0});

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;
            double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

            int iterations = mandelbrot.getIterations(xFractal, yFractal);
            fractal[y * WIDTH + x] = iterations;

            histogram[iterations]++;
        }
    }

    cout << "Histogram: " << endl;

    int maxCount = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        cout << histogram[i] << ", " << flush;
        maxCount += histogram[i];
    }

    cout << min << ", " << max << endl;

    int total = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        total += histogram[i];
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int iterations = fractal[y * WIDTH + x];

            uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

            double hue = 0.0;

            for (int i = 0; i < iterations; i++) {
				hue += (double)histogram[i] / total;
           }
            
            
           // color = color * color * color;
            uint8_t red = red = 0;
            uint8_t green = hue * hue*255;
            uint8_t blue = blue = 0;

            bitmap.setPixel(x, y, red, green, blue);

        }
    }

    bitmap.write("mbarek6.bmp");
    std::cout << "Finished" << std::endl;

    return 0;
}
