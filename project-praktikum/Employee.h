#pragma once
#ifndef _EMPLOYEE_
#define _EMPLOYEE_

#include<string>
#include<iostream>
#include<fstream>

struct PersonalInformation {
	std::string name;
	std::string address;
	std::string EGN;
	PersonalInformation(std::string, std::string, std::string);
};

class Employee {

protected:
	PersonalInformation persInfo;
	std::string date;
	std::string bossName;
	std::string position;
	int teamNumber;

public:
	Employee(std::string = "", std::string = "", std::string = "", 
		std::string = "", std::string = "", std::string = "", int = 0);

	virtual void input(std::istream&);
	virtual void print(std::ostream&) const;

	std::string getEGN() const;
	std::string getName() const;
	std::string getPosition() const;
	std::string getBoss() const;
	int getTeamNumber() const;

	void setAddress(std::string);
	void setBoss(std::string);
	void setTeamNumber(int);

	virtual void setProjectWork(std::string);
	virtual void setProjectTest(std::string);
	virtual void setOS(std::string);

	virtual ~Employee();

	static Employee* produce(std::string);
};

#endif