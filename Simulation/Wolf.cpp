#include <iostream>
#include "Wolf.h"
#include "Warrior.h"
using namespace std;

void Wolf::doAction(Warrior& warrior)
{
	if (canAttack(warrior))
	{
		cout << "Wolf attacks" << endl;
		warrior.hp.value -= attack;
		cout << warrior.name << " HP: " << warrior.hp.value << endl;
	}
	else
	{
		cout << "Wolf moves" << endl;
		if (position < warrior.position)
		{
			position += 25;
			return;
		}
		position -= 25;
	}
}
