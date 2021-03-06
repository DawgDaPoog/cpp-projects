// Capturing this in Lambda.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Test {
private:
	int one{ 1 };
	int two{ 2 };
public:
	void run()
	{
		int three{ 3 };
		int four{ 4 };

		auto pLamp = [this, three, four]() {std::cout << three << four << one << std::endl;};
		pLamp();
	}
};

int main()
{
	Test test;
	test.run();


	system("pause");
    return 0;
}

