// primeNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200504
// Description: This program takes in an integer and then checks to see if it's a prime number

#include <iostream>

int main()
{
    //Variables
    int intNum = 0;
    int intdivider = 2;
    
    std::cout << "Enter a number to see if it's a prime number: ";
    std::cin >> intNum;

    //Checks to see if the number is divisible by any other number
    while ((intNum % intdivider !=0) &&(intNum != intdivider))
    {
        intdivider++;
    }
    if (intNum == intdivider)
    {
        std::cout << intNum << " is a prime number.";
    }
    //Takes into 2 being a prime number
    else if (intNum == 2)
    {
        std::cout << intNum << " is a prime number.";
    }
    else
    {
        std::cout << intNum << " is not a prime number.";
    }
    return 0;
}

