// Overloading Plus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Complex.h"

int main()
{
	Complex comp1(3, 6);
	Complex comp2(2, 4);
	Complex comp3;
	comp3=comp1 + comp2;

	std::cout << comp3 <<std::endl;

	std::cout << comp3 + 3 << std::endl;

	std::cout << 4 + comp2 << std::endl;

	std::cout << 4 + comp2 + comp3 + 6 + 3.2 + comp1 << std::endl;
	system("pause");
    return 0;
}

