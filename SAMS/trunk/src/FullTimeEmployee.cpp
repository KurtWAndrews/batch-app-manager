/**
 * @file FullTimeEmployee.cpp
 * @brief Full Time Employee class member function definitions
 * @author Brian Royer & Kurt Andrews
 */

#include <sstream>
#include "FullTimeEmployee.h"

using namespace std;

/**
 * Default Full Time Employee constructor
 */
FullTimeEmployee::FullTimeEmployee() : Employee(),
  account(new Account()),
  address(new StreetAddress())

{
}

FullTimeEmployee::FullTimeEmployee(const Employee& e) : Employee(e.getEmployeeId(),
      e.getFirstName(),
      e.getLastName(),
      e.getPrefName(),
      e.getEmailAddress(),
      e.getTeam()),
  account(new Account()),
  address(new StreetAddress())
{
}

/**
 * Full-Time Employee Destructor
 */
FullTimeEmployee::~FullTimeEmployee()
{
  if (account != NULL) {
    delete account;
  }

  if (address != NULL) {
    delete address;
  }
}

void FullTimeEmployee::clearAttributes()
{
  account->setBalance(0.00);
  address->clearAttributes();
  Employee::clearAttributes();
}

void FullTimeEmployee::makeDeposit()
{
  system("cls");
  double amount;
  cout << getEmployeeId() << " - " << getFirstName() << " " << getLastName() << endl << endl;
  cout << "Current Balance: " << account->getBalance() << endl << endl;
  cout << "How much would you like to deposit? $";
  cin >> amount;
  account->makeDeposit(amount);
}

void FullTimeEmployee::makeWithdrawal()
{
  system("cls");
  double amount;
  cout << getEmployeeId() << " - " << getFirstName() << " " << getLastName() << endl << endl;
  cout << "Current Balance: $" << account->getBalance() << endl << endl;

  double oldBalance = account->getBalance();
  cout << "How much would you like to withdraw? $";
  cin >> amount;
  account->makeWithdrawal(amount);

  if (oldBalance == account->getBalance()) {
    cout << "There is not enough money in the account to withdraw " << amount << endl;
    cin.ignore();
  }
}

void FullTimeEmployee::display() const
{
  Employee::display();
  getAddress()->display();
  cout << "Employee Type:\t" << (isTemporaryEmployee() ? "Temporary Full-Time" : "Regular Full-Time") << endl;
  cout << "Benefit Account Balance: $" << account->getBalance() << endl;
}

void FullTimeEmployee::populate()
{
  Employee::populate();
  getAddress()->populate();

  cout << "(R)egular full-time or (T)emporary full-time? (r/t): ";
  char _temp;
  cin.get(_temp);
  cin.ignore();

  if (tolower(_temp) == 't') {
    setTemporaryEmployee(true);
  } else {
    setTemporaryEmployee(false);
  }
}

void FullTimeEmployee::startup(ifstream& inFile)
{
  Employee::startup(inFile);
  getAddress()->startUp(inFile);

  string _accountId, _desc, _balance, _tempEmployee, _eol;

  getline(inFile, _accountId, '|');
  getline(inFile, _desc, '|');
  getline(inFile, _balance, '|');
  getline(inFile, _tempEmployee, '|');
  getline(inFile, _eol);

  double balance;
  istringstream stm;

  stm.str(_balance);
  stm >> balance;

  account->setAccountId(_accountId);
  account->setDesc(_desc);
  account->setBalance(balance);

  if (_tempEmployee == "T") {
    setTemporaryEmployee(true);
  } else {
    setTemporaryEmployee(false);
  }
}

void FullTimeEmployee::shutdown(ofstream& outFile)
{
  outFile << "F|";
  Employee::shutdown(outFile);
  getAddress()->shutDown(outFile);
  outFile << account->getAccountId() << '|'
          << account->getDesc() << '|'
          << account->getBalance() << '|'
          << (isTemporaryEmployee() ? "T" : "R") << '|' << endl;
}
