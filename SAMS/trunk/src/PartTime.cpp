/**
 * @file PartTime.cpp
 * @brief Part Time Employee class member function definitions
 * @author Brian Royer & Kurt Andrews
 */

#include "PartTime.h"

using namespace std;

/**
 * Default Part Time Employee constructor
 */
PartTime::PartTime() : Employee()
{
}

/**
 * Employee Destructor
 */
PartTime::~PartTime()
{
}

void PartTime::clearAttributes()
{
	Employee::clearAttributes();
}

/**
 * Retrieves employee information from user to populate an part time employee object
 * Returns a pointer to the new employee object
 */
void PartTime::populate()
{
	setFullTime(false);
	Employee::populate();
}

/**
 * Displays a Part Time Employee object
 */
void PartTime::display() const
{
	Employee::display();
}

void PartTime::startup(ifstream& inFile)
{
	setFullTime(false);
	Employee::startup(inFile);
}

void PartTime::shutdown(ofstream& outFile)
{
	outFile << "0|";
	Employee::shutdown(outFile);
}

std:: ostream & operator << (std::ostream & os, const PartTime & p)
{
	p.display();
	return os;
}