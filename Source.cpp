#include <iostream>
#include <string>
#include <vector>
#include "BankAccount.h"

// 	cin.clear();
//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
// this error catch used throughout the program first clears the error flags in the input stream and then the big guy ensures that any and all unwanted characters in the input is discarded, including the new line

using namespace std;

int main()
{
	int choice = 0; // used for the main switch menu
	string name;	// used for account name in main
	double deposit; // used for deposit info in main
	double withdraw;// used for withdraw info in main

	int accountChoice = 0;	// changes according to which account the user wants to access

	vector<BankAccount> accounts;	// a vector of the bankAccount class

	do
	{
		cout << "1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Balance\n5. Exit \n";

		cin >> choice;

		switch (choice) 
		{
		//CREATE ACCOUNT CASE
		case 1:
			// old habit I implement in switch cases that utilize getline to ensure we dont skip the getline
			cin.clear();
			cin.ignore();
			//

			cout << "What is the account holder's name? ";
			getline(cin, name);

			cout << "Enter initial deposit: ";
			cin >> deposit;
			accounts.emplace_back(name, deposit); //create a new object of the class with the information provided
			break;

		//DEPOSIT CASE
		case 2:
			//ask user which account they'd like to deposit money into
			cout << "Which account would you like to access?\n";

			//for loop to display account names
			for (int i = 0; i < accounts.size(); i++)
			{
				cout << i + 1 << ". " << accounts[i].getAccountName() << endl;
			}
			//gets user choice and minus 1 to account for 0 start
			cin >> accountChoice;
			accountChoice -= 1;
			
			//error catch to ensure account choice is in range of vector
			if (cin.fail() || accountChoice > accounts.size())
			{
				cout << "Entry not found in list of options. Please choose a valid option.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> accountChoice;
				accountChoice -= 1;
			}

			cout << "\nYou are now working with the account belonging to " << accounts[accountChoice].getAccountName() << endl;

			//asks how much money they'd like to deposit
			cout << "how much money would you like to deposit into " << accounts[accountChoice].getAccountName() << "'s acccount? ";
			
			//gets the user input
			cin >> deposit;

			if (cin.fail() || deposit <= 0)
			{
				cout << "Invalid input. Please enter a positive number to deposit.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cin >> deposit;
			}

			//calls the proper method of the correct object to add the money
			accounts[accountChoice].deposit(deposit);
			break;

		//WITHDRAW CASE
		case 3:
			//ask user which account they'd like to withdraw money from
			cout << "Which account would you like to access?\n";

			//for loop to display account names
			for (int i = 0; i < accounts.size(); i++)
			{
				cout << i + 1 << ". " << accounts[i].getAccountName() << endl;
			}
			//gets user choice and minus 1 to account for 0 start
			cin >> accountChoice;
			accountChoice -= 1;

			//ensure user chose a valid choice within the vector size

			if (cin.fail() || accountChoice > accounts.size())
			{
				cout << "Entry not found in list of options. Please choose a valid option.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cin >> accountChoice;
				accountChoice -= 1;
			}

			cout << "\nYou are now working with the account belonging to " << accounts[accountChoice].getAccountName() << endl;

			cout << "How much money would you like to withdraw from " << accounts[accountChoice].getAccountName() << "'s acccount? ";
			
			cin >> withdraw;

			if (cin.fail() || withdraw <= 0)
			{
				cout << "Invalid input. Please enter a positive value to withdraw.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cin >> withdraw;
			}

			accounts[accountChoice].withdraw(withdraw);
			break;

		//CHECK BALANCE CASE
		case 4:
			//ask user which account they'd like to check the balance
			cout << "Which account would you like to access?\n";

			//for loop to display account names
			for (int i = 0; i < accounts.size(); i++)
			{
				cout << i + 1 << ". " << accounts[i].getAccountName() << endl;
			}
			//gets user choice and minus 1 to account for 0 start
			cin >> accountChoice;
			accountChoice -= 1;

			//ensure user chose a valid choice within the vector size

			if (cin.fail() || accountChoice > accounts.size())
			{
				cout << "Entry not found in list of options. Please choose a valid option.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> accountChoice;
				accountChoice -= 1;
			}

			cout << "\nYou are now working with the account belonging to " << accounts[accountChoice].getAccountName() << endl;

			//full printout of account info accessed
			cout << "             ACCOUNT INFO:             " << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Account Holder name: " << accounts[accountChoice].getAccountName() << endl;
			cout << "Account Balance:     " << accounts[accountChoice].getBalance() << endl;
			cout << "Account Balance:     " << accounts[accountChoice].getAccountNum() << endl;
			cout << "\n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		}



	} while (choice != 5);

	cout << "Thanks for using the Ricky Ramirez Radical Bank!";
	return 0;
}