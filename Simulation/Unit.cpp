#include "Unit.h"
#include "Geometry.h"

bool canAttack(const Unit& unit1, const Unit& unit2)
{
	return checkDistance(unit1.position, unit2.position);
}

bool Unit::canAttack(const Unit& other)
{
	return checkDistance(position, other.position);
}