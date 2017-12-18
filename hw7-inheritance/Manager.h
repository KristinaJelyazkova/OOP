#pragma once
#ifndef _MANAGER_
#define _MANAGER_

#include"Slujitel.h"

class Manager : public Employee {
private:
	int inferiors;
	static int dummy;
	static int registerClass();
public:
	Manager(int = 0, std::string = "", int = 0);
	void save(std::ostream &out);
	void load(std::istream &in);
	Employee* spawn();
};

#endif // !_MANAGER_

