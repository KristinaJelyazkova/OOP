#include"Tester.h"


Tester::Tester(std::string _name, std::string _address, std::string _EGN,
	std::string _date, std::string _boss,
	std::string _projectNameTested, std::string _OperatingSystem, std::string position)
	: Employee(_name, _address, _EGN, _date, _boss, position), 
	projectNameTested(_projectNameTested), OperatingSystem(_OperatingSystem) {}

void Tester::input(std::istream& in) {
	Employee::input(in);
	if (in.peek() == '\n') in.ignore();
	std::getline(in, projectNameTested);
	std::getline(in, OperatingSystem);
}

void Tester::print(std::ostream& out) const {
	Employee::print(out);
	out << projectNameTested << '\n'
		<< OperatingSystem << '\n';
}

void Tester::setProjectTest(std::string newProject) {
	projectNameTested = newProject;
}

void Tester::setOS(std::string newOS) {
	OperatingSystem = newOS;
}

Tester::~Tester() {}