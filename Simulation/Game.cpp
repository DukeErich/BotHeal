#include "Game.h"
#include "Warrior.h"
#include "Wolf.h"
#include "Bishop.h"
#include "Bar.h"
#include <iostream>

const int WORLD_SIZE = 1000;

void Game::initCharacters()
{
	warrior.name = "Warrior";
	warrior.hp.create(100);
	warrior.deadWolves = 0;
	warrior.position = 0;

	wolf.name = "Wolf";
	wolf.powerBreak = false;
	wolf.hp.create(100);
	wolf.mp.create(10);
	wolf.attack = wolf.baseAttack = 60;
	wolf.position = 600;

	bishop.name = "Bishop";
	bishop.mpDrain = 3;
	bishop.mp.create(5);
	bishop.position = 130;
}

bool Game::isOver()
{
	return (warrior.hp.isEmpty());
}

void Game::doAllActions()
{
	if (!wolf.hp.isEmpty())
	{
		wolf.doAction(warrior);
	}
	if (!warrior.hp.isEmpty())
	{
		warrior.doAction(wolf);
	}

	bishop.doAction(warrior, wolf);
}

void Game::processResult()
{
	if (warrior.hp.isEmpty())
	{
		std::cout << "Warrior Noob DEAD!" << std::endl;
		std::cout << "GAME OVER" << std::endl;
		std::cout << warrior.deadWolves << " wolves dead" << std::endl;
	}
	if (wolf.hp.isEmpty())
	{
		wolf.position = int((float)rand() / RAND_MAX * WORLD_SIZE);
		warrior.deadWolves++;
		wolf.baseAttack++;
		wolf.attack = wolf.baseAttack;

		wolf.hp.create(int(wolf.hp.maximum * 1.1));
		wolf.mp.create(int(wolf.mp.maximum * 1.1));

		wolf.powerBreak = false;

		std::cout << "Geat Wolf DEAD ='(" << std::endl;
		std::cout << "New Great Wolf" << std::endl;
		std::cout << "Attack New Wolf: " << wolf.attack << std::endl;
		std::cout << "HP New Wolf: " << wolf.hp.value << std::endl;
		std::cout << "MP New Wolf: " << wolf.mp.value << std::endl;
	}
}