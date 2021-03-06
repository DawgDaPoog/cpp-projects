// Unique Pointers.cpp : Defines the entry point for the console application.
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

class Temp {
private:
	std::unique_ptr<Test[]> pTest;
public:
	Temp():pTest(new Test[2]){}
};
int main()
{
	std::unique_ptr<Test> gTest(new Test);

	gTest->greet();


	Temp temp;

	system("pause");
    return 0;
}

