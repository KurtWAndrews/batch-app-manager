/**
 * @file AppManager.cpp
 * @brief AppManager definition
 * @author Kurt Andrews & Brian Royer
 */

#include "AppManager.h"

using namespace std;

/**
 * constructor for AppManager
 */
AppManager::AppManager() : employees(0),
                           teams(0),
                           programs(0) {
	setEmployees(new EmployeeList);
  setTeams(new TeamList);
  setPrograms(new ProgramList);
                             
  startup();
}

/**
 * destructor for AppManager
 */
AppManager::~AppManager() {
  cout << "Executing AppManager Destructor" << endl;
  shutdown();
  
  delete teams;
  delete employees;
  delete programs;
}

void AppManager::setEmployees(EmployeeList* ePtr) {
  delete employees;
  employees = ePtr;
}

void AppManager::setTeams(TeamList *tPtr) {
  delete teams;
  teams = tPtr;
}

void AppManager::setPrograms(ProgramList* pPtr) {
  delete programs;
  programs = pPtr;
}
void AppManager::startup() {
	employees->startup();
  teams->startup(employees);
	programs->startup();
}

void AppManager::shutdown() {
  teams->shutdown();
	employees->shutdown();
	programs->shutdown();
}
