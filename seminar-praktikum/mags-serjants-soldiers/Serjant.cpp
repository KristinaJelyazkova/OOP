#include<string>
#include<vector>
#include"Serjant.h"

Serjant::Serjant(std::string _desc, 
	std::string _name, int _age, int _level, int _salary) :
	Soldier(_name, _age, _level ,_salary), description(_desc), squad() {};

int Serjant::SquadRate() const { // number of soldiers in the squad + their serjant
	return squad.size() + 1;
};	

int Serjant::SquadLevel() const {
	int size = SquadRate() - 1,
		sum = 0;
	for (int i = 0; i < size; i++) {
		sum += ((Soldier)squad[i]).getLevel();
	}
	sum += level;
	return sum;
};

void Serjant::addSoldier(std::string name, int age, int level, int salary) {
	squad.push_back(Soldier(name, age, level, salary));
}

int Serjant::SquadCost() const{
	int size = SquadRate() - 1,
		sum = 0;
	for (int i = 0; i < size; i++) {
		sum += ( (Soldier) squad[i]).getSalary();
	}
	sum += salary;
	return sum;
}