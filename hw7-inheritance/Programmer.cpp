#include"Programmer.h"

Programmer::Programmer(bool _Cplus, bool _Csharp, std::string _name, int _internship) :
	Employee(_name,_internship), knowsCplusplus(_Cplus), knowsCsharp(_Csharp) {}

void Programmer::save(std::ostream &out) {
	out << "programmer " 
		<< name << " "
		<< internship << " " 
		<< knowsCplusplus << " " 
		<< knowsCplusplus << " ";
}

void Programmer::load(std::istream &in) {
	in >> name
		>> internship 
		>> knowsCplusplus 
		>> knowsCplusplus;
}

Employee* Programmer::spawn() {
	return new Programmer;
}

int Programmer::dummy = Programmer::registerClass();
int Programmer::registerClass()
{
	Employee::addEmployeeType("programmer", new Programmer(0, 0, 0));
	return -1;
}