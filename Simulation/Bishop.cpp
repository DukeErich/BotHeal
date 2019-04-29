#include <iostream>
#include "Bishop.h"
#include "Warrior.h"
#include "Wolf.h"

using namespace std;

void Bishop::heal(Warrior& warrior)
{
	if (warrior.hp.isEmpty())
	{
		cout << "The target is dead" << endl;
		return;
	}

	if (mp.isEmpty())
	{
		cout << "No MP!" << endl;
		return;
	}

	mp.value -= 1;
	warrior.hp.value += 60;
	warrior.hp.removeOverflow();
	cout << warrior.name << " HP: " << warrior.hp.value << endl;
	cout << "Bishop MP: " << mp.value << endl;
}

void Bishop::drainMp(Wolf& wolf)
{
	if (wolf.mp.value >= mpDrain)
	{
		wolf.mp.value -= mpDrain;
		mp.value += mpDrain;
		mp.removeOverflow();
		cout << "MP Bishop: " << mp.value << endl;
		cout << "MP " << wolf.name << ": " << wolf.mp.value << endl;
	}
	else if (!wolf.mp.isEmpty())
	{
		mp.value += wolf.mp.value;
		mp.removeOverflow();
		wolf.mp.value -= wolf.mp.value;
		cout << "MP Bishop: " << mp.value << endl;
		cout << "MP " << wolf.name << ": " << wolf.mp.value << endl;
	}
	else
	{
		cout << "Great Wolf has no MP" << endl;
	}
}

void Bishop::doAction(Warrior& warrior, Wolf& wolf)
{
	if (!warrior.hp.isFull() && !mp.isEmpty())
	{
		cout << "Heal!" << endl;
		heal(warrior);
	}
	else if (!mp.isFull())
	{
		cout << "MP drain!" << endl;
		drainMp(wolf);
	}
	else
	{
		cout << "Bishop says: I wait" << endl;
	}
}