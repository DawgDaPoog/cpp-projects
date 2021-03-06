// Maps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
class Person {
private:
	std::string name;
	int age;
public:
	Person(): name(""), age(0) {}
	// Copy constructor
	Person(const Person &other)
	{
		name = other.name;
		age = other.age;
	}
	Person(std::string name, int age):name(name),age(age) {}
	void print() const{
		std::cout << name << ":" << age << std::endl;
	}
	//operator overloading for key comparing in a map
	bool operator<(const Person&other) const {
		if (name == other.name) {
			return age < other.age;
		}
		else {
			return name < other.name;
		}
	}
};
int main()
{
	/// Simeple maps
	std::map<std::string, int> ages;
	ages["Mike"] = 40;
	ages["Jane"] = 26;
	ages["Jaobalot'th"] = 36812;
	std::cout << ages["Jane"] << std::endl;

	//inserting
	std::pair<std::string, int> addToMap("Peter", 100);
	ages.insert(addToMap);
	//another way
	ages.insert(std::make_pair("Zaut'Akar'Nathul", 1530));

	// Checking for a key in the map without accidentally adding it
	if (ages.find("Igor") != ages.end()) {
		std::cout << "Found Igor" << std::endl;
	}
	else std::cout << "Not found" << std::endl;
	// Iterating through elements
	for (std::map<std::string, int>::iterator iter = ages.begin(); iter != ages.end();iter++) {
		std::cout << iter->first << ":" << iter->second << std::endl;
	}
	std::cout << std::endl;
	//another way
	for (std::map<std::string, int>::iterator iter = ages.begin(); iter != ages.end();iter++) {
		std::pair<std::string, int>age = *iter;

		std::cout << age.first << ":" << age.second << std::endl;
	}
	std::cout << std::endl;

	/// Implementing maps with custom objects in them

	std::map<int, Person> People;

	People[0] = Person("John Wick", 29);
	People[1] = Person("Father Grigori", 40);
	People[3] = Person("Ainz Ool Gown", 24);
	People.insert(std::make_pair(4, Person("Amon", 2018)));
	People.erase(0);
	for (std::map<int, Person>::iterator iter = People.begin(); iter != People.end();iter++) {
		iter->second.print();
	}

	/// Custom objects as map keys
	std::map<Person, int> PeopleKey;
	PeopleKey[Person("John", 31)] = 1;
	PeopleKey[Person("drunk Father Grigori", 40)] = 2;
	PeopleKey[Person("drunk Father Grigori", 20)] = 221;
	PeopleKey[Person("Ainz Ool Gown", 24)]= 3;

	for (std::map<Person, int>::iterator iter = PeopleKey.begin(); iter != PeopleKey.end();iter++) {
		std::cout << iter->second<<" "<<std::flush;
		iter->first.print();
		
	}
	system("pause");
    return 0;
}

