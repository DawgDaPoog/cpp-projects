// Lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

int main()
{
	std::list<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);

	for (std::list<int>::iterator iter = numbers.begin(); iter != numbers.end();iter++) {
		std::cout << *iter << std::endl;
	}

	// Inserting
	std::list<int>::iterator iter = numbers.begin();
	iter++;
	std::cout << "Elem: " << *iter << std::endl;
	numbers.insert(iter, 100);

	for (std::list<int>::iterator iter = numbers.begin(); iter != numbers.end();iter++) {
		std::cout << *iter << std::endl;
	}

	// Erasing
	std::list<int>::iterator iterErase = numbers.begin();
	iterErase++;
	std::cout << "Elem to erase: " << *iterErase << std::endl;
	iterErase = numbers.erase(iterErase);
	std::cout << "Iterator after erase: " << *iterErase << std::endl;


	// adding 1234 after a number 2
	for (std::list<int>::iterator iter = numbers.begin(); iter != numbers.end();iter++) {
		if (*iter == 2) {
			numbers.insert(iter, 1234);
		}
	}

	for (std::list<int>::iterator iter = numbers.begin(); iter != numbers.end();iter++) {
		std::cout << *iter << std::endl;
	}
	system("pause");
    return 0;
}

