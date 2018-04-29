// Decltype, Typeid, Name Mangling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <typeinfo>
int main()
{
	std::string i;

	std::cout << typeid(i).name() << std::endl;

	decltype(i) name;

	std::cout << typeid(name).name() << std::endl;
	system("pause");
    return 0;
}

