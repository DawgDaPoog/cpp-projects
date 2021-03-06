// Object Slicing and Polymorphism.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Parent {
private:
	int i1;
public:
	Parent():i1(0){}
	Parent(const Parent &other):i1(0)
	{
		i1 = other.i1;
		std::cout << "Copy parent" << std::endl;
	}
	virtual void print()
	{
		std::cout << "parrent speaking" << std::endl ;
	}


};
class Child: public Parent {
private:
	int i2;
public:
	Child():i2(0){}
	Child(const Child &other):i2(0)
	{
		std::cout << "Copy child" << std::endl;
	}
	void print() override
	{
		
		std::cout << "child speaking" << std::endl;
	}
};
int main()
{
	Child c1;
	Parent &p1 = c1;
	
	p1.print();
	c1.print();

	Parent p2 = Child(); // up-casting
	p2.print();


	system("pause");
    return 0;
}

