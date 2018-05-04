// Fractal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdint>
#include <iostream>
#include <ctime>
#include "FractalCreator.h"
#include "Zoom.h"



int main()
{
	

	//initialising 
	int resolutionScale = 5;
	int const WIDTH = resolutionScale*800;
	int const HEIGHT = resolutionScale*600;
	std::string name = "test.bmp";

	
	FractalCreator fractalCreator(WIDTH,HEIGHT);

	
	
	std::cout << "Starting." << std::endl;
	///adding color ranges

	//full random color Range
	/*
	srand(time(NULL));
	for (double i = 1;i <= 500;i += 1) {
		fractalCreator.addColorRange(i/500, RGB((int)((rand() * (int)(255) / RAND_MAX)), (int)((rand() * (int)(255) / RAND_MAX)), (int)(rand() * (int)(255) / RAND_MAX)));
	}
	*/

	// Chunky color destribution
	/*
	fractalCreator.addColorRange(0.0, RGB(0, 0, 0));
	fractalCreator.addColorRange(0.05, RGB(0,100, 200));
	fractalCreator.addColorRange(0.15, RGB(100, 200 , 200));
	fractalCreator.addColorRange(1.0, RGB(100 ,255, 255));
	*/

	//Color Gradient
	int Frequency = 2000;
	double softRange = 27 * 4; // First couple iterations that are supposed to be blacked out
	int HardEnd = 500; // Upper line for most iterations. Color should be most prominent untill this point. After that coloring is very dull.

	int rColorBegin = 0;
	int rColorEndSoft = 100;
	int rColorEndHard = 255;

	int gColorBegin = 0;
	int gColorEndSoft = 100;
	int gColorEndHard = 255;

	int bColorBegin = 0;
	int bColorEndSoft = 255;
	int bColorEndHard = 255;

	fractalCreator.addColorRange(0.0, RGB(0, 0, 0));
	fractalCreator.addColorRange(softRange / Frequency, RGB(rColorBegin, gColorBegin, bColorBegin));
	for (double i = softRange + 1;i <= HardEnd;i += 1) {
		fractalCreator.addColorRange(i / Frequency, RGB((rColorBegin + (rColorEndSoft - rColorBegin)*(i / Frequency)), gColorBegin + (gColorEndSoft - gColorBegin)* (i / Frequency), bColorBegin + (bColorEndSoft - bColorBegin)* (i / Frequency)));
	}
	for (double i = HardEnd + 1; i <= Frequency;i += 1) {
		fractalCreator.addColorRange(i / Frequency, RGB((rColorEndSoft + (rColorEndHard - rColorEndSoft)*(i / Frequency)), gColorEndSoft + (gColorEndHard - gColorEndSoft)* (i / Frequency), bColorEndSoft + (bColorEndHard - bColorEndSoft)* (i / Frequency)));
	}

	//adding zoom
	fractalCreator.addZoom(Zoom(WIDTH / 2, HEIGHT / 2, 4.0 / WIDTH));
	fractalCreator.addZoom(Zoom(resolutionScale * 470, resolutionScale * 299, 0.05));
	fractalCreator.addZoom(Zoom(resolutionScale * 61, resolutionScale * 319, 0.1));
	fractalCreator.addZoom(Zoom(resolutionScale * 18, resolutionScale * 307, 0.2));
	fractalCreator.addZoom(Zoom(resolutionScale *680, resolutionScale * 131, 0.5));
	fractalCreator.addZoom(Zoom(resolutionScale * 518, resolutionScale * 254, 0.1));
	fractalCreator.addZoom(Zoom(resolutionScale * 494, resolutionScale * 303, 0.5));
	//run
	fractalCreator.run(name);

    return 0;
}

