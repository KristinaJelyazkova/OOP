#include"Mag.h"

Mag::Mag(std::string _desc, int _power, MagicBook* _book,
	std::string _name, int _age, int _level, int _salary) :
Soldier(_name, _age, _level, _salary), description(_desc), power(_power), book(_book) {}

int Mag::battalionRateSerjants() const { // number of serjants in the battalion
	return battalion.size();
}

int Mag::battalionRateSoldiers() const { // number of soldiers in the battalion + serjants + mag
	int size = battalionRateSerjants(),
		total = 0;
	for (int i = 0; i < size; i++) {
		total += battalion[i]->SquadRate();
	}
	total++;	// + the mag
	return total;
}

int Mag::battalionLevel() const{
	int size = battalionRateSerjants(),
		sum = 0;
	for (int i = 0; i < size; i++) {
		sum += battalion[i]->SquadLevel();
	}
	sum += level;	// + the mag
	return sum;
}

void Mag::addSerjant(Serjant* serjant) {
	battalion.push_back(serjant);
}

int Mag::getPower() {
	return power;
}

int Mag::battalionCost() const {
	int size = battalionRateSerjants(),
		sum = 0;
	for (int i = 0; i < size; i++) {
		sum += battalion[i]->SquadCost();
	}
	sum += salary;	// + the mag
	return sum;
}

