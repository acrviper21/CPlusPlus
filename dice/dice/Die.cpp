#include "Die.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

//The constructor accepts an arguent for
//the number of sides for the die and
//performs a roll.
Die::Die(int numSides)
{
	unsigned seed = time(NULL);

	srand(seed);

	sides = numSides;

	roll();
}

//This function simulates the rolling
//of a die.
void Die::roll()
{
	//Minimum die value
	const int MIN_VALUE = 1;
	
	//Get random value for die
	value = (rand() % (sides - MIN_VALUE + 1) + MIN_VALUE);
}

//The getSides function returns the number
//for this die.
int Die::getSides()
{
	return sides;
}

//The getValue function returns the die's value
int Die::getValue()
{
	return value;
}