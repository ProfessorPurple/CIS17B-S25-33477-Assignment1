#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
//#include <string>
using namespace std;

class BankAccount
{
private:
	string accountHolderName;
	int acccountNumber;
	double accountBalance;

public:
	BankAccount(string, double);

	void deposit(double);
	void withdraw(double);
	double getBalance();
	string getAccountName();
	int getAccountNum();


};

#endif