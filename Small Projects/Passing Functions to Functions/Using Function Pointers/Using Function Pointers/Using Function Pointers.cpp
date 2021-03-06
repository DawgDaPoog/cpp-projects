// Using Function Pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
bool match(std::string test)
{
	return test.size() == 3;
}

int countStrings(std::vector<std::string> &texts, bool(*match)(std::string test)) // custom function with a function pointer
{
	int counter = 0;
	for (std::vector<std::string>::iterator iter = texts.begin();iter != texts.end();iter++) {
		if (match(*iter)) counter++;
	}
	return counter;
}
int main()
{
	std::vector<std::string> texts;
	texts.push_back("One");
	texts.push_back("Two");
	texts.push_back("Three");
	texts.push_back("One");
	texts.push_back("One");
	texts.push_back("Three");
	texts.push_back("Eleven");


	std::cout << std::count_if(texts.begin(), texts.end(), match) << std::endl; // counting the matching strings via count_if
	
	bool (*matchRef)(std::string) = match; // Getting the pointer to a function
	
	std::cout << countStrings(texts, matchRef)<<std::endl; // counting the matching strings via custom function
	system("pause");
    return 0;
}

