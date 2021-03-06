// Sets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>
class Test {
private:

	int id;

	std::string name;
public:

	Test():id(0),name(""){}

	Test(int id, std::string name):id(id), name(name){}

	void print() const
	{
		std::cout << "id: " << id << " - Name: " << name<< std::endl;
	}

	//operator overloading for comparing objects in set
	bool operator<(const Test&other) const
	{
		if(name!=other.name)
			return name < other.name;
		else return id < other.id;
	}

};
int main()
{
	std::set<int> numbers;
	numbers.insert(50);
	numbers.insert(30);
	numbers.insert(109);
	

	//iterating through set
	for (std::set<int>::iterator iter = numbers.begin(); iter != numbers.end();iter++) {
		std::cout << *iter << std::endl;
	}

	
	int intToFind = 109;
	// Finding and anouncing a number from set
	std::set<int>::iterator iterFind = numbers.find(intToFind);
	
	if (iterFind != numbers.end()) {
		std::cout << "Found: " << *iterFind << std::endl;
	}
	else {
		std::cout << "Couldn`t find " << intToFind << std::endl;
	}

	//another way of finding and anouncing
	if (numbers.count(intToFind))
	{
		std::cout << "Number found: " << intToFind<< std::endl;
	}
	else {
		std::cout << "Not found: " << intToFind << std::endl;
	}
	//Using custom class as a variable type for set
	std::set<Test> tests;
	tests.insert(Test(134, "Hue"));
	tests.insert(Test(34, "Sue"));
	tests.insert(Test(124, "Mue"));
	tests.insert(Test(124, "Mue2"));
	tests.insert(Test(127, "Mue"));
	//iterating through set
	for (std::set<Test>::iterator iter = tests.begin(); iter != tests.end();iter++) {
		iter->print();
	}
	system("pause");
    return 0;
}

