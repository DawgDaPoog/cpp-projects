// Overloading the Assignment Operator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Test {
private:
	int id;
	std::string name;
public:
	Test() :name(""), id(0) {}
	Test(int id, std::string name) :id(id), name(name){}
	void print() const
	{
		std::cout << id << ": " << name << std::endl;
	}
	//overloading "=" operator
	const Test &operator=(const Test &other) 
	{
		std::cout << "Assignment running"<<std::endl;
		name = other.name;
		return *this;
	}
	//copy constructor
	Test(const Test &other)
	{
		std::cout << "Copy constructor running"<<std::endl;
		id = other.id;
		name = other.name;
	}
};
int main()
{
	Test test1(10, "Sas");
	test1.print();

	Test test2(20, "Bob");

	test2 = test1;
	test2.print();

	Test test3 = test1;
	test3.print();
	system("pause");
    return 0;
}

