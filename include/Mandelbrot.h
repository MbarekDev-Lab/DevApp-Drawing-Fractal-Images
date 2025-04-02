#pragma once

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

class Mandelbrot {
public:
    static const int MAX_ITERATIONS = 1000;

    Mandelbrot();
    ~Mandelbrot();

    int getIterations(double x, double y);

private:

};

#endif /* MANDELBROT_H_ */
