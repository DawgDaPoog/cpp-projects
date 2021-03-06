// Delegating Constructors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Parent {
private:
	int dogs{5};
	std::string text{"Hello"};
public:
	Parent() :Parent("Hello") // delegatin constructor
	{
		std::cout << "No param parent constructor" << std::endl;
	}
	Parent(std::string text)
	{
		this->text = text;
		std::cout << "string parent constructor" << std::endl;
	}
};
class Child :public Parent {
public:
	Child() = default;
};
int main()
{
	Parent parent;
	Child child;

	system("pause");
    return 0;
}

