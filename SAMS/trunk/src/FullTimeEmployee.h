/**
 * @file FullTimeEmployee.h
 * @brief Full time employee class definition
 * @author Brian Royer & Kurt Andrews
 */

#ifndef FULLTIME_H
#define FULLTIME_H

#include "Employee.h"
#include "Account.h"
#include "StreetAddress.h"

/**
 * Full time employee Class Definition
 */
class FullTimeEmployee: public Employee
{
  public:
    FullTimeEmployee();
    FullTimeEmployee(const Employee&);

    virtual ~FullTimeEmployee();
    void startup(std::ifstream& inFile);
    virtual void shutdown(std::ofstream& outFile);
    void clearAttributes();
    Account* getAccount() const;
    void setAccount(Account* _account);
    StreetAddress* getAddress() const;
    void setAddress(StreetAddress* _address);
    bool isTemporaryEmployee() const;
    void setTemporaryEmployee(bool _tempEmployee);
    bool isFullTime() const;
    void makeDeposit();
    void makeWithdrawal();
    void populate();
    virtual void display() const;
  private:
    Account* account;
    StreetAddress* address;
    bool temporaryEmployee;
};

inline Account* FullTimeEmployee::getAccount() const {return account;}
inline void FullTimeEmployee::setAccount(Account* _account) {account = _account;}
inline StreetAddress* FullTimeEmployee::getAddress() const {return address;}
inline void FullTimeEmployee::setAddress(StreetAddress* _address) {address = _address;}
inline bool FullTimeEmployee::isFullTime() const {return true;}
inline bool FullTimeEmployee::isTemporaryEmployee() const {return temporaryEmployee;}
inline void FullTimeEmployee::setTemporaryEmployee(bool _tempEmployee) {temporaryEmployee = _tempEmployee;}

#endif