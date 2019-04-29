#include "Bar.h"
#include "Unit.h"

void Bar::create(int value)
{
	maximum = this->value = value;
}
bool Bar::isEmpty() const
{
	return value <= 0;
}
void Bar::removeOverflow()
{
	if (value > maximum)
	{
		value = maximum;
	}
}
bool Bar::isFull() const
{
	return value >= maximum;
}

float Bar::fillFactor() const
{
	float k = (float)value / maximum;

	if ( k >= 1)
	{
		return 1;
	}
	if (k <= 0)
	{
		return 0;
	}
	return k;
}