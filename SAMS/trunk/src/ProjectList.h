/**
 * @file ProjectList.h
 * @brief ProjectList declaration
 * @author Brian Royer & Kurt Andrews
 */

#ifndef PROJECTLIST_H_
#define PROJECTLIST_H_

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "Project.h"
#include "ProgramList.h"

/**
 * @brief A list of the of projects in the system
 * Manages all of the projects in the system
 */
class ProjectList {
public:
	/**
	 * default constructor for ProjectList
	 */
	ProjectList();

	/**
	 * ProjectList destructor
	 */
	virtual ~ProjectList();

	/**
	 * add a project to a collection for the projects
	 */
	void addProject(ProgramList* programs);

	/**
	 * change a project in the collection
	 */
	void changeProject(ProgramList* programs);

	/**
	 * displays the projects from the collection
	 */
	void display() const;
	
	/**
	 * remove a project from the collection
	 */
	void removeProject();

	/**
	 * Start up method to call all necessary methods to load data for projects
	 */
	void startup(ProgramList* programs);
	
	/**
	 * Shut down method to call all necessary methods to persist data and delete 
	 * all projects from memory
	 */
	void shutdown();

private:
	std::map<std::string, Project*> projects;
};

#endif /* PROJECTLIST_H_ */