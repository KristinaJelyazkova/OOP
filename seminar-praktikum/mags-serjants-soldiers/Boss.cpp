#include"Boss.h"
#include<string>
#include<vector>
#include<iostream>

Boss::Boss(std::string _desc, 
	std::string _name, int _age, int _level, int _salary) :
	Soldier(_name, _age, _level, _salary), description(_desc) {}

int Boss::magsRate() const { // number of mags in the army
	return mags.size();
}

int Boss::SoldierRate() const { // number of soldiers in the army - all - soldiers, serjants, mags and boss
	int size = magsRate(),
		total = 0;
	for (int i = 0; i < size; i++) {
		total += mags[i]->battalionRateSoldiers();
	}
	total++;	// + the boss
	return total;
}

int Boss::ArmyLevel() const {
	int size = mags.size(),
		sum = 0;
	for (int i = 0; i < size; i++) {
		sum += mags[i]->battalionLevel();
	}
	sum += level;	// + the boss
	return sum;
}

void Boss::addMag(Mag* mag) {
	mags.push_back(mag);
}

int Boss::totalPower() const{
	int size = mags.size(),
		sum = 0;
	for (int i = 0; i < size; i++) {
		sum += mags[i]->getPower();
	}
	return sum;
}

int Boss::ArmyCost() const {
	int size = mags.size(),
		sum = 0;
	for (int i = 0; i < size; i++) {
		sum += mags[i]->battalionCost();
	}
	return sum;
}