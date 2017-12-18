#pragma once
#ifndef _JUNIORPROGRAMMER_
#define _JUNIORPROGRAMMER_

#include"Employee.h"

class JuniorProgrammer : virtual public Employee {
protected:
	std::string projectName;
public:
	JuniorProgrammer(std::string = "", std::string = "", std::string = "",
		std::string = "", std::string = "", std::string = "", std::string = "junior programmer");

	void setProjectWork(std::string);

	void input(std::istream&);
	void print(std::ostream&) const;

	virtual ~JuniorProgrammer();
};

#endif