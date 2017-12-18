#pragma once
#ifndef _MAGICBOOK_
#define _MAGICBOOK_

#include<vector>
#include"Spell.h"

class MagicBook {
private:
	std::vector<Spell*> spells;
	int pages;
public:
	MagicBook(int _pages = 1);
	MagicBook(MagicBook*);
	void addSpell(Spell*);
};

#endif // !_MAGICBOOK_
