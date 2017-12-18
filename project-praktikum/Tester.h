#pragma once
#ifndef _TESTER_
#define _TESTER_

#include"Employee.h"

class Tester : virtual public Employee {
protected:
	std::string projectNameTested;
	std::string OperatingSystem;
public:
	Tester(std::string = "", std::string = "", std::string = "",
		std::string = "", std::string = "", 
		std::string = "", std::string = "", std::string = "tester");

	void input(std::istream&);
	void print(std::ostream&) const;

	void setProjectTest(std::string);
	void setOS(std::string);

	virtual ~Tester();
};

#endif