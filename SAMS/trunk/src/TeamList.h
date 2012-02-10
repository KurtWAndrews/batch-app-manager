/**
 * @file TeamList.h
 * @brief TeamList declaration
 * @author Brian Royer & Kurt Andrews
 */

#ifndef TEAMLIST_H_
#define TEAMLIST_H_

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "Team.h"
#include "EmployeeList.h"

/**
 * @brief A list of the of teams in the system
 * Manages all of the teams in the system
 */
class TeamList {
public:
	/**
	 * default constructor for TeamList
	 */
	TeamList();

	/**
	 * TeamList destructor
	 */
	virtual ~TeamList();

	/**
	 * add a team to a collection for the team
	 */
	void addTeam(EmployeeList* employees);

	/**
	 * change a team in the collection
	 */
	void changeTeam(EmployeeList* employees);

	/**
	 * displays the teams from the collection
	 */
	void display() const;
	
	/**
	 * remove a team from the collection
	 */
	void removeTeam();

	/**
	 * Start up method to call all necessary methods to load data for teams
	 */
	void startup(EmployeeList* employees);
	
	/**
	 * Shut down method to call all necessary methods to persist data and delete 
	 * all teams from memory
	 */
	void shutdown();

private:
	std::map<std::string, Team*> teams;
};

#endif /* TEAMLIST_H_ */