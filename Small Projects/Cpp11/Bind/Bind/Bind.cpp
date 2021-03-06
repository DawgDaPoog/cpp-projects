// Bind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <functional>

class Test {
public:
	int add(int a, int b, int c)
	{
		std::cout << a << ", " << b << ", " << c << std::endl;
		return a + b + c;
	}
};

int add(int a, int b, int c)
{
	std::cout << a << ", " << b << ", " << c << std::endl;
	return a + b + c;
}

int run(std::function<int(int, int)> func) 
{
	return func(7, 3);
}
int main()
{
	int a = 5;
	int b = 4;
	int c = 5;


	auto sum = std::bind(add, std::placeholders::_1 , std::placeholders::_2, std::placeholders::_3);
	std::cout<<sum(a,b,c)<<std::endl;



	auto sum2 = std::bind(add, std::placeholders::_1, 100, std::placeholders::_2);
	std::cout << run(sum2)<< std::endl;


	Test obj;
	auto sum3 = std::bind(&Test::add, obj, std::placeholders::_1, 50, std::placeholders::_2);
	std::cout << run(sum3) << std::endl;
	
	system("pause");
    return 0;
}

