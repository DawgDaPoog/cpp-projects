// Auto Keyword.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
int get()
{
	return 999;
}
auto test2()->decltype(get())
{
	return get();
}
int main()
{
	auto value = 6;
	auto text = "string";
	
	std::cout << value << std::endl;

	std::cout << test2() << std::endl;
    return 0;
}

