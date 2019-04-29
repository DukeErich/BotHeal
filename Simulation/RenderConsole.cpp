#include "RenderConsole.h"
#include "Bishop.h"
#include "Warrior.h"
#include "Wolf.h"
#include "Game.h"
#include "Unit.h"
#include <iostream>

using namespace std;

void drawBar(const string& name, const Bar& bar)
{
	cout << name;
	cout << bar.value << "/" << bar.maximum << " [";

	int value = (int)(bar.fillFactor() * 10);
	int maximum = 10;
	int i = 1;
	while (i <= value)
	{
		cout << "#";
		i++;
	}
	while (i <= maximum)
	{
		cout << " ";
		i++;
	}
	cout << "]" << endl;
}

void drawStateToConsole(const Game& game)
{
	cout << endl;
	cout << "=====================================" << endl;
	drawBar(game.warrior.name + "HP: ", game.warrior.hp);
	drawBar(game.bishop.name + "MP: ", game.bishop.mp);
	drawBar(game.wolf.name + "HP: ", game.wolf.hp);
	drawBar(game.wolf.name + "MP: ", game.wolf.mp);

	if (game.wolf.powerBreak)
	{
		cout << "Status Wolf: Power Break" << endl;
	}
	else
	{
		cout << "Status Wolf: none" << endl;
	}
	cout << endl;
}