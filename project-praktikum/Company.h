#pragma once
#ifndef _COMPANY_
#define _COMPANY_

#include"Employee.h"
#include"Team.h"
#include<iostream>
#include<vector>

class Company {
private:
	Employee CEO;
	std::string companyName;
	std::string companyAddress;
	std::vector<Employee*> employees;
	std::vector<Team> teams;
public:
	Company(std::string = "", std::string = "", std::string = "",
		std::string = "", std::string = "", std::string = "");

	void inputFromKeyboard();
	void output() const;

	bool isTeamLeader(std::string) const;
	bool isEmployee(std::string) const;
	void AddEmployee(Employee *);
	int numberOfEmployees() const;
	bool printEmployeeBy(std::string) const;
	bool deleteEmployeeBy(std::string);
	bool printByPosition(std::string) const;
	bool ChangeInfoEmployee(std::string, int, std::string);

	void AddTeam(Team);
	int numberOfTeams() const;
	void changeTeamNumberOf(std::string, int);
	bool deleteTeamBy(int);
	void printTeams() const;
	bool isTeamNumber(int) const;
	bool everyoneAreTeamLeaders() const;
	void changeLeader(int, std::string);
	int getTeamNumberOf(std::string) const;

	~Company();

	friend std::ostream& operator << (std::ostream&, const Company&);
	friend std::istream& operator >> (std::istream&, Company&);
};

std::ostream& operator << (std::ostream&, const Company&);
std::istream& operator >> (std::istream&, Company&);

#endif