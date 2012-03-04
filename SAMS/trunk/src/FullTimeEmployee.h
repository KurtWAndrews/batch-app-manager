/**
 * @file FullTimeEmployee.h
 * @brief Full time employee class definition
 * @author Brian Royer & Kurt Andrews
 */

#ifndef FULLTIME_H
#define FULLTIME_H

#include "Employee.h"
#include "Account.h"

/**
 * Full time employee Class Definition
 */
class FullTimeEmployee: public Employee
{
public:
  FullTimeEmployee();
  FullTimeEmployee(const Employee&);

  virtual ~FullTimeEmployee();
  virtual void startup(std::ifstream& inFile);
  virtual void shutdown(std::ofstream& outFile);
  virtual void clearAttributes();
  Account* getAccount() const;
  void setAccount(Account* _account);
  virtual bool isFullTime() const;
  virtual void makeDeposit();
  virtual void makeWithdrawal();
  virtual void display()const;
private:
  Account* account;
};

inline Account* FullTimeEmployee::getAccount() const {return account;}
inline void FullTimeEmployee::setAccount(Account* _account) {account = _account;}
inline bool FullTimeEmployee::isFullTime() const {return true;}

#endif