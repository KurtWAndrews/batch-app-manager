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
													 applications(0),
													 projects(0),
													 programs(0) {
	setEmployees(new EmployeeList);
	setTeams(new TeamList);
	setApplications(new ApplicationList);
	setProjects(new ProjectList);
	setPrograms(new ProgramList);
														 
	startup();
}

/**
 * destructor for AppManager
 */
AppManager::~AppManager() {
	cout << "Executing AppManager Destructor" << endl;
	shutdown();
	
	delete applications;
	delete teams;
	delete employees;
	delete projects;
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

void AppManager::setApplications(ApplicationList *aPtr) {
	delete applications;
	applications = aPtr;
}

void AppManager::setProjects(ProjectList *pPtr) {
	delete projects;
	projects = pPtr;
}

void AppManager::setPrograms(ProgramList* pPtr) {
	delete programs;
	programs = pPtr;
}

void AppManager::startup() {
	employees->startup();
	programs->startup();
	projects->startup(programs);
	applications->startup(projects);
	teams->startup(employees, applications);
}

void AppManager::shutdown() {
	teams->shutdown();
	employees->shutdown();
	applications->shutdown();
	projects->shutdown();
	programs->shutdown();
}
