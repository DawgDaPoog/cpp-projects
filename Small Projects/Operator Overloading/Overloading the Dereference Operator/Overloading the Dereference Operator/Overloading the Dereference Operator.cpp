// Overloading the Dereference Operator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Complex.h"

int main()
{
	Complex comp1(5, 1);

	std::cout << *comp1 + Complex(-6,1) +3 << std::endl;
	system("pause");
    return 0;
}

