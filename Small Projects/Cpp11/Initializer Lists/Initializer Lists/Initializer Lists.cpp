// Initializer Lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <initializer_list>
#include <string>

class Test {
public:
	Test(std::initializer_list<std::string> texts)
	{
		for (auto value : texts) {
			std::cout << value << std::endl;
		}
	}
	void print(std::initializer_list<int> listToPrint)
	{
		for (auto value : listToPrint)
		{
			std::cout << value << std::endl;
		}
	}
};
int main()
{
	std::vector<int> numbers{ 1,3,6,7 };
	std::cout << numbers[2] << std::endl;

	Test test{ "one","dog","banana" };

	test.print({ 6,7,126,7 });

	system("pause");
    return 0;
}

