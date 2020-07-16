#pragma once
#include <iostream>

class Account
{
private:
	double balance;
	double interestRate = 0.045;
	double interest;
	int transactions;
public:
	Account();
	Account(double);
	~Account();
	void makeDeposit(double);
	bool withdraw(double);
	void calcInterest();
	double getInterestRate();
	double getBalance();
	double getInterest();
	int getTransaction();
};

