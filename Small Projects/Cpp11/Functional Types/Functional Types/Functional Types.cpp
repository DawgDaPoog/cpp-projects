// Functional Types.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>


bool check(std::string &test) 
{
	return test.size() == 3;
}

class Check {
public:
	bool operator()(std::string &text) //functor
	{
		return text.size() == 5;
	}
} checker;

/*void run(std::function<bool(std::string&)> check,std::string test) 
{
	std::cout << check(test) << std::endl;
}*/
bool run(std::function<bool(std::string&)> check, std::string test) // Function accepting function
{
	std::cout << check(test) << std::endl;
	return check(test);
}
int main()
{
	
	int size = 5;
	std::vector<std::string> vec{ "one", "two", "three" };
	
	int count = std::count_if(vec.begin(), vec.end(), [size](std::string text) {return text.size() == size;}); //count_if taking in lambda expression
	std::cout << count << std::endl;
	std::cout << "-------------------" << std::endl;

	count = std::count_if(vec.begin(), vec.end(), check); // count_if taking in function pointer
	std::cout << count << std::endl;
	std::cout << "-------------------" << std::endl;

	count = std::count_if(vec.begin(), vec.end(), checker); // count_if taking in functor;
	std::cout << count << std::endl;
	std::cout << "-------------------" << std::endl;

	int counter = 0;
	for (auto iter : vec) {
		counter+= run([size](std::string text) {return text.size() == size;}, iter); // Custom function taking in lambda expression
	}
	std::cout << "counter= " <<counter << std::endl;
	std::cout << "-------------------" << std::endl;

	counter = 0;
	for (auto iter : vec) {
		counter += run(check, iter);// Custom function taking in function pointer
	}
	std::cout << "counter= " << counter << std::endl;
	std::cout << "-------------------" << std::endl;

	counter = 0;
	for (auto iter : vec) {
		counter += run(checker, iter); // Custom function taking in functor;
	}
	std::cout << "counter= " << counter << std::endl;
	std::cout << "-------------------" << std::endl;

	std::function<int(int, int)> add = [](int a, int b) {return a + b;};
	std::cout<<add(1, 2)<<std::endl;
	system("pause");
	return 0;
}

