#include"Slujitel.h"
#include<vector>

Employee::Employee(std::string _name, int _internship) :
	name(_name), internship(_internship) {}

std::string Employee::getName() {
	return name;
}

int Employee::getInternship() {
	return internship;
}

Employee* Employee::factory(std::string type) {
	for (int i = 0; i < allEmployeeTypes.size(); i++)
	{
		if (allEmployeeTypes[i].employeeType == type)
			return allEmployeeTypes[i].hollowEmployee->spawn();
	}
}

std::vector<NameAndPointerPair> Employee::allEmployeeTypes;


void Employee::addEmployeeType(std::string typeName, Employee *emp)
{
	allEmployeeTypes.push_back(NameAndPointerPair(typeName, emp));
}