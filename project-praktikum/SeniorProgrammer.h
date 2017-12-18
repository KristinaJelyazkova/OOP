#pragma once
#ifndef _SENIORPROGRAMMER_
#define _SENIORPROGRAMMER_

#include"JuniorProgrammer.h"
#include"Tester.h"

class SeniorProgrammer : public Tester, public JuniorProgrammer {
public:
	SeniorProgrammer(std::string = "", std::string = "", std::string = "",
		std::string = "", std::string = "",
		std::string = "", std::string = "", std::string = "");

	void input(std::istream&);
	void print(std::ostream&) const;

	~SeniorProgrammer();
};

#endif