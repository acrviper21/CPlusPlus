// CalculatorMimic.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200502
// Description: This program takes userinput and mimics a calculator based on the output.

#include <iostream>
#include <iomanip>

int main()
{
    //Variables
    double x = 0.0;
    double y = 0.0;
    char charOperator = '*';

    std::cout << std::fixed << std::showpoint << std::setprecision(3);

    std::cout << "Enter the first number: ";
    std::cin >> x;
    std::cout << "Enter the second Number: ";
    std::cin >> y;

    //Displays the functions you can do with the calculator
    std::cout << "Addition: +" << "\nSubtraction: -"
        << "\nMultiplication: *" << "\nDivision: /" << "\nEnter your choice of operations: ";
    std::cin >> charOperator;

    //Determines which operation to perform with the operator symbol
    switch (charOperator)
    {
    case '+':
        std::cout << x << " " << charOperator << " " << y << " " << "=" << " " << x + y;
        break;
    case '-':
        std::cout << x << " " << charOperator << " " << y << " " << "=" << " " << x - y;
        break;
    case '*':
        std::cout << x << " " << charOperator << " " << y << " " << "=" << " " << x * y;
        break;
    case '/':
        //Handles divison of zero
        if (x/y == 0)
        {
            std::cout << "Sorry you can't divide by zero: Undefined";
        }
        else
        {
            std::cout << x << " " << charOperator << " " << y << " " << "=" << " " << x / y;
        }
        break;
    default:
        std::cout << "That's not an appropiate function";
        break;
    }
}

