// CableCompany.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200422
// Description: This program calculates customers charges based on businesses or residentials
//              with other variables involved.

#include <iostream>
#include <iomanip>
using namespace std;
//Residential fees
const double RES_BILL_PROC_FEES = 4.50;
const double RES_BASIC_SERV_COST = 20.50;
const double RES_COST_PREM_CHANNEL = 7.50;
//Business fees
const double BUS_BILL_PROC_FEES = 15.00;
const double BUS_BASIC_SERV_COST = 75.00;
const double BUS_BASIC_CONN_COST = 5.00;
const double BUS_COST_PREM_CHANNEL = 50.00;

double residential();
double business();

int main()
{
    //Variables
    int accountNumber;
    char customerType;
    double amountDue;

    cout << fixed << showpoint;
    cout << setprecision(2);

    cout << "This program computes a cable bill." << endl;
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << endl;

    cout << "Enter customer type : R, r "
        << "(Residential), B, b (business): ";
    cin >> customerType;
    cout << endl;
    
    //Calls the function based on what type of customer they are
    switch (customerType)
    {
    case 'r': case 'R':
        amountDue = residential();
        cout << "Account number = "
            << accountNumber << endl;
        cout << "Amount Due = $"
            << amountDue << endl;
        break;
    case 'b': case 'B':
        amountDue = business();
        cout << "Account number = "
            << accountNumber << endl;
        cout << "Amount Due = $"
            << amountDue << endl;
        break;
    default:
        cout << "Invalid customer type." << endl;
        break;
    }
    return 0;
}

//Function to calculate residential prices
double residential()
{
    int noOfPChannels = 0;
    double bAmount = 0;

    cout << "Enter the number of premium "
        << "channels used: ";
    cin >> noOfPChannels;
    cout << endl;

    bAmount = RES_BILL_PROC_FEES + RES_BASIC_SERV_COST +
        noOfPChannels * RES_COST_PREM_CHANNEL;
    return bAmount;
}
//Function to calculate businesses price
double business()
{
    int noOfBasicServiceConnections = 0;
    int noOfPChannels = 0;
    double bAmount = 0;

    cout << "Enter the number of basic "
        << "service connections: ";
    cin >> noOfBasicServiceConnections;
    cout << endl;
    cout << "Enter the numner of premium "
        << "channels used: ";
    cin >> noOfPChannels;
    cout << endl;

    if (noOfBasicServiceConnections <= 10)
    {
        bAmount = BUS_BILL_PROC_FEES + BUS_BASIC_SERV_COST
            + noOfPChannels * BUS_COST_PREM_CHANNEL;
    }
    else
    {
        bAmount = BUS_BILL_PROC_FEES + BUS_BASIC_SERV_COST +
            (noOfBasicServiceConnections - 10) * BUS_BASIC_CONN_COST
            + noOfPChannels * BUS_COST_PREM_CHANNEL;
    }
    return bAmount;
}