#include"Soldier.h"

Soldier::Soldier(std::string _name, int _age, int _level, int _salary) :
	name(name), age(_age), level(_level), salary(_salary) {}

int Soldier::getLevel() {
	return level;
}

int Soldier::getSalary() {
	return salary;
}