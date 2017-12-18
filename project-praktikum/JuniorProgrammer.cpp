#include"JuniorProgrammer.h"


JuniorProgrammer::JuniorProgrammer(std::string _name, std::string _address, std::string _EGN,
	std::string _date, std::string _boss,  std::string _projectName, std::string position)
	: Employee(_name, _address, _EGN, _date, _boss, position), projectName(_projectName) {}

void JuniorProgrammer::setProjectWork(std::string newName) {
	projectName = newName;
}

void JuniorProgrammer::input(std::istream& in) {
	Employee::input(in);
	if (in.peek() == '\n') in.ignore();
	std::getline(in, projectName);
}

void JuniorProgrammer::print(std::ostream& out) const {
	Employee::print(out);
	out << projectName << '\n';
}

JuniorProgrammer::~JuniorProgrammer() {}