/**
 * @file AppManager.h
 * @brief AppManager declaration
 * @author Kurt Andrews & Brian Royer
 */

#ifndef APPMANAGER_H_
#define APPMANAGER_H_

#include "EmployeeList.h"
#include "TeamList.h"

#include <string>
#include <iostream>
#include <fstream>

/**
 * @brief The AppManager class functions as the facade for the entire SAMS system.
 *
 * The main entry point for all of the system functionality and delegates system
 * operations to the appropriate objects in the system
 */
class AppManager {
public:
	/**
	 * Default AppManager constructor
	 */

  AppManager();

  /**
   * AppManager Destructor
   */
  virtual ~AppManager();

  // accessor methods

  /**
   * @return the system employee list
   */
  EmployeeList* getEmployees() const;

  /**
   * @return the system team list
   */
  TeamList* getTeams() const;
  
  // modifier methods

  /**
   * replace the employee list with the specified value
   * @param ePtr - the pointer to the new system employee list
   */
  void setEmployees(EmployeeList* ePtr);

  /**
   * replace the team list with the specified value
   * @param tPtr - the pointer to the new system team list
   */
  void setTeams(TeamList* tPtr);
  
  // system functions

  /**
   * add employees to the system
   */
  void addEmployees();

  /**
   * change employee information
   */
  void changeEmployees();

  /**
   * remove employees from the system
   */
  void removeEmployees();

  /**
   * display all employees in the employee list
   */
  void displayEmployees();

  /**
   * add teams to the system
   */
  void addTeams();
  
  /**
   * change team information
   */
  void changeTeams();
  
  /**
   * remove teams from the system
   */
  void removeTeams();
  
  /**
   * display all teams in the employee list
   */
  void displayTeams();
  
private:
  EmployeeList* employees;
  TeamList* teams;
};

// accessor method definitions
inline EmployeeList* AppManager::getEmployees() const {return employees;}
inline TeamList* AppManager::getTeams() const {return teams;}

// delligated system operations
inline void AppManager::addEmployees() {employees->addEmployee();}
inline void AppManager::changeEmployees() {employees->changeEmployee();}
inline void AppManager::removeEmployees() {employees->removeEmployee();}
inline void AppManager::displayEmployees() {employees->display();}
inline void AppManager::addTeams() {teams->addTeam(getEmployees());}
inline void AppManager::changeTeams() {teams->changeTeam(getEmployees());}
inline void AppManager::removeTeams() {teams->removeTeam();}
inline void AppManager::displayTeams() {teams->display();}

#endif /* APPMANAGER_H_ */
