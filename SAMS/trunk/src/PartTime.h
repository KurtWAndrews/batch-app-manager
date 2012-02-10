/**
 * @file PartTime.h
 * @brief Part time employee class definition
 * @author Brian Royer & Kurt Andrews
 */

#ifndef PARTTIME_H
#define	PARTTIME_H

#include "Employee.h"
#include "Account.h"

/**
 * Part time employee Class Definition
 */
class PartTime:public Employee
{
private:
public:
	PartTime();
	~PartTime();
	void startup(std::ifstream& inFile);
	void shutdown(std::ofstream& outFile);
	void clearAttributes();
	void populate();
	void display()const;
};

/**
 * Overload output operation for part time employee object
 */
std:: ostream & operator << (std::ostream & os, const PartTime & p);

#endif