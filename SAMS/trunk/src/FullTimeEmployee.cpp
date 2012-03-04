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
FullTimeEmployee::FullTimeEmployee() : Employee()
{
  cout << "Executing FullTimeEmployee() default constructor" << endl;
  setAccount(new Account());
}

FullTimeEmployee::FullTimeEmployee(const Employee& e) : Employee(e.getEmployeeId(),
                                                                 e.getFirstName(),
                                                                 e.getLastName(),
                                                                 e.getPrefName(),
                                                                 e.getEmailAddress(),
                                                                 e.getTeam())
{
  cout << "Executing FullTimeEmployee(const Employee& e) copy constructor" << endl;
  setAccount(new Account());
}

/**
 * Full-Time Employee Destructor
 */
FullTimeEmployee::~FullTimeEmployee()
{
  cout << "Executing Full Time Employee's Destructor" << endl;
  
  if (account != NULL) {
    delete account;
  }
}

void FullTimeEmployee::clearAttributes()
{
  account->setBalance(0.00);
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
  cout << "Employee Status:\tFull-Time" << endl;
  cout << "Benefit Account Balance: $" << account->getBalance() << endl;
}

void FullTimeEmployee::startup(ifstream& inFile)
{
  Employee::startup(inFile);
  
  string _accountId,
  _desc,
  _balance;
  
  getline(inFile, _accountId, '|');
  getline(inFile, _desc, '|');
  getline(inFile, _balance, '|');
  
  double balance;
  istringstream stm;
  
  stm.str(_balance);
  stm >> balance;
  
  account->setAccountId(_accountId);
  account->setDesc(_desc);
  account->setBalance(balance);
}

void FullTimeEmployee::shutdown(ofstream& outFile)
{
  outFile << "F|";
  Employee::shutdown(outFile);
  outFile << account->getAccountId() << '|'
  << account->getDesc() << '|'
  << account->getBalance() << '|' << endl;
}
