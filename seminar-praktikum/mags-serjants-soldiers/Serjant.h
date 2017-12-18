#pragma once
#ifndef _SERJANT_
#define _SERJANT_

#include<string>
#include<vector>
#include"Soldier.h"

class Serjant : public Soldier {
private:
	std::string description;
	std::vector<Soldier> squad;
public:
	Serjant(std::string, std::string, int, int, int);
	int SquadRate() const;	// number of soldiers in the squad
	int SquadLevel() const;
	void addSoldier(std::string, int, int, int);
	int SquadCost() const;
};

#endif // !_SERJANT_
