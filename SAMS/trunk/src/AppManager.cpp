/**
 * @file AppManager.cpp
 * @brief AppManager definition
 * @author Kurt Andrews & Bryan Royer
 */

#include "AppManager.h"

using namespace std;

/**
 * constructor for AppManager
 */
AppManager::AppManager() : employees(0),
                           teams(0) {
	setEmployees(new EmployeeList);
  setTeams(new TeamList);
}

/**
 * destructor for AppManager
 */
AppManager::~AppManager() {
  cout << "Executing AppManager Destructor" << endl;
  delete employees;
  delete teams;
}

void AppManager::setEmployees(EmployeeList* ePtr) {
  delete employees;
  employees = ePtr;
}

void AppManager::setTeams(TeamList* tPtr) {
  delete teams;
  teams = tPtr;
}
