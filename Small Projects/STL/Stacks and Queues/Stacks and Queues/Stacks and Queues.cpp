// Stacks and Queues.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>

class Test {
private:

	std::string name;

public:
	Test() :name("") {}

	Test(std::string name) :name(name) {}

	void print() { std::cout << "Name: " << name << std::endl; }
};

int main()
{
	// Stacks
	// last in - first out
	std::stack<Test> testStack;

	testStack.push(Test("Kayle"));
	testStack.push(Test("Mile"));
	testStack.push(Test("Xaye"));
	/*
	//getting the top of the stack
	Test &test1 = testStack.top();
	test1.print();

	//popping off the stack

	Test &test2 = testStack.top();
	testStack.pop(); // poping objects off the stack destroys them.
	test2.print(); // trying to access the destroyed object. Wrong.
	*/
	while (testStack.size() > 0) {
		Test &test = testStack.top();
		test.print();
		testStack.pop();
	}
	std::cout << std::endl;
	
	//Queue
	// First in - First out
	std::queue<Test> testQueue; 
	testQueue.push(Test("Kayle"));
	testQueue.push(Test("Mile"));
	testQueue.push(Test("Xaye"));

	while (testQueue.size() > 0){
	Test &testQ = testQueue.front();
	testQ.print();
	testQueue.pop();
}
	system("pause");
    return 0;
}

