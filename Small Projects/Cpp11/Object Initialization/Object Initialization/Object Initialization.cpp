// Object Initialization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>

class Test {
	int id{ 0 };
	std::string name{"Name"};
public:
	Test() = default;
	Test(const Test &other) = default;
	Test &operator=(const Test &other) = delete;
	Test(int i):id(i){}
	void print()
	{
		std::cout << id << ": " << name << std::endl;
	}
};

int main()
{
	Test test;
	test.print();

	Test test2(2);
	test2.print();

	Test test3 = test2;
	test3.print();
	//test = test3; We deleted the "=" operator from Test class. This won`t work
	system("pause");
    return 0;
}

