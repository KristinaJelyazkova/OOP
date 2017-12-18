#pragma once
#ifndef _MAG_
#define _MAG_

#include<string>
#include<vector>
#include"MagicBook.h"
#include"Serjant.h"

class Mag : Soldier{
private:
	std::string description;
	std::vector<Serjant*> battalion;
	int power;
	MagicBook book;
public:
	Mag(std::string, int, MagicBook*, std::string, int, int, int);
	int battalionRateSerjants() const; // number of serjants in the battalion
	int battalionRateSoldiers() const; // number of soldiers in the battalion
	int battalionLevel() const;
	void addSerjant(Serjant*);
	int getPower();
	int battalionCost() const;
};

#endif // !_MAG_
