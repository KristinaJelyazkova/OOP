#pragma once
#ifndef _BOSS_
#define _BOSS_

#include"Serjant.h"
#include"Mag.h"
#include<string>
#include<vector>

class Boss : Soldier {
private:
	std::string description;
	std::vector<Mag*> mags;
public:
	Boss(std::string, std::string, int, int, int);
	int magsRate() const; // number of mags in the army
	int SoldierRate() const; // number of soldiers in the army - all - soldiers, serjants, mags and boss
	int ArmyLevel() const;
	void addMag(Mag*);
	int totalPower() const;
	int ArmyCost() const;
};

#endif // !_BOSS_
