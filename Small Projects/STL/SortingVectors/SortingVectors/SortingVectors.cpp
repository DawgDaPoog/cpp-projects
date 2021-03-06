// SortingVectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
class Test {
	int id;
	std::string name;

public:
	Test() :id(0), name("") {}

	Test(int id,std::string name) :id(id),name(name) {}

	void print() { std::cout<< id << " : " << name << std::endl; }

	/*bool operator<(const Test&other)const
	{
		return name < other.name;
	}*/

	//friend is allowed to access private members
	friend bool comp(const Test&a, const Test&b);
};
//comparison function for sorting 
bool comp(const Test&a, const Test&b)
{
	return a.name < b.name;
}
int main()
{
	std::vector<Test> tests;

	tests.push_back(Test(13, "John"));
	tests.push_back(Test(78, "Carl"));
	tests.push_back(Test(1, "Mark"));
	tests.push_back(Test(4, "Milo"));

	std::sort(tests.begin(), tests.end(),comp);

	for (int i = 0; i < tests.size();i++) {
		tests[i].print();
	}

	system("pause");
    return 0;
}

