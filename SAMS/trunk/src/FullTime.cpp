/**
 * @file FullTime.cpp
 * @brief Full Time Employee class member function definitions
 * @author Brian Royer & Kurt Andrews
 */

#include <sstream>
#include "FullTime.h"

using namespace std;

/**
 * Default Full Time Employee constructor
 */
FullTime::FullTime() : Employee()
{
	account = new Account(getEmployeeId() + "B", "Benefits Account");
}

/**
 * Employee Destructor
 */
FullTime::~FullTime()
{
	cout << "Executing Full Time Employee's Destructor" << endl;
}

void FullTime::clearAttributes()
{
	delete account;
	Employee::clearAttributes();
}

/**
 * Retrieves employee information from user to populate an full time employee object
 * Returns a pointer to the new employee object
 */
void FullTime::populate()
{
	setFullTime(true);
	Employee::populate();
}

void FullTime::deposit()
{
	system("cls");
	double amount;
	cout << getEmployeeId() << " - " << getFirstName() << " " << getLastName() << endl << endl;
	cout << "Current Balance: " << account->getBalance() << endl << endl;
	cout << "How much would you like to deposit? $";
	cin >> amount;
	account->deposit(amount);
}

void FullTime::withdraw()
{
	system("cls");
	double amount;
	cout << getEmployeeId() << " - " << getFirstName() << " " << getLastName() << endl << endl;
	cout << "Current Balance: $" << account->getBalance() << endl << endl;

	if(account->getBalance() > 0)
	{
		cout << "How much would you like to withdraw? $";
		cin >> amount;
		account->withdraw(amount);
	}
	else
	{
		cout << "Employee must have a positive balance to withdraw." << endl;
		cin.ignore();
	}
}

void FullTime::display() const
{
	Employee::display();
	cout << "Benefit Account Balance: $" << account->getBalance() << endl;
}

void FullTime::startup(ifstream& inFile)
{
	string _balance;
	double balance;
	std::istringstream stm;

	getline(inFile, _balance, '|');
	stm.str(_balance);
	stm >> balance;

	account->setBalance(balance);

	setFullTime(true);
	Employee::startup(inFile);
}

void FullTime::shutdown(ofstream& outFile)
{
	outFile << "1|"
					<< account->getBalance() << '|';
	Employee::shutdown(outFile);
}

std:: ostream & operator << (std::ostream & os, const FullTime & f)
{
	f.display();
	return os;
}