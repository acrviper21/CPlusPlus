#include "Account.h"

Account::Account()
{
	balance = 0.00;
	interest = 0.00;
	transactions = 0;
}

Account::Account(double bal = 0)
{
	balance = bal;
	interest = 0;
	transactions = 0;
}

Account::~Account()
{

}

void Account::makeDeposit(double amount)
{
	balance += amount;
	transactions++;
}

bool Account::withdraw(double amount)
{
	if (balance < amount)
	{
		return false;
	}
	else
	{
		balance -= amount;
		transactions++;
		return true;
	}
}

void Account::calcInterest()
{
	interest = balance * getInterestRate();
	balance += interest;
}

double Account::getInterestRate()
{
	return interestRate;
}

double Account::getBalance()
{
	return balance;
}

double Account::getInterest()
{
	return interest;
}

int Account::getTransaction()
{
	return transactions;
}
