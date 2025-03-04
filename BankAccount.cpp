#include "BankAccount.h"
#include <string>


BankAccount::BankAccount(string name, double deposit)
{



	accountHolderName = name;
	// gets a random account number to be made
	srand(time(0));
	acccountNumber = 1 + (rand() % (99999));
	//-----------------------------------------
	accountBalance = deposit;

	cout << "Account created succesfully!" << endl;
	cout << "Account Holder name:      " << accountHolderName << endl;
	cout << "Account Number:           " << acccountNumber << endl;
	cout << "Account starting Balance: $" << accountBalance << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}

void BankAccount::deposit(double amt)
{

	accountBalance += amt;
	cout << "\nYou deposited $" << amt << " making your account balance now $" << getBalance() << endl;
}

void BankAccount::withdraw(double amt)
{
	if (amt <= accountBalance)
	{
		accountBalance -= amt;
		cout << "\nYou withdrew $" << amt << " leaving a balance of $" << getBalance() << endl;
	}
	else
	{
		cout << "\n>> Insufficient funds in account <<\n";
	}

}

double BankAccount::getBalance()
{
	return accountBalance;
}

string BankAccount::getAccountName()
{
	return accountHolderName;
}

int BankAccount::getAccountNum()
{
	return acccountNumber;
}
