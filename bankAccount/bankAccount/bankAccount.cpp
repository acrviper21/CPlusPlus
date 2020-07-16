// bankAccount.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 07/15/2020
// Description: This program demostrates an account

#include <iostream>
#include <cctype>
#include <iomanip>
#include "Account.h"

// Function prototypes
void displayMenu();
void makeDeposit(Account&);
void withdraw(Account&);

int main()
{
    Account savings;    // Savings account object
    char choice;        // Menus selection

    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    do
    {
        // Display the menu
        displayMenu();
        std::cin >> choice;
        choice = toupper(choice);

        while (choice < 'A' || choice > 'G')
        {
            std::cout << "Please make a choice in the range "
                << "of A through G: ";
            std::cin >> choice;
            choice = toupper(choice);
        }

        // Process the user's selection
        switch (choice)
        {
        case 'A':
            std::cout << "The current balance is $";
            std::cout << savings.getBalance() << std::endl;
            break;
        case 'B':
            std::cout << "There have been " << savings.getTransaction()
                << " transactions." << std::endl;
            break;
        case 'C':
            std::cout << "Interest earned for this period: $";
            std::cout << savings.getInterest() << std::endl;
            break;
        case 'D':
            makeDeposit(savings);
            break;
        case 'E':
            withdraw(savings);
            break;
        case 'F':
            savings.calcInterest();
            std::cout << "Interest added." << std::endl;
        default:
            break;
        }
    } while (choice !='G');

}

// This function displays the user's menu
// on the screen
void displayMenu()
{
    std::cout << std::endl << "\t\tMENU" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "A) Display the account balance" << std::endl;
    std::cout << "B) Display the number of transactions" << std::endl;
    std::cout << "C) Display interest earned for this period" << std::endl;
    std::cout << "D) Make a desposit" << std::endl;
    std::cout << "E) Make a withdrawal" << std::endl;
    std::cout << "F) Add interest for this period" << std::endl;
    std::cout << "G) Exit the program" << std::endl << std::endl;
    std::cout << "Enter your choice: ";
}

// The user is prompted for the dollar amount 
// of the deposit, and the makeDeposit member
// of the Account object is called
void makeDeposit(Account &acnt)
{
    double dollars;

    std::cout << "Enter the amount of the depsoit: ";
    std::cin >> dollars;

    std::cin.ignore();
    acnt.makeDeposit(dollars);
}

// The user is prompted for the dollar amount
// of the withdrawal, and the withdraw member
// of the Account object is then called
void withdraw(Account& acnt)
{
    double dollars;
    
    std::cout << "Enter the amount of the withdrawl: ";
    std::cin >> dollars;
    std::cin.ignore();
    if (!acnt.withdraw(dollars))
    {
        std::cout << "Error: Not enough money in account. " << std::endl << std::endl;
    }
}