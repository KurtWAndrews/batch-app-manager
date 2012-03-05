/**
 * @file PartTimeEmployee.h
 * @brief Part time employee class definition
 * @author Brian Royer & Kurt Andrews
 */

#ifndef PARTTIME_H
#define PARTTIME_H

#include "Employee.h"

/**
 * Part time employee Class Definition
 */
class PartTimeEmployee: public Employee
{
  public:
    /**
     * Default Part Time Employee constructor
     */
    PartTimeEmployee();

    PartTimeEmployee(Employee&);

    /**
     * Part Time Employee Destructor
     */
    virtual ~PartTimeEmployee();

    /**
     * Display part-time employee
     */
    virtual void display() const;

    /**
     * @return false because this is a part-time employee
     */
    virtual bool isFullTime() const;

    void startup(std::ifstream& inFile);

    /**
     * saves part-time employee to a file
     * @param outFile - file used to savce part time employees
     */
    virtual void shutdown(std::ofstream& outFile);

  private:
};

#endif