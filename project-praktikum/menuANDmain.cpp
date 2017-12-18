#include"Company.h"
#include<iostream>
#include<fstream>

const char *FILE_NAME = "Company2.txt";

Employee* createEmployee() {
	Employee *newEmployee;
	std::cout << "Please enter the position of the employee: tester, junior programmer, senior programmer.\n";
	std::string position;
	if (std::cin.peek() == '\n') std::cin.ignore();
	std::getline(std::cin, position);
	while (position != "tester" && position != "junior programmer" && position != "senior programmer") {
		std::cout << "The position you entered does not exist.\n"
			<< "Enter new position: ";
		if (std::cin.peek() == '\n') std::cin.ignore();
		std::getline(std::cin, position);
	}
	newEmployee = Employee::produce(position);
	std::cout << "Enter full name, address, EGN, date, boss name, team number(in this order!).\n";
	std::cout << "Then if tester - enter project and OS, if junior programmer - project, if senior - tested project, OS and other project(in this order!).\n";
	newEmployee->input(std::cin);
	return newEmployee;
}

void printOptions() {
	std::cout << "\nPlease enter the number of the task you choose to be performed (from 1 to 12).\n"
		<< "The changes you make will be automatically saved to a file.\n"
		<< "1. Enter information about the company.\n"
		<< "2. See the information about the company.\n"
		<< "3. Add an employee.\n"
		<< "4. See the information about an employee.\n"
		<< "5. Fire an employee.\n"
		<< "6. See the information about all employees on a certain position.\n"
		<< "7. Change the information about an employee.\n"
		<< "8. Create a new team.\n"
		<< "9. Transfer an employee from one team to another.\n"
		<< "10. Delete team.\n"
		<< "11. See the information about all teams.\n"
		<< "12. Exit the menu.\n";
}

void menu(Company &company) {
	int number;
	printOptions();
	std::cin >> number;
	switch (number) {
	case 1: {
		company.inputFromKeyboard();
		std::cout << "You will have to create empty teams for your company.\n"
			<< "Enter the number of teams.\n";
		unsigned int number;
		std::cin >> number;
		if (number == 0) {
			std::cout << "You have to create at least one team! Creating one team...\n";
			number = 1;
		}
		for (unsigned int i = 0; i < number; i++) {
			std::cout << "Enter the information about the team leader.\n";
			Employee *newEmployee = createEmployee();
			company.AddEmployee(newEmployee);
			std::cout << "Now enter the name of the project the team will be working on.\n";
			std::string project;
			if (std::cin.peek() == '\n') std::cin.ignore();
			std::getline(std::cin, project);
			std::cout << "Now enter the IDnumber of the team.\n";
			int ID;
			if (std::cin.peek() == '\n') std::cin.ignore();
			std::cin >> ID;
			newEmployee->setTeamNumber(ID);
			company.AddTeam(Team(ID, newEmployee->getName(), project));
		}
		std::ofstream out(FILE_NAME);
		out << company;
		break;
	}
	case 2: {
		//company.output();
		std::cout << company;
		break;
	}
	case 3: {
		Employee *newEmployee = createEmployee();
		int newTeamNumber = newEmployee->getTeamNumber();
		while (!company.isTeamNumber(newTeamNumber)) {
			std::cout << "The team number you entered does not exist! You have to add the employee to an existing team - the team number of the employee should be one of the ID numbers of the existing teams.\n";
			std::cout << "Enter new team number: ";
			if (std::cin.peek() == '\n') std::cin.ignore();
			std::cin >> newTeamNumber;
		}
		newEmployee->setTeamNumber(newTeamNumber);
		company.AddEmployee(newEmployee);
		std::ofstream out;
		out.open(FILE_NAME, std::ios::out | std::ios::trunc);
		out << company;
		break;
	}
	case 4: {
		std::string EGN;
		std::cout << "Enter EGN of the employee you want to see the information about.\n";
		if(std::cin.peek() == '\n') std::cin.ignore();
		std::getline(std::cin, EGN);
		if (!company.printEmployeeBy(EGN)) {
			std::cout << "There is no employee with this EGN.\n";
		}
		break;
	}
	case 5: {
		if (company.everyoneAreTeamLeaders()) {
			std::cout << "Every employee is a team leader! You can not fire anyone! Exiting this mode...\n";
			break;
		}
		std::cout << "Caution: if you fire someone's boss, the boss name of this person will be changed to 'no boss'.\n";
		std::string name;
		std::cout << "Enter full name of the employee you want to fire.\n";
		if (std::cin.peek() == '\n') std::cin.ignore();
		std::getline(std::cin, name);
		if (!company.deleteEmployeeBy(name)) {
			std::cout << "No employee with this name!\n";
		}
		else {
			std::ofstream out(FILE_NAME);
			out << company;
		}
		break;
	}
	case 6: {
		std::cout << "Please enter the position: tester, junior programmer, senior programmer\n";
		if (std::cin.peek() == '\n') std::cin.ignore();
		std::string position;
		std::getline(std::cin, position);
		if (position != "tester" && position != "junior programmer" && position != "senior programmer") {
			std::cout << "The position you entered does not exist.\n";
		}
		else if (!company.printByPosition(position)) {
			std::cout << "There are no employees on this position.\n";
		}
		break;
	}
	case 7: {
		std::cout << "Enter the name of the employee.\n";
		std::string name;
		if (std::cin.peek() == '\n') std::cin.ignore();
		std::getline(std::cin, name);
		int number = 0;
		std::cout << "You can change 5 things about an employee.\n"
			<< "You will stay in the mode for changing the information about this employee until you enter 6.\n"
			<< "1. Change the address of the employee.\n"
			<< "2. Change the boss of the employee.\n"
			<< "3. Change the project they are working on(in case they are a junior or a senior programmer).\n"
			<< "4. Change the project they are testing(in case they are a tester or a senior programmer).\n"
			<< "5. Change the operating system they are using for testing(in case they are a tester or a senior programmer).\n"
			<< "6. Done changing the information about this employee.\n";
		std::cout << "Enter a number from 1 to 6: ";
		std::cin >> number;
		while (number != 6) {
			std::string newInfo;
			std::cout << "Enter the new information: ";
			if (std::cin.peek() == '\n') std::cin.ignore();
			std::getline(std::cin, newInfo);
			if (!company.ChangeInfoEmployee(name, number, newInfo)) {
				std::cout << "There is no such employee or the position of the employee is not adequate for the change or you have to enter a number from 1 to 6.\n";
			}
			std::cout << "Enter a number from 1 to 6: ";
			std::cin >> number;
		}
		std::ofstream out(FILE_NAME, std::ios::out | std::ios::trunc);
		out << company;
		break;
	}
	case 8: {
		if (company.everyoneAreTeamLeaders()) {
			std::cout << "Every employee is a team leader! You have to hire a new employee! "
				<< "You can add an employee by entering 3. Exiting this mode...\n";
			break;
		}
		std::cout << "Enter the team number, leader name and project name(in this order!).\n";
		Team newTeam;
		newTeam.input(std::cin);
		int newTeamNumber = newTeam.getIDnumber();
		while (company.isTeamNumber(newTeamNumber)) {
			std::cout << "You have entered an existing team number! The team numbers have to be unique!\n";
			std::cout << "Enter new team number: ";
			if (std::cin.peek() == '\n') std::cin.ignore();
			std::cin >> newTeamNumber;
		}
		newTeam.setTeamNumber(newTeamNumber);
		std::string leaderName = newTeam.getLeaderName();
		while (!company.isEmployee(leaderName) || company.isTeamLeader(leaderName)) {
			std::cout << "This person is not an existing employee or is already a team leader!\n";
			std::cout << "Enter new leader name: ";
			if (std::cin.peek() == '\n') std::cin.ignore();
			std::getline(std::cin, leaderName);
		}
		newTeam.setLeaderName(leaderName);
		company.AddTeam(newTeam);
		company.changeTeamNumberOf(newTeam.getLeaderName(), newTeam.getIDnumber());
		std::cout << "Enter the number of people in this team: ";
		int size;
		if (std::cin.peek() == '\n') std::cin.ignore();
		std::cin >> size;
		while(size > (company.numberOfEmployees() - company.numberOfTeams())) {
			std::cout << "There are not enough people in the company.\n";
			std::cout << "Enter new number of people in this team: ";
			if (std::cin.peek() == '\n') std::cin.ignore();
			std::cin >> size;
		}
		for (int i = 0; i < size; i++) {
			std::cout << "Enter the name of an employee you want to be in this team.\n";
			std::string name;
			if (std::cin.peek() == '\n') std::cin.ignore();
			std::getline(std::cin, name);
			while (!company.isEmployee(name) || company.isTeamLeader(name)) {
				std::cout << "This person is not an existing employee or is already a team leader!\n";
				std::cout << "Enter new name: ";
				if (std::cin.peek() == '\n') std::cin.ignore();
				std::getline(std::cin, name);
			}
			company.changeTeamNumberOf(name, newTeam.getIDnumber());
		}
		std::ofstream out(FILE_NAME);
		out << company;
		break;
	}
	case 9: {
		if (company.everyoneAreTeamLeaders()) {
			std::cout << "Every employee is a team leader! You can not transfer anyone! Exiting this mode...\n";
			break;
		}
		if (company.numberOfTeams() == 1) {
			std::cout << "There is only one team. You can not transfer anyone!\n";
			break;
		}
		std::string name;
		std::cout << "Enter the name of the employee you want to transfer.\n";
		if (std::cin.peek() == '\n') std::cin.ignore();
		std::getline(std::cin, name);
		while (!company.isEmployee(name)) {
			std::cout << "This person is not an existing employee!\n";
			std::cout << "Enter new name: ";
			if (std::cin.peek() == '\n') std::cin.ignore();
			std::getline(std::cin, name);
		}
		int ID;
		std::cout << "Enter the ID number of the team you want to transfer the employee to.\n";
		if (std::cin.peek() == '\n') std::cin.ignore();
		std::cin >> ID;
		while (!company.isTeamNumber(ID)) {
			std::cout << "No such team number!\n";
			std::cout << "Enter new team number: ";
			if (std::cin.peek() == '\n') std::cin.ignore();
			std::cin >> ID;
		}
		if (company.isTeamLeader(name)) {
			int teamNumber = company.getTeamNumberOf(name);
			std::cout << "You transfered the leader of team with ID number " << teamNumber << std::endl
				<< "You have to enter the name of the new leader of this team: ";
			std::string newLeaderName;
			if (std::cin.peek() == '\n') std::cin.ignore();
			std::getline(std::cin, newLeaderName);
			while (!company.isEmployee(newLeaderName) || company.isTeamLeader(newLeaderName)) {
				std::cout << "This person is not an existing employee or is already a team leader!\n";
				std::cout << "Enter new leader name: ";
				if (std::cin.peek() == '\n') std::cin.ignore();
				std::getline(std::cin, newLeaderName);
			}
			company.changeLeader(teamNumber, newLeaderName);
			company.changeTeamNumberOf(newLeaderName, teamNumber);
		}
		company.changeTeamNumberOf(name, ID);
		std::ofstream out(FILE_NAME);
		out << company;
		break;
	}
	case 10: {
		if (company.numberOfTeams() == 1) {
			std::cout << "There is only one team. You can not delete it!\n";
			break;
		}
		int ID;
		std::cout << "Enter the ID number of the team you want to delete.\n";
		if (std::cin.peek() == '\n') std::cin.ignore();
		std::cin >> ID;
		if (!company.deleteTeamBy(ID)) {
			std::cout << "No team with this ID number.\n";
		}
		else {
			std::ofstream out(FILE_NAME);
			out << company;
		}
		break;
	}
	case 11: {
		company.printTeams();
		break;
	}
	case 12: return;
	default: std::cout << "The number should be between 1 and 12.\n";
	}
	menu(company);
}

int main() {
	Company company;

	std::ifstream in(FILE_NAME);
	in >> company;

	menu(company);

	system("pause");
	return 0;
}