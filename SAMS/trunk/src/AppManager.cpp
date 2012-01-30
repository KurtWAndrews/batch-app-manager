/**
 * @file AppManager.cpp
 * @brief AppManager definition
 */

#include "AppManager.h"

using namespace std;

/**
 * constructor for AppManager
 */
AppManager::AppManager() : employees(0),
													 programs(0)
{
	setEmployees(new EmployeeList);
	setPrograms(new ProgramList);
	startup();
}

/**
 * destructor for AppManager
 */
AppManager::~AppManager()
{
	cout << "Executing AppManager Destructor" << endl;
	shutdown();
	delete employees;
	delete programs;
}

/**
 * Start up method to call all necessary methods to read in data
 */
void AppManager::startup()
{
	employees->startup();
	programs->startup();
}

/**
 * Shut down method to call all necessary methods to persist data and delete all variables from memory
 */
void AppManager::shutdown()
{
	employees->shutdown();
	programs->shutdown();
}

void AppManager::setEmployees(EmployeeList* ePtr) {
	delete employees;
	employees = ePtr;
}

void AppManager::setPrograms(ProgramList* pPtr) {
	delete programs;
	programs = pPtr;
}