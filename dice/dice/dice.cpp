// dice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Die.h"

int main()
{
    const int DIE1_SIDES = 6;   //Number of sides for die #1
    const int DIE2_SIDES = 12;  //Number of sides for die #2
    const int MAX_ROLLS = 5;    //Number of times to roll

    //Create two instances of the Die class
    Die die1(DIE1_SIDES);
    Die die2(DIE2_SIDES);

    std::cout << "This simulates the rolling of a "
        << die1.getSides() << " sided die and a "
        << die2.getSides() << " sided die." << std::endl;

    std::cout << "Initial value fo the dice:" << std::endl;
    std::cout << die1.getValue() << " " << die2.getValue() << std::endl;

    //Roll the dice five times
    std::cout << "Rolling the dice " << MAX_ROLLS
        << " times." << std::endl;
    for (int count = 0; count < MAX_ROLLS; count++)
    {
        die1.roll();
        die2.roll();

        std::cout << die1.getValue() << " "
            << die2.getValue() << std::endl;
    }
}


