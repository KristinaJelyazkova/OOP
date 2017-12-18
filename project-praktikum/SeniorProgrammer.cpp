#include"SeniorProgrammer.h"


SeniorProgrammer::SeniorProgrammer(std::string _name, std::string _address, std::string _EGN,
	std::string _date, std::string _boss, 
	std::string _projectNameTested, std::string _OperatingSystem, std::string _projectName)
	: Employee(_name, _address, _EGN, _date, _boss, "senior programmer"), 
	Tester(_name, _address, _EGN, _date, _boss, _projectNameTested, _OperatingSystem, "senior programmer"),
	JuniorProgrammer(_name, _address, _EGN, _date, _boss, _projectName, "senior programmer") {}

void SeniorProgrammer::input(std::istream& in) {
	Tester::input(in);
	if (in.peek() == '\n') in.ignore();
	std::getline(in, projectName);
}

void SeniorProgrammer::print(std::ostream& out) const {
	Tester::print(out);
	out << projectName << '\n';
}

SeniorProgrammer::~SeniorProgrammer() {}