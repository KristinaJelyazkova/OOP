#pragma once
#ifndef _SLUJITEL_
#define _SLUJITEL_

#include <string>

class Employee;

struct NameAndPointerPair
{
	std::string employeeType;
	Employee* hollowEmployee;

	NameAndPointerPair(std::string et, Employee* he) : employeeType(et), hollowEmployee(he) {}

};

class Employee {
private:
	static std::vector<NameAndPointerPair> allEmployeeTypes;
protected:
	std::string name;
	int internship;
	static void addEmployeeType(std::string, Employee*);
public:
	Employee(std::string = "", int = 0);
	std::string getName();
	int getInternship();
	virtual void save(std::ostream &out) = 0;
	virtual void load(std::istream &in) = 0;
	static Employee* factory(std::string);
	virtual Employee* spawn() = 0;
};

#endif // !_SLUJITEL_

