/**
 * @file EmployeeList.h
 * @brief EmployeeList declaration
 * @author Kurt Andrews & Brian Royer
 */

#ifndef EMPLOYEELIST_H_
#define EMPLOYEELIST_H_

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

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
   * manage the employee's benefits account
   */
  void manageBenefits();

  /**
   * change an employee in the collection
   */
  void changeEmployee();

  /**
   * display the collection of system employees
   */
  void display() const;
  
  /**
   * @return true if the employee list is empty; false otherwise
   */
  bool empty() const;
  
  /**
   * @return the pointer to the employee object that has employeeId == _employeeId
   * or null if no match is found
   */
  Employee* find(const std::string& _employeeId);
  
  /**
   * @return true if the employee list contains at least one full-time employee, 
   * otherwise return false
   */
  bool hasFullTimeEmployee() const;
  
  /**
   * remove an employee from the collection
   */
  void removeEmployee();

  /**
   * Select an employee from the employee list
   * @return a pointer to the selected employee
   */
  Employee* selectEmployee();
  
  /**
	 * Start up method to call all necessary methods to read in data
	 */
	void startup();
	
	/**
	 * Shut down method to call all necessary methods to persist data and delete 
   * all variables from memory
	 */
	void shutdown();
  

  
private:
  std::map<std::string, Employee*> employees;
};

inline bool EmployeeList::empty() const {return(employees.empty());}

#endif /* EMPLOYEELIST_H_ */
