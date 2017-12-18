#pragma once
#ifndef _PROGRAMMER_
#define _PROGRAMMER_

#include"Slujitel.h"

class Programmer : public Employee {
private:
	bool knowsCplusplus;
	bool knowsCsharp;
	static int dummy;
	static int registerClass();
public:
	Programmer(bool = false, bool = false, std::string = "", int = 0);
	void save(std::ostream &out);
	void load(std::istream &in);
	Employee* spawn();
};

#endif // !_PROGRAMMER_
