#include"Slujitel.h"
#include"Programmer.h"
#include"Manager.h"
#include"Personnel.h"

#include<iostream>
#include<fstream>

int main() {
	Employee *employees[] = {
		new Programmer(true, false, "Ivan Hankov", 2),
		new Manager(23, "Katerina Nikolova", 4),
		new Programmer(true, true, "Kristina Zhelyazkova", 10),
		new Programmer(false, false, "Ivo Mihov", 15),
		new Manager(17, "Dora Angelova", 1),
		new Programmer(false, true, "Angel Todorov", 7),
		new Manager(34, "Ryan Reynolds", 1),
		new Manager(19, "Tara Reid", 13)
	};

	Personnel Firma;

	for (int i = 0; i < 8; i++) {
		Firma.addEmployee(employees[i]);
	}

	std::string FILE_NAME = "ProgrammerAndManagers.txt";
	std::ostream out(FILE_NAME);

	out << Firma;

	Personnel otherFirma;
	std::istream in(FILE_NAME);

	in >> otherFirma;
	cout << otherFirma;


	system("pause");
	return 0;
}