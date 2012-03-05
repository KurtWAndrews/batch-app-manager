/**
 * @file Account.cpp
 * @brief Account definition
 * @author Kurt Andrews & Brian Royer
 */

#include "Account.h"

using namespace std;

Account::Account(const string& _accountId,
                 const string& _desc,
                 const double _balance)
{
  setAccountId(_accountId);
  setDesc(_desc);
  setBalance(_balance);
}

Account::~Account()
{
}

void Account::makeWithdrawal(const double amount)
{
  if ((balance - amount) >= 0.0) {
    setBalance(balance - amount);
  }
}
