#pragma once

#include <string>
#include "Unit.h"

class Warrior;
class Wolf;

class Bishop : public Unit
{
public:
	int mpDrain;
	
	void heal(Warrior& warrior);
	void drainMp(Wolf& wolf);
	void doAction(Warrior& warrior, Wolf& wolf);
};
