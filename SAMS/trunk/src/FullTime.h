/**
 * @file FullTime.h
 * @brief Full time employee class definition
 * @author Brian Royer & Kurt Andrews
 */

#ifndef FULLTIME_H
#define	FULLTIME_H

#include "Employee.h"
#include "Account.h"

/**
 * Full time employee Class Definition
 */
class FullTime:public Employee
{
private:
	Account* account;
public:
	FullTime();
	~FullTime();
	void startup(std::ifstream& inFile);
	void shutdown(std::ofstream& outFile);
	void clearAttributes();
	void populate();
	void deposit();
	void withdraw();
	void display()const;
};

/**
 * Overload output operation for full time employee object
 */
std:: ostream & operator << (std::ostream & os, const FullTime & f);

#endif