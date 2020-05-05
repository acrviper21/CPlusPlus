// payRate.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200501
// Description: This program takes user input for the name and hours to calculate salary

#include <iostream>
#include <string>

int main()
{
    //Variables
    std::string strName = "";
    double dblPayRate = 0.00;
    double dblHoursWorked = 0.00;
    double dblSalary = 0.00;

    //Gathers employees information
    std::cout << "Enter your name: ";
    std::getline(std::cin, strName);
    std::cout << "Enter the pay rate: $";
    std::cin >> dblPayRate;
    std::cout << "Enter the hours worked: ";
    std::cin >> dblHoursWorked;
    
    dblSalary = dblPayRate * dblHoursWorked;

    //Outputs employees information
    std::cout << "Name: " << strName << std::endl;
    std::cout << "Pay Rate: $" << dblPayRate << std::endl;
    std::cout << "Hours Worked: " << dblHoursWorked << std::endl;
    std::cout << "Salary: $" << dblSalary << std::endl;
    
    return 0;
}
