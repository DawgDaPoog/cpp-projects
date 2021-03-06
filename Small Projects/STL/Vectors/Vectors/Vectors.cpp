// Vectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <exception>
#include <iostream>

int main()
{
	std::vector<std::string> strings;
	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");

	// iterating through all vector variables
	for (std::vector<std::string>::iterator iter = strings.begin();iter != strings.end(); iter++) {
		std::cout << *iter << std::endl;
	}
	
	std::vector<int> intVector;
	for (int i = 0;i < 9;i++) {
		intVector.push_back(i);
	}
	// wrong way of iterating through vectors
	for (int i = 0;i < intVector.size(); i++) {
		std::cout << "intVector " << i << "= " << intVector[i]<<std::endl;
	}
	//proper way
	for (std::vector<int>::iterator iterator = intVector.begin(); iterator != intVector.end();iterator++) {
		std::cout << *iterator << std::endl;
}
	system("pause");
    return 0;
}

