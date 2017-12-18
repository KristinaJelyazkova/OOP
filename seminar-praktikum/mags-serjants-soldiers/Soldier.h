#pragma once
#ifndef _SOLDIER_
#define _SOLDIER_

#include<string>

class Soldier {
protected:
	std::string name;
	int age;
	int level;
	int salary;
public:
	Soldier(std::string, int, int, int);
	int getLevel();
	int getSalary();
};


#endif
