/**
 * @file EmployeeList.h
 * @brief EmployeeList declaration
 */

#ifndef EMPLOYEELIST_H_
#define EMPLOYEELIST_H_

#include "Employee.h"

#include <map>
#include <string>
#include <iostream>
#include <fstream>

/**
 * @brief A collection of the of employees in the system
 */
class EmployeeList {
public:
  /**
   * default constructor for EmployeeList
   */
  EmployeeList();

  /**
   * EmployeeList destructor
   */
  virtual ~EmployeeList();

  /**
   * add an employee to the collection
   */
  void addEmployee();

  /**
   * change an employee in the collection
   */
  void changeEmployee();

  /**
   * remove an employee from the collection
   */
  void removeEmployee();

  /**
   * display the collection of system employees
   */
  void display() const;

private:
  std::map<std::string, Employee*> employees;
};

#endif /* EMPLOYEELIST_H_ */
