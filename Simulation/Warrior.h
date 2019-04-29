#pragma once

#include "Unit.h"

class Wolf;

class Warrior : public Unit
{
public:
	int deadWolves;

	void powerBreak(Wolf& wolf);
	void attack(Wolf& wolf);
	void doAction(Wolf& wolf);
};