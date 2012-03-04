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
	 * Select an project from the project list
	 * @return a pointer to the selected project
	 */
	Project* selectProject();
	
	/**
	 * @return true if the project list is empty; false otherwise
	 */
	bool empty() const;
	
	/**
	 * @return the pointer to the project object that has projectId == _projectId
	 * or null if no match is found
	 */
	Project* find(const std::string& _projectId);

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

inline bool ProjectList::empty() const {return(projects.empty());}

#endif /* PROJECTLIST_H_ */