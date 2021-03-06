// Parsing Text Files.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>	
#include <fstream>
#include <string>

int main()
{
	std::string filename = "stats.txt";
	std::ifstream input;
	input.open(filename);

	if (!input.is_open()) {
		return 1;
	}
	while (input) {
		std::string line;
		std::getline(input, line, ':');

		int population;
		input >> population;

		if (!input) {
			break;
		}
		std::cout << line << ":-" << population << std::endl;
		input >> std::ws; // Discarding the additional non-printed line to eliminate a bug
	}
	input.close();
	system("pause");
    return 0;
}

