/**
 * @file Team.h
 * @brief Team declaration
 * @author Kurt Andrews & Brian Royer
 */
#ifndef TEAM_H_
#define TEAM_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Application.h"
#include "ApplicationList.h"

// using class declarations here to avoid recursive includes caused by the 
// bi-directional relationship between Team and Employee
class Employee;
class EmployeeList; // EmployeeList.h includes Employee.h

class Team {
public:
	/**
	 * The Team constructor
	 * @param _teamId - new team id
	 * @param _desc - description of the new team
	 * @param _defaultApp - name of the teams default application
	 */
	Team(const std::string& _teamId = "",
			 const std::string& _desc = "",
			 const std::string& _defaultApp = "");
	
	/**
	 * Team destructor
	 */
	virtual ~Team();
	
	/**
	 * Add employees to a team
	 * @param employees - pointer to the employee list
	 */
	virtual void addMember(EmployeeList* employees);
	
	/**
	 * Set all team attributes to empty strings, and null pointers etc
	 */
	void clearAttributes();
	
	/**
	 * Set the team pointer for each member to NULL before clearing the members vector
	 */
	void clearAllMembers();
	
	/**
	 * Display the team
	 */
	virtual void display() const = 0;

	void displaySupportList() const;
	
	/**
	 * @return the teams team id
	 */
	std::string getTeamId() const;

	/**
	 * @return the team description
	 */
	std::string getDesc() const;
	
	/**
	 * @return the default application for the team
	 */
	std::string getDefaultApp() const;
	
	/**
	 * @return true if the team has a full time member, otherwise return false
	 */
	bool hasFullTimeMember();
	
	/**
	 * Populate the team's attributes
	 */
	virtual void populate();
	
	/**
	 * Remove employees from the team
	 */
	virtual void removeMember();

	/**
	 * Remove employee from the team
	 * Used when employee is removed from system and needs to be removed from team
	 */
	void removeEmployee(Employee* emp);
	
	/**
	 * Add applications to a team
	 * @param applications - pointer to the application list
	 */
	void addApplication(ApplicationList* applicaitons);
	
	/**
	 * Set the application pointer for each program to NULL before clearing the applications vector
	 */
	void clearAllApplications();
	
	/**
	 * Remove applications from the team
	 */
	void removeApplication();

	/**
	 * Erases the application from the team support list
	 * @param - i - the index location to remove
	 */
	void eraseApplication(int i);
	
	/**
	 * Update the team id with the specified value
	 * @param _teamId - the new team id
	 */
	void setTeamId(const std::string& _teamId);
	
	/**
	 * Update the team description with the specified value
	 * @param -_desc - the new team description
	 */
	void setDesc(const std::string& _desc);
	
	/**
	 * Update the teams default application
	 * @param - _defaultApp - the new default app for the team
	 */
	void setDefaultApp(const std::string& _defaultApp);
	
	/**
	 * @return the members vector
	 */
	std::vector<Employee*>const* getMembers() const;
	
	/**
	 * @return the members vector in order to add/delete/edit the values
	 */
	std::vector<Employee*>* getMembersToChange();

	/**
	 * Start up method to call all necessary methods to load team data
	 */
	virtual void startup(std::ifstream& inFile, EmployeeList* employees, ApplicationList* applications);
	
	/**
	 * Shut down method to call all necessary methods to persist team data 
	 */
	virtual void shutdown(std::ofstream& outFile);
		
private:
	std::string teamId;
	std::string desc;
	std::string defaultApp;
	std::vector <Employee*> members;
	std::vector <Application*> supportingApplications;
	
	/**
	 * Display Non member attributes
	 */
	void _display() const;  
};

/**
 * Overload output operation for team object
 */
std::ostream & operator << (std::ostream& os, const Team& team);

inline std::string Team::getTeamId() const {return teamId;}
inline void Team::setTeamId(const std::string& _teamId) {teamId = _teamId;}
inline std::string Team::getDesc() const {return desc;}
inline void Team::setDesc(const std::string& _desc) {desc = _desc;}
inline std::string Team::getDefaultApp() const {return defaultApp;}
inline void Team::setDefaultApp(const std::string& _defaultApp) {defaultApp = _defaultApp;}
inline std::vector<Employee*>const* Team::getMembers() const {return &members;}
inline std::vector<Employee*>* Team::getMembersToChange() {return &members;}

#endif /* TEAM_H_ */
