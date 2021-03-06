// STL Complex Data Types.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
int main()
{
	//map of vectors
	std::map<std::string, std::vector<int>> scores;

	scores["Mike"].push_back(10);
	scores["Mike"].push_back(20);
	scores["Mike"].push_back(10);
	scores["Jake"].push_back(10);

	for (std::map<std::string, std::vector<int>>::iterator iter = scores.begin();iter != scores.end();iter++) {
		std::string name = iter->first;
		std::vector<int> scoreList = iter->second;
		std::cout << name << std::endl;
		for (std::vector<int>::iterator iterVec = scoreList.begin(); iterVec != scoreList.end();iterVec++) {
			std::cout << *iterVec<<std::endl;
		}
	}
	system("pause");
	return 0;
}

