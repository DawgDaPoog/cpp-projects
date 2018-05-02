// Fractal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdint>
#include <iostream>
#include <cmath>
#include <memory>
#include "Bitmap.h"
#include "Mandelbrot.h"

int main()
{
	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH,HEIGHT);

	double min = 9999999;
	double max = -9999999;

	std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{ 0 });
	std::unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]);
	
	std::cout << "In process." << std::endl;
	//executing and storing amount of Mandelbrot iterations
	for (int iHeight = 0;iHeight < HEIGHT;iHeight++) {
		for (int iWidth = 0; iWidth < WIDTH;iWidth++)
		{
			double xFractal = (iWidth - WIDTH / 2 - (WIDTH - HEIGHT)) * 2.0 / WIDTH;
			double yFractal = (iHeight - HEIGHT / 2) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				histogram[iterations]++;
				
			}
			fractal[iHeight*WIDTH + iWidth] = iterations;
		}
	}

	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS;i++) {
		total += histogram[i];
	}

	//writing to bitmap
	for (int iHeight = 0;iHeight < HEIGHT;iHeight++) {
		for (int iWidth = 0; iWidth < WIDTH;iWidth++)
		{
			int iterations = fractal[iHeight*WIDTH + iWidth];
			
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {

				double hue = 0.0;

				for (int i = 0; i <= iterations; i++) {
					hue += ((double)histogram[i]) / total;
				}

				red = (uint8_t)std::pow(255,  hue);
				green = (uint8_t)std::pow(255, 1/hue);
				if(hue>=0.5)
				blue = (uint8_t)std::pow(2*255, hue);
				else
				blue = (uint8_t)std::pow(2 * 255, 1/hue);
			}
		
			
			bitmap.setPixel(iWidth, iHeight, red, green, blue);
		}
	}
	

	//Drawing in file
	bitmap.write("test.bmp");
	std::cout <<"Finished."<< std::endl;
	system("pause");
    return 0;
}

