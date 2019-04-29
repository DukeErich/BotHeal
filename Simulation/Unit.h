#pragma once

#include <string>
#include "Bar.h"

class Unit
{
public:
	std::string name;
	Bar hp;
	Bar mp;
	int baseAttack;
	int attack;
	bool powerBreak;
	int position;

	bool canAttack(const Unit& other);
};