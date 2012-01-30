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
  void addMember(EmployeeList* employees);
  
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
  void display() const;
  
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
  void populate();
  
  /**
   * Remove employees from the team
   */
  void removeMember();
  
  /**
   * Update the team id with the specified value
   * @param _teamId - the new neam id
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
   * Start up method to call all necessary methods to load team data
   */
  void startup(std::ifstream& inFile, EmployeeList* employees);
  
  /**
   * Shut down method to call all necessary methods to persist team data 
   */
  void shutdown(std::ofstream& outFile);
    
private:
  std::string teamId;
  std::string desc;
  std::string defaultApp;
  std::vector <Employee*> members;

  
  /**
   * Display Non member attributes
   */
  void _display() const;  
};

inline std::string Team::getTeamId() const {return teamId;}
inline void Team::setTeamId(const std::string& _teamId) {teamId = _teamId;}
inline std::string Team::getDesc() const {return desc;}
inline void Team::setDesc(const std::string& _desc) {desc = _desc;}
inline std::string Team::getDefaultApp() const {return defaultApp;}
inline void Team::setDefaultApp(const std::string& _defaultApp) {defaultApp = _defaultApp;}

#endif /* TEAM_H_ */
