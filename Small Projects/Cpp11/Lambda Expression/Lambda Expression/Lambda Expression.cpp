// Lambda Expression.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void test(void (*pFunc)()){
	pFunc();
}

int main()
{
	auto func =[]() {std::cout << "Sup" << std::endl;};

	func();
	test(func);

	auto func2 = []() {std::cout << "func2" << std::endl;};

	test(func2);

	test([]() {std::cout << "pure lambda call" << std::endl;});
	system("pause");
    return 0;
}

