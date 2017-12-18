#pragma once
#ifndef _SPELL_
#define _SPELL_

#include<string>

class Spell {
private:
	std::string description;
	std::string type;
	int power;
public:
	Spell(std::string, std::string, int);
};

#endif // !_SPELL
