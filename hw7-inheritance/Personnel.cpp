#include"Personnel.h"

void Personnel::addEmployee(Employee* employee) {
	employees.push_back(employee);
}

void Personnel::removeEmployeeByName(std::string _name) {
	int size = employees.size();
	for (int i = 0; i < size; i++) {
		if (employees[i]->getName() == _name) {
			employees.erase(employees.begin() + i);
		}
	}
}

std::istream& Personnel::operator >> (std::istream& in) {
	int size;
	in >> size;
	std::string type;

	for (int i = 0; i < size; i++) {
		in >> type;
		Employee *newEmployee = Employee::factory(type);
		newEmployee->load(in);
		employees.push_back(newEmployee);
	}
}


std::ostream& Personnel::operator << (std::ostream& out) const{
	int size = employees.size();
	out << size << " ";
	for (int i = 0; i < size; i++) {
		employees[i]->save(out);
	}
}

void Personnel::removeEmployeeIfInternshipIsLessThan(int _internship) {
	int size = employees.size();
	for (int i = 0; i < size; i++) {
		if (employees[i]->getInternship() < _internship) {
			employees.erase(employees.begin() + i);
		}
	}
}