#include "Warrior.h"
#include "Wolf.h"
#include <iostream>

void Warrior::powerBreak(Wolf& wolf)
{
	if (!canAttack(wolf))
	{
		std::cout << "Too far to use Power Break" << std::endl;
		return;
	}
	if (wolf.powerBreak)
	{
		printf("Power Break is already applied\n");
		return;
	}
	printf("Use Power Break\n");
	wolf.attack /= 2;
	wolf.powerBreak = true;
}

void Warrior::attack(Wolf& wolf)
{
	if (!canAttack(wolf))
	{
		std::cout << "Too far to attack" << std::endl;
		return;
	}
	printf("Warrior attacks\n");
	wolf.hp.value -= 10;
	std::cout << wolf.name << " HP: " << wolf.hp.value << std::endl;
}

void Warrior::doAction(Wolf& wolf)
{
	if (canAttack(wolf))
	{
		if (!wolf.powerBreak)
		{
			std::cout << "Warrior use Power break" << std::endl;
			powerBreak(wolf);
			return;
		}
		attack(wolf);
	}
	else
	{
		std::cout << "Warrior moves" << std::endl;
		if (position < wolf.position)
		{
			position += 25;
			return;
		}
		position -= 25;
	}
}
