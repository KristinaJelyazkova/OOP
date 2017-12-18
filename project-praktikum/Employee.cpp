#include"Employee.h"

#include"Tester.h"
#include"JuniorProgrammer.h"
#include"SeniorProgrammer.h"


PersonalInformation::PersonalInformation(std::string _name, std::string _address, std::string _EGN)
	: name(_name), address(_address), EGN(_EGN){}

Employee::Employee(std::string _name, std::string _address, std::string _EGN,
	std::string _date, std::string _boss, std::string _position, int _teamNumber)
	: persInfo(_name, _address, _EGN), date(_date),
	bossName(_boss), position(_position), teamNumber(_teamNumber) {}

void Employee::input(std::istream& in) {
	std::getline(in, persInfo.name);
	std::getline(in, persInfo.address);
	std::getline(in, persInfo.EGN);
	std::getline(in, date);
	std::getline(in, bossName);
	in >> teamNumber;
}

void Employee::print(std::ostream& out) const {
	out << position << '\n'
		<< persInfo.name << '\n'
		<< persInfo.address << '\n'
		<< persInfo.EGN << '\n'
		<< date << '\n'
		<< bossName << '\n'
		<< teamNumber << '\n';
}

std::string Employee::getEGN() const {
	return persInfo.EGN;
}

std::string Employee::getName() const {
	return persInfo.name;
}

std::string Employee::getPosition() const {
	return position;
}

int Employee::getTeamNumber() const {
	return teamNumber;
}

std::string Employee::getBoss() const {
	return bossName;
}

void Employee::setAddress(std::string newAddress)
{
	persInfo.address = newAddress;
}

void Employee::setBoss(std::string newBossName)
{
	bossName = newBossName;
}

void Employee::setTeamNumber(int newTeamNumber) {
	teamNumber = newTeamNumber;
}

void Employee::setProjectWork(std::string) {}
void Employee::setProjectTest(std::string) {}
void Employee::setOS(std::string) {}

Employee::~Employee(){}

Employee* Employee::produce(std::string type) {
	if (type == "tester") return new Tester();
	if (type == "junior programmer") return new JuniorProgrammer();
	if (type == "senior programmer") return new SeniorProgrammer();
}