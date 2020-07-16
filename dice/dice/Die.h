#pragma once

class Die
{
private:
	int sides;
	int value;

public:
	Die(int);
	void roll();
	int getSides();
	int getValue();
};

