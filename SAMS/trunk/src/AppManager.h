/**
 * @file AppManager.h
 * @brief AppManager declaration
 * @author Kurt Andrews & Brian Royer
 */

#ifndef APPMANAGER_H_
#define APPMANAGER_H_

#include <iostream>
#include <fstream>
#include <string>

#include "EmployeeList.h"
#include "TeamList.h"
#include "ProgramList.h"

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
	
	/**
	 * @return the system program list
	 */
	ProgramList* getPrograms() const;
	
	// modifier methods

	/**
	 * replace the employee list with the specified value
	 * @param ePtr - the pointer to the new system employee list
	 */
	void setEmployees(EmployeeList* ePtr);

	/**
	 * Update the team list pointer with the specified value
	 * @param tPtr - the pointer to the new team list
	 */
	void setTeams(TeamList* tPtr);
	
	/**
	 * Update the program list pointer with the specified value
	 * @param pPtr - the pointer to the new program list
	 */
	void setPrograms(ProgramList* pPtr);
	
	// system functions

	/**
	 * add employees to the system
	 */
	void addEmployees();

	/**
	 * manage an Employee's benefits account
	 */
	void manageEmployeeBenefits();

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
	 * display all teams in the Team list
	 */
	void displayTeams();
	
	/**
	 * add teams to the system
	 */
	void addPrograms();
	
	/**
	 * change team information
	 */
	void changePrograms();
	
	/**
	 * remove teams from the system
	 */
	void removePrograms();
	
	/**
	 * display all teams in the Team list
	 */
	void displayPrograms();
	
	/**
	 * Start up method to call all necessary methods to read in data
	 */
	void startup();
	
	/**
	 * Shut down method to call all necessary methods to persist data 
	 */
	void shutdown();
		
private:
	EmployeeList* employees;
	TeamList* teams;
	ProgramList* programs;
};

// accessor method definitions
inline EmployeeList* AppManager::getEmployees() const {return employees;}
inline TeamList* AppManager::getTeams() const {return teams;}
inline ProgramList* AppManager::getPrograms() const {return programs;}

// delligated system operations
inline void AppManager::addEmployees() {employees->addEmployee();}
inline void AppManager::manageEmployeeBenefits() {employees->manageBenefits();}
inline void AppManager::changeEmployees() {employees->changeEmployee();}
inline void AppManager::removeEmployees() {employees->removeEmployee();}
inline void AppManager::displayEmployees() {employees->display();}
inline void AppManager::addTeams() {teams->addTeam(getEmployees());}
inline void AppManager::changeTeams() {teams->changeTeam(getEmployees());}
inline void AppManager::removeTeams() {teams->removeTeam();}
inline void AppManager::displayTeams() {teams->display();}
inline void AppManager::addPrograms() {programs->addProgram();}
inline void AppManager::changePrograms() {programs->changeProgram();}
inline void AppManager::removePrograms() {programs->removeProgram();}
inline void AppManager::displayPrograms() {programs->display();}


#endif /* APPMANAGER_H_ */
