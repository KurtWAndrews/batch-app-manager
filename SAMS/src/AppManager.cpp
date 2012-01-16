/**
 * @file AppManager.cpp
 * @brief AppManager definition
 */

#include "AppManager.h"

using namespace std;

/**
 * constructor for AppManager
 */
AppManager::AppManager() : employees(0) {
	setEmployees(new EmployeeList);
}

/**
 * destructor for AppManager
 */
AppManager::~AppManager() {
  cout << "Executing AppManager Destructor" << endl;
  delete employees;
}

void AppManager::setEmployees(EmployeeList* ePtr) {
  delete employees;
  employees = ePtr;
}
