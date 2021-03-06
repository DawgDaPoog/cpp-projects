// Elision and Optimization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <ostream>

/// Memory allocatong lvalues, rvalues
class Test {
private:
	static const int SIZE = 100;
	int *_pBuffer;
public:
	Test()
	{
		std::cout << "constr" << std::endl;
		_pBuffer = new int[SIZE] {};  //allocating memory
		//memset(_pBuffer, 0, sizeof(int)*SIZE);
	}
	Test(int i)
	{
		std::cout << "param constr" << std::endl;
		_pBuffer = new int[SIZE] {};

		for (int i = 0; i < SIZE; i++) {
			_pBuffer[i] = 7 * i;
		}
	}
	Test(const Test&other)
	{
		std::cout << "copy constr" << std::endl;

		_pBuffer = new int[SIZE] {};

		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));

	}
	Test &operator=(const Test &other)
	{
		std::cout << "assign" << std::endl;

		_pBuffer = new int[SIZE] {};

		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
		return *this;
	}
	~Test()
	{
		std::cout << "destructor" << std::endl;
		delete[]_pBuffer;
	}
	friend std::ostream &operator<<(std::ostream &out, const Test &test);
};
std::ostream &operator<<(std::ostream &out, const Test &test)
{
	out << "Hello from test";
	return out;
}

Test getTest()
{
	return Test();
}

void check(const Test &value)
{
	std::cout << "lvalue!" << std::endl;
}
void check(Test &&value)
{
	std::cout << "rvalue!" << std::endl;
}
int main()
{
	Test test = getTest();

	std::cout << test << std::endl;

	Test &ltest1 = test;
	Test &&rtest1 = getTest();

	check(test);
	check(getTest());
	check(Test());

	std::vector<Test> vec;
	vec.push_back(Test());
	system("pause");

    return 0;
}

