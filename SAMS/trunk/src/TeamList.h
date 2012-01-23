/**
 * @file TeamList.h
 * @brief TeamList declaration
 * @author Brian Royer & Kurt Andrews
 */

#ifndef TEAMLIST_H_
#define TEAMLIST_H_

#include "Team.h"

#include <map>
#include <string>
#include <iostream>
#include <fstream>

/**
 * @brief A collection of the of teams in the system
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
   * remove a team from the collection
   */
  void removeTeam();

  /**
   * displays the teams from the collection
   */
  void display() const;

private:
  std::map<std::string, Team*> teams;
};

#endif /* TEAMLIST_H_ */