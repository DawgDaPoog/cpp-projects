// Initialisation Cpp11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
	int value{ 5 };
	std::cout << value << std::endl;

	std::string text{"Hi"};
	std::cout << text << std::endl;

	int *pInts = new int[3] {1, 2, 3};
	std::cout << pInts[1] << std::endl;
	delete pInts;

	int value1{};
	std::cout << value1 << std::endl;

	int *pSmth{}; // nullptr
	std::cout << pSmth << std::endl;

	int numbers2[5]{};
	std::cout << numbers2[1] << std::endl;

	struct {
		int value;
		std::string text;
	}s = {5, "Sup"};
	std::cout << s.text << std::endl;

	std::vector<std::string> strings{"uno","dos","tres"};
	std::cout << strings[2] << std::endl;

	system("pause");
    return 0;
}

