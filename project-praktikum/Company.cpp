#include"Company.h"
#include<iostream>
#include<fstream>


Company::Company(std::string _name, std::string _address, std::string _EGN,
	std::string _date, std::string _companyName, std::string _companyAddress)
	: CEO(_name, _address, _EGN, _date, "no boss", "CEO"),
	companyName(_companyName), companyAddress(_companyAddress) {}

void Company::inputFromKeyboard() {
	std::cout << "Enter CEO information - full name, address, EGN, date of starting the job, boss name and team number(in this order!). The CEO is not in a team so the team number will be set to 0.\n";
	std::cin.ignore();
	CEO.input(std::cin);
	CEO.setTeamNumber(0);
	std::cout << "Enter name of the company.\n";
	std::cin.ignore();
	std::getline(std::cin, companyName);
	std::cout << "Enter address of the company.\n";
	std::getline(std::cin, companyAddress);
}

void Company::output() const {
	std::cout << "CEO information - full name, address, EGN and date of starting the job:\n";
	CEO.print(std::cout);
	std::cout << "The name of the company is " << companyName << '\n'
		<< "The address of the company is " << companyAddress << '\n';
}

bool Company::isTeamLeader(std::string name) const{
	int size = numberOfTeams();
	for (int i = 0; i < size; i++) {
		if (teams[i].getLeaderName() == name) return true;
	}
	return false;
}

bool Company::isEmployee(std::string name) const {
	int size = numberOfEmployees();
	for (int i = 0; i < size; i++) {
		if (employees[i]->getName() == name) return true;
	}
	return false;
}

void Company::AddEmployee(Employee *newEmployee) {
	employees.push_back(newEmployee);
}

int Company::numberOfEmployees() const {
	return employees.size();
}

bool Company::printEmployeeBy(std::string EGN) const {
	int size = numberOfEmployees();
	for (int i = 0; i < size; i++) {
		if (employees[i]->getEGN() == EGN) {
			employees[i]->print(std::cout);
			return true;
		}
	}
	return false;
}

bool Company::deleteEmployeeBy(std::string name) {
	int size = numberOfEmployees();
	Employee *toBeFired;
	for (int i = 0; i < size; i++) {
		if (employees[i]->getName() == name) {
			toBeFired = employees[i];
			employees.erase(employees.begin() + i);
			if (isTeamLeader(name)) {
				int teamNumber = toBeFired->getTeamNumber();
				std::cout << "You fired the leader of team with ID number " << teamNumber << std::endl
					<< "You have to enter the name of the new leader of this team: ";
				std::string newLeaderName;
				if (std::cin.peek() == '\n') std::cin.ignore();
				std::getline(std::cin, newLeaderName);
				while (!isEmployee(newLeaderName) || isTeamLeader(newLeaderName)) {
					std::cout << "This person is not an existing employee or is already a team leader!\n";
					std::cout << "Enter new leader name: ";
					if (std::cin.peek() == '\n') std::cin.ignore();
					std::getline(std::cin, newLeaderName);
				}
				changeLeader(teamNumber, newLeaderName);
				changeTeamNumberOf(newLeaderName, teamNumber);
			} 
			for (int k = 0; k < size - 1; k++) {	// if someone's boss is fired
				if (employees[k]->getBoss() == name) {
					employees[k]->setBoss("no boss");
				}
			}
			delete toBeFired;
			return true;
		}
	}
	return false;
}

bool Company::printByPosition(std::string position) const {
	int size = numberOfEmployees();
	bool exist = false;
	for (int i = 0; i < size; i++) {
		if (employees[i]->getPosition() == position) {
			employees[i]->print(std::cout);
			exist = true;
		}
	}
	return exist;
}

bool Company::ChangeInfoEmployee(std::string name, int number, std::string newInfo) {
	int size = numberOfEmployees(), index = -1;
	bool flag = true;
	for (int i = 0; i < size && flag; i++) {
		if (employees[i]->getName() == name) {
			index = i;
			flag = false;
		}
	}
	if (index == -1) return false;
	switch (number) {
	case 1: {
		employees[index]->setAddress(newInfo);
		break;
	}
	case 2: {
		employees[index]->setBoss(newInfo);
		break;
	}
	case 3: {
		if (employees[index]->getPosition() != "junior programmer" &&
			employees[index]->getPosition() != "senior programmer")
			return false;
		employees[index]->setProjectWork(newInfo);
		break;
	}
	case 4: {
		if (employees[index]->getPosition() != "tester" &&
			employees[index]->getPosition() != "senior programmer")
			return false;
		employees[index]->setProjectTest(newInfo);
		break;
	}
	case 5: {
		if (employees[index]->getPosition() != "tester" &&
			employees[index]->getPosition() != "senior programmer")
			return false;
		employees[index]->setOS(newInfo);
		break;
	}
	default: return false;
	}
	return true;
}

void Company::AddTeam(Team team) {
	teams.push_back(team);
}

int Company::numberOfTeams() const {
	return teams.size();
}

void Company::changeTeamNumberOf(std::string name, int newTeamNumber) {
	int size = numberOfEmployees();
	for (int i = 0; i < size; i++) {
		if (employees[i]->getName() == name) {
			employees[i]->setTeamNumber(newTeamNumber);
			return;
		}
	}
}

bool Company::deleteTeamBy(int IDnumber) {
	int size = numberOfTeams();
	bool found = false;
	for (int i = 0; i < size && !found; i++) {
		if (teams[i].getIDnumber() == IDnumber) {
			teams.erase(teams.begin() + i);
			found = true;
		}
	}
	if (!found) return false;
	size = numberOfEmployees();
	int newID;
	for (int i = 0; i < size; i++) {
		if (employees[i]->getTeamNumber() == IDnumber) {
			std::cout << "Enter the ID number of the team you want to put " << employees[i]->getName() << " in: ";
			if (std::cin.peek() == '\n') std::cin.ignore();
			std::cin >> newID;
			while (!isTeamNumber(newID)) {
				std::cout << "The team number you entered does not exist! You have to add the employee to an existing team - the team number of the employee should be one of the ID numbers of the existing teams.\n";
				std::cout << "Enter new team number: ";
				if (std::cin.peek() == '\n') std::cin.ignore();
				std::cin >> newID;
			}
			employees[i]->setTeamNumber(newID);
		}
	}
	return true;
}

void Company::printTeams() const {
	int size1 = numberOfTeams(), size2 = numberOfEmployees();
	std::cout << "There are " << size1 << " teams in the company: \n";
	for (int i = 0; i < size1; i++) {
		std::cout << "Information about team " << i + 1 << ": \n";
		int ID = teams[i].getIDnumber();
		teams[i].print(std::cout);
		for (int j = 0; j < size2; j++) {
			if (employees[j]->getTeamNumber() == ID) {
				employees[j]->print(std::cout);
			}
		}
		std::cout << std::endl;
	}
}

bool Company::isTeamNumber(int number) const {
	int size = numberOfTeams();
	for (int i = 0; i < size; i++) {
		if (teams[i].getIDnumber() == number) return true;
	}
	return false;
}

bool Company::everyoneAreTeamLeaders() const {
	return numberOfEmployees() == numberOfTeams();
}

void Company::changeLeader(int teamNumber, std::string newLeaderName) {
	int size = numberOfTeams();
	bool found = false;
	for (int j = 0; j < size && !found; j++) {
		if (teams[j].getIDnumber() == teamNumber) {
			teams[j].setLeaderName(newLeaderName);
			found = true;
		}
	}
}

int Company::getTeamNumberOf(std::string name) const {
	int size = numberOfEmployees();
	for (int i = 0; i < size; i++) {
		if (employees[i]->getName() == name) return employees[i]->getTeamNumber();
	}
	return -1;
}

Company::~Company() {
	int size = numberOfEmployees();
	for (int i = 0; i < size; i++) {
		delete employees[i];
	}
}

std::ostream& operator << (std::ostream& out, const Company &company) {
	company.CEO.print(out);
	out	<< company.companyName << '\n'
		<< company.companyAddress << '\n';
	int numberOfTeams = company.teams.size();
	if (numberOfTeams != 0) {
		out << numberOfTeams << '\n';
		for (int i = 0; i < numberOfTeams; i++) {
			company.teams[i].print(out);
		}
	}
	int numberOfEmployees = company.employees.size();
	if (numberOfEmployees != 0) {
		out << numberOfEmployees << '\n';
		for (int i = 0; i < numberOfEmployees; i++) {
			company.employees[i]->print(out);
		}
	}
	return out;
}

std::istream& operator >> (std::istream& in, Company& company) {
	std::string type;
	in >> type;
	in.ignore();
	company.CEO.input(in);
	in.ignore();
	std::getline(in, company.companyName);
	std::getline(in, company.companyAddress);
	int numberOfTeams;
	in >> numberOfTeams;
	if (numberOfTeams != 0) {
		in.ignore();
		for (int i = 0; i < numberOfTeams; i++) {
			Team newTeam;
			newTeam.input(in);
			company.AddTeam(newTeam);
		}
	}
	int numberOfEmployees;
	in >> numberOfEmployees;
	if (numberOfEmployees != 0) {
		in.ignore();
		for (int i = 0; i < numberOfEmployees; i++) {
			Employee *newEmployee;
			std::getline(in, type);
			newEmployee = Employee::produce(type);
			newEmployee->input(in);
			company.AddEmployee(newEmployee);
		}
	}
	return in;
}