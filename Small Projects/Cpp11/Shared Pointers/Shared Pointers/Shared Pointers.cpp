// Shared Pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>

class Test {
public:
	Test()
	{
		std::cout << "created" << std::endl;
	}
	void greet()
	{
		std::cout << "hello" << std::endl;
	}
	~Test()
	{
		std::cout << "destroyed" << std::endl;
	}
};

int main()
{

	std::shared_ptr<Test> pTest2(nullptr);

	std::shared_ptr<Test> pTest1 = std::make_shared <Test> ();

	pTest2 = pTest1;

	std::cout <<"Finish" <<std::endl;

	system("pause");
    return 0;
}

