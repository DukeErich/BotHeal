#include <cstdio>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

class Warrior 
{
public:
	string name;
	int hp;
	int maxHp;
	int deadWolves;
};

class Wolf
{
public:
	string name;
	int hp;
	int maxHp;
	int mp;
	int maxMp;
	int attack;
	int baseAttack;
	bool powerBreak;
};

class Bishop
{
public:
	string name;
	int mp;
	int maxMp;
	int mpDrain;
};

void initCharacters(Warrior& warrior, Wolf& wolf, Bishop& bishop)
{
	warrior.name = "Warrior";
	warrior.maxHp = 100;
	warrior.hp = warrior.maxHp;
	warrior.deadWolves = 0;
	
	wolf.name = "Wolf";
	wolf.mp = 10;
	wolf.baseAttack = 60;
	wolf.powerBreak = false;
	cout << "give wolf hp ";
	cin >> wolf.hp;
	wolf.maxHp = wolf.hp;
	wolf.maxMp = wolf.mp;
	wolf.attack = wolf.baseAttack;

	bishop.name = "Bishop";
	bishop.mpDrain = 3;
	cout << "give bishop mp ";
	cin >> bishop.mp;
	bishop.maxMp = bishop.mp;
}

void drawBar(string name, int value, int maxValue)
{
	cout << name;
	cout << value << "/" << maxValue << " [";
	if (maxValue == 0)
	{
		cout << "          ]" << endl;
	}
	else
	{
		value = (value * 10 / maxValue);
		maxValue = 10;
		int i = 1;
		while (i <= value)
		{
			cout << "#";
			i++;
		}
		while (i <= maxValue)
		{
			cout << " ";
			i++;
		}
		cout << "]" << endl;
	}
}

void drawState(Warrior& warrior, Wolf& wolf, Bishop& bishop)
{
	cout << endl;
	cout << "=====================================" << endl;
	drawBar(warrior.name + "HP: ", warrior.hp, warrior.maxHp);
	drawBar(bishop.name + "MP: ", bishop.mp, bishop.maxMp);
	drawBar(wolf.name + "HP: ", wolf.hp, wolf.maxHp);
	drawBar(wolf.name + "MP: ", wolf.mp, wolf.maxMp);
	if (wolf.powerBreak)
	{
		cout << "Status Wolf: Power Break" << endl;
	}
	else
	{
		cout << "Status Wolf: none" << endl;
	}
	cout << endl;
}

void doWolfAction(Wolf wolf, Warrior& warrior)
{
	printf("Wolf attacks\n");
	warrior.hp = warrior.hp - wolf.attack;
	cout << warrior.name <<" HP: " << warrior.hp << endl;
}

void doWarroirAction(Wolf& wolf)
{
	if (wolf.powerBreak)
	{
		printf("Warrior attacks\n");
		wolf.hp = wolf.hp - 10;
		cout << wolf.name << " HP: " << wolf.hp << endl;
	}
	else
	{
		printf("Use Power Break\n");
		wolf.attack = wolf.attack * 0.5;
		wolf.powerBreak = true;
	}
}

void doBishopAction(Bishop& bishop, Warrior& warrior, Wolf& wolf)
{
	if (bishop.mp > 0 && warrior.hp > 0)
	{
		printf("Heal\n");
		bishop.mp = bishop.mp - 1;
		warrior.hp = warrior.hp + 60;
		if (warrior.hp > warrior.maxHp)
		{
			warrior.hp = warrior.maxHp;
		}
		cout << warrior.name << " HP: " << warrior.hp << endl;
		cout << "Bishop MP: " << bishop.mp << endl;
	}
	else
	{
		cout << "No mana, draining" << endl;
		if (wolf.mp >= bishop.mpDrain)
		{
			wolf.mp = wolf.mp - bishop.mpDrain;
			bishop.mp = bishop.mp + bishop.mpDrain;
			cout << "MP Bishop: " << bishop.mp << endl;
			cout << "MP " << wolf.name << ": " << wolf.mp << endl;
		}
		else if (wolf.mp > 0)
		{
			bishop.mp = bishop.mp + wolf.mp;
			wolf.mp = wolf.mp - wolf.mp;
			cout << "MP Bishop: " << bishop.mp << endl;
			cout << "MP " << wolf.name << ": " << wolf.mp << endl;
		}
		else
		{
			cout << "Great Wolf has no MP" << endl;
		}
	}
}

void doAllActions(Bishop& bishop, Warrior& warrior, Wolf& wolf)
{	
	if (wolf.hp > 0)
	{
		doWolfAction(wolf, warrior);
	}
	if (warrior.hp > 0)
	{
		doWarroirAction(wolf);
	}
	doBishopAction(bishop, warrior, wolf);
}

void processResult(Warrior& warrior, Wolf& wolf)
{
	if (warrior.hp <= 0)
	{
		cout << "Warrior Noob DEAD!" << endl;
	}
	if (wolf.hp <= 0)
	{
		warrior.deadWolves++;
		wolf.baseAttack++;
		wolf.attack = wolf.baseAttack;

		wolf.maxHp *= 1.1;
		wolf.hp = wolf.maxHp;

		wolf.maxMp *= 1.1;
		wolf.mp = wolf.maxMp;
		wolf.powerBreak = false;

		cout << "Geat Wolf DEAD ='(" << endl;
		cout << "New Great Wolf" << endl;
		cout << "Attack New Wolf: " << wolf.attack << endl;
		cout << "HP New Wolf: " << wolf.hp << endl;
		cout << "MP New Wolf: " << wolf.mp << endl;
	}
}

int main()
{
	Warrior warrior;
	Wolf wolf;
	Bishop bishop;

	initCharacters(warrior, wolf, bishop);
	
	while (warrior.hp > 0)
	{
		drawState(warrior, wolf, bishop);
		doAllActions(bishop, warrior, wolf);
		processResult(warrior, wolf);
	}

	cout << "GAME OVER" << endl;
	cout << warrior.deadWolves << " wolves dead" << endl;
	system("pause");
}