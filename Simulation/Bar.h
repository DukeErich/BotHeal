#pragma once

class Bar
{
public:
	int value;
	int maximum;

	void create(int value);
	bool isEmpty() const;
	bool isFull() const;
	float fillFactor() const;
	void removeOverflow();
};
