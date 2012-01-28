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
 * @brief A collection of the employees in the system
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
	 * Start up method to call all necessary methods to read in data
	 */
	void startup();
	
	/**
	 * Shut down method to call all necessary methods to persist data and delete all variables from memory
	 */
	void shutdown();

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
