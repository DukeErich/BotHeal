#pragma once

#include <string>
#include "Unit.h"

class Warrior;

class Wolf : public Unit
{
public:
	void doAction(Warrior& warrior);
};

