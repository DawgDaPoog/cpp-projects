// Enchanced for Loop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
int main()
{
	auto texts = { "A","B","C" };

	for (auto text : texts) {
		std::cout << text << std::endl;
	}
	std::vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(7);
	num.push_back(134);
	num.push_back(21);
	num.push_back(1);
	for (auto number : num) {
		std::cout << number << std::endl;
	}

	std::string str = "Hello";

	for (auto c : str) {
		std::cout << c << std::endl;
	}


	system("pause");
    return 0;
}

