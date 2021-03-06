// Vectors and Memory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>	
#include <vector>

int main()
{
	std::vector<double> numbers(0);
	std::cout << "Size: " << numbers.size() << std::endl;
	int capacity = numbers.capacity();
	std::cout << "Capacity: " << capacity<< std::endl;
	for (int i = 0; i < 1000; i++) {
		if (numbers.capacity() != capacity) {
			capacity = numbers.capacity();
			std::cout << "Capacity: " << capacity << std::endl;;
		}
		numbers.push_back(i);
	}
	std::cout << "------------clear------------------------ " << std::endl;
	numbers.clear();
	std::cout << "Size: " << numbers.size() << std::endl;

	std::cout << "Capacity: " << numbers.capacity() << std::endl;
	std::cout << "-------resize---------------------------- " << std::endl;
	numbers.resize(100);
	std::cout << "Size: " << numbers.size() << std::endl;

	std::cout << "Capacity: " << numbers.capacity() << std::endl;
	std::cout << "-------reserve--------------------------- " << std::endl;
	numbers.reserve(10000);
	std::cout << "Size: " << numbers.size() << std::endl;

	std::cout << "Capacity: " << numbers.capacity() << std::endl;
		system("pause");
    return 0;
}

