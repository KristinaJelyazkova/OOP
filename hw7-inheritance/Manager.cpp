#include"Manager.h"

Manager::Manager(int _inf, std::string _name, int _internship) :
	Employee(_name, _internship), inferiors(_inf) {}

void Manager::save(std::ostream &out) {
	out << "manager "
		<< name << " "
		<< internship << " "
		<< inferiors << " ";
}

void Manager::load(std::istream &in) {
	in >> name
		>> internship
		>> inferiors;
}

Employee* Manager::spawn() {
	return new Manager;
}

int Manager::dummy = Manager::registerClass();
int Manager::registerClass()
{
	Employee::addEmployeeType("manager", new Manager(0, 0, 0));
	return -1;
}