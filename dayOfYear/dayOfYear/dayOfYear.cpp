// dayOfYear.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200504
// Description: This program asks for a month, day, and year and output what the actual number day
//              of the year it is while taking into account the leap years.

#include <iostream>

bool isLeapYear(int intYear);

int main()
{
    //Variables
    int intMonth = 0;
    int intDay = 0;
    int intYear = 0;
    int intDayNumber = 0;
    char ch = '-';

    std::cout << "Enter a date (mm-dd-yyyy): ";
    std::cin >> intMonth >> ch >> intDay >> ch >> intYear;

    //Checks userinput incase they enter the wrong information
    if ((intMonth >= 1 && intMonth <= 12) && (intDay >=1 && intDay <= 31))
    {
        while (intMonth > 1 && intMonth <= 12)
        {
            switch (intMonth - 1)
            {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                intDayNumber += 31;
                break;
            case 4: case 6: case 9: case 11:
                intDayNumber += 30;
                break;
            case 2:
                intDayNumber += 28;
                //If the year is a leapyear it adds an extra day
                if (isLeapYear(intYear))
                {
                    intDayNumber++;
                }
                break;
            default:
                std::cout << "Invalid input.";
                break;
            }
            //Subtracts the month by one until the program his the last month
            intMonth--;
        }
        intDayNumber += intDay;
    }
    std::cout << "The day number is: " << intDayNumber;
    return 0;
}

//Function takes into account the leapyear
bool isLeapYear(int intYear)
{
    bool isLeapYear = false;

    if ((intYear % 4 ==0) && (intYear % 100 !=0))
    {
        isLeapYear = true;
    }
    else if ((intYear % 100 == 0) && (intYear % 400 == 0))
    {
        isLeapYear = true;
    }
    else
    {
        isLeapYear = false;
    }
    return isLeapYear;
}
