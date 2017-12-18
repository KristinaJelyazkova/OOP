#include"MagicBook.h"

MagicBook::MagicBook(int _pages) : pages(_pages) {};

MagicBook::MagicBook(MagicBook* other) {
	spells = other->spells;
	pages = other->pages;
}

void MagicBook::addSpell(Spell* spell) {
	spells.push_back(spell);
	pages++;
}

