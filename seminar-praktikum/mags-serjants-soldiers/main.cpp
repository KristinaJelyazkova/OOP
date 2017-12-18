#include"Soldier.h"
#include"Serjant.h"
#include"Spell.h"
#include"MagicBook.h"
#include"Mag.h"
#include"Boss.h"

#include<iostream>

int main() {

	Serjant *serjant[5] = {
		new Serjant("squad 1","Ivan",40,50,200),
		new Serjant("squad 2","Krisi",20,100,360),
		new Serjant("squad 3","Ivi",30,120,500),
		new Serjant("squad 4","Sophie",42,30,100),
		new Serjant("squad 5","Yana",56,60,250),
	};

	serjant[0]->addSoldier("Anton", 10, 20, 60);
	serjant[0]->addSoldier("Mitko", 5, 15, 50);
	serjant[1]->addSoldier("Viktor", 30, 50, 70);
	serjant[1]->addSoldier("Yasen", 21, 10, 80);
	serjant[1]->addSoldier("Zdravko", 43, 20, 90);
	serjant[2]->addSoldier("Poli", 30, 25, 80);
	serjant[2]->addSoldier("Toni", 45, 15, 60);
	serjant[3]->addSoldier("Veni", 90, 50, 70);
	serjant[3]->addSoldier("Kari", 31, 70, 50);
	serjant[3]->addSoldier("eti", 43, 80, 40);
	serjant[4]->addSoldier("Niki", 90, 15, 70);
	serjant[4]->addSoldier("Mira", 25, 95, 20);

	Spell *spells[5] = {
		new Spell("causes death","poison",100),
		new Spell("makes them fall in love","love",100),
		new Spell("makes them faint","poison",100),
		new Spell("makes them fall out of love","love",100),
		new Spell("makes the thing disappear","damage",100)
	};

	MagicBook *magicBook[2] = {
		new MagicBook,
		new MagicBook
	};
	magicBook[0]->addSpell(spells[0]);
	magicBook[0]->addSpell(spells[1]);
	magicBook[0]->addSpell(spells[2]);
	magicBook[1]->addSpell(spells[3]);
	magicBook[1]->addSpell(spells[4]);

	Mag *mag[2] = {
			new Mag("very powerful magician",2000, magicBook[0],"Kriel",150,2500,3000),
			new Mag("the master of magicians",5000, magicBook[0],"Lonto",270,7000,9000)
	};

	mag[0]->addSerjant(serjant[0]);
	mag[0]->addSerjant(serjant[1]);
	mag[0]->addSerjant(serjant[2]);
	mag[1]->addSerjant(serjant[3]);
	mag[1]->addSerjant(serjant[4]);

	Boss *boss = new Boss("the great boss", "Manta", 52, 1000, 2000);
	boss->addMag(mag[0]);
	boss->addMag(mag[1]);

	std::cout << "TOTAL ARMY LEVEL: " << boss->ArmyLevel() << std::endl;
	std::cout << "AVERAGE ARMY LEVEL: " << (double) boss->ArmyLevel() / boss->SoldierRate() << std::endl;


	std::cout << "TOTAL POWER LEVEL: " << boss->totalPower() << std::endl;
	std::cout << "AVERAGE POWER LEVEL: " << (double)boss->totalPower() / boss->magsRate() << std::endl;

	std::cout << "TOTAL ARMY COST: " << boss->ArmyCost() << std::endl;
	
	system("pause");
	return 0;
}