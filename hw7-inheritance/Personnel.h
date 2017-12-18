#pragma once
#ifndef _PERSONNEL_
#define _PERSONNEL_

#include"Slujitel.h"
#include<vector>

class Personnel {
private:
	std::vector<Employee*> employees;
public:
	void addEmployee(Employee*);
	void removeEmployeeByName(std::string);
	void removeEmployeeIfInternshipIsLessThan(int);
	std::istream& operator >> (std::istream&);
	std::ostream& operator << (std::ostream&) const;
};

#endif // !_PERSONNEL