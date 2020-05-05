// monthlyPayCheck.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200501
// Description: This program outputs an employees salary and then the netpay after deductions

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    //Variables
    std::string strName = "";
    double dblHoursWorked = 0.0;
    double dblPayRate = 0.0;
    double dblGrossAmount = 0.0;
    double dblNetPay = 0.0;
    double dblFederalIncomeTax = 0.15;
    double dblStateTax = 0.035;
    double dblSocialSecurityTax = 0.0575;
    double dblMedicaidTax = 0.0275;
    double dblPensionPlanTax = 0.05;
    double dblHealthInsurance = 75.00;
    
    std::cout << std::setprecision(2) << std::fixed;

    //Takes in employees information
    std::cout << "Enter the employees name: ";
    std::getline(std::cin, strName);
    std::cout << "Enter the pay rate: ";
    std::cin >> dblPayRate;
    std::cout << "Enter the number of hours worked: ";
    std::cin >> dblHoursWorked;

    dblGrossAmount = dblPayRate * dblHoursWorked;

    std::cout << strName << std::endl;
    
    //Formats the output of the employees information and the results on the right side
    std::cout << std::setfill('.') << std::left << std::setw(35) << "Gross Amount: " << "$" 
        << std::setfill(' ') << std::right << std::setw(7) <<dblGrossAmount << std::endl;
    std::cout << std::setfill('.') << std::left << std::setw(35) << "Federal Tax: " << "$"
        << std::setfill(' ') << std::right << std::setw(7) << (dblGrossAmount * dblFederalIncomeTax) << std::endl;
    std::cout << std::setfill('.') << std::left << std::setw(35) << "State Tax: " << "$"
        << std::setfill(' ') << std::right << std::setw(7) << (dblGrossAmount * dblStateTax) << std::endl;
    std::cout << std::setfill('.') << std::left << std::setw(35) << "Social Security Tax: " << "$"
        << std::setfill(' ') << std::right << std::setw(7) << (dblGrossAmount * dblSocialSecurityTax) << std::endl;
    std::cout << std::setfill('.') << std::left << std::setw(35) << "Medicare/Medicaid Tax: " << "$"
        << std::setfill(' ') << std::right << std::setw(7) << (dblGrossAmount * dblMedicaidTax) << std::endl;
    std::cout << std::setfill('.') << std::left << std::setw(35) << "Pension Plan: " << "$"
        << std::setfill(' ') << std::right << std::setw(7) << (dblGrossAmount * dblPensionPlanTax) << std::endl;
    std::cout << std::setfill('.') << std::left << std::setw(35) << "Health Insurance: " << "$"
        << std::setfill(' ') << std::right << std::setw(7) << (dblHealthInsurance) << std::endl;

    dblNetPay = dblGrossAmount - ((dblGrossAmount * dblFederalIncomeTax) + (dblGrossAmount * dblStateTax) +
        (dblGrossAmount * dblSocialSecurityTax) + (dblGrossAmount * dblMedicaidTax) +
        (dblGrossAmount * dblPensionPlanTax) + dblHealthInsurance);

    std::cout << std::setfill('.') << std::left << std::setw(35) << "Net Pay: " << "$"
        << std::setfill(' ') << std::right << std::setw(7) << (dblNetPay) << std::endl;
    return 0;
}
