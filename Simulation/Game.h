#pragma once
#include "Warrior.h"
#include "Wolf.h"
#include "Bishop.h"

class Game
{
public:
	Warrior warrior;
	Wolf wolf;
	Bishop bishop;

	void initCharacters();
	bool isOver();
	void doAllActions();
	void processResult();
};