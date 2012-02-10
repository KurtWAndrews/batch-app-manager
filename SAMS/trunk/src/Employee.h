/**
 * @file Employee.h
 * @brief Employee class definition
 * @author Brian Royer & Kurt Andrews
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include <iostream>
#include <fstream>
#include <string>

class Team;

/**
 * Employee Class Definition
 */
class Employee
{
private:
	std::string employeeId;
	std::string firstName;
	std::string lastName;
	std::string prefName;
	std::string emailAddress;
	bool fullTime;
  Team* team;

public:
	Employee(const std::string& _id = "",
					 const std::string& _firstName = "",
					 const std::string& _lastName = "",
					 const std::string& _preferredName = "",
					 const std::string& _email = "",
					 const bool _fullTime = false,
           Team* _team = NULL);
	virtual ~Employee();
	void clearAttributes();
	void setEmployeeId(const std::string & _id);
	std::string getEmployeeId() const;
	void setFirstName(const std::string & _firstName);
	std::string getFirstName() const;
	void setLastName(const std::string & _lastName);
	std::string getLastName() const;
	void setPrefName(const std::string & _preferredName);
	std::string getPrefName() const;
	void setEmailAddress(const std::string & _email);
	std::string getEmailAddress() const;
	void setFullTime(const bool _isFullTime);
	bool isFullTime() const;
  Team* getTeam() const;
  void setTeam(Team* _team);
	void populate();
	virtual void display() const = 0;

  /**
   * Start up method to call all necessary methods to read in data
   */
  void startup(std::ifstream& inFile);
  
  /**
   * Shut down method to call all necessary methods to persist data and delete all 
   * variables from memory
   */
  void shutdown(std::ofstream& outFile);
};

/**
 * Overload output operation for employee object
 */
std::ostream & operator << (std::ostream& os, const Employee& emp);

/**
 * Update the employee id attribute
 * @param _id the new value of employee id
 */
inline void Employee::setEmployeeId(const std::string& _id)
{
	employeeId = _id;
}

/**
 * @return the employee id
 */
inline std::string Employee::getEmployeeId() const
{
	return employeeId;
}

/**
 * Update the employee first name
 * @param _firstName the new value of the employee's first name
 */
inline void Employee::setFirstName(const std::string& _firstName)
{
	firstName = _firstName;
}

/**
 * @return The employee's first name
 */
inline std::string Employee::getFirstName() const
{
	return firstName;
}

/**
 * Update the employee's last name
 * @param _lastName the new value of the employee's last name
 */
inline void Employee::setLastName(const std::string& _lastName)
{
	lastName = _lastName;
}

/**
 * @return the employee's last name
 */
inline std::string Employee::getLastName() const
{
	return lastName;
}

/**
 * @return the employee's preferred name
 */
inline std::string Employee::getPrefName() const
{
	return prefName;
}

/**
 * Update the employee's prefered name
 * @param _preferredName the new value for the employee's first name
 */
inline void Employee::setPrefName(const std::string& _preferredName)
{
	prefName = _preferredName;
}

/**
 * Update the employee's email address
 * @param the employee's new email address
 */
inline void Employee::setEmailAddress(const std::string& _email)
{
	emailAddress = _email;
}

/**
 * @return the employee's email address
 */
inline std::string Employee::getEmailAddress() const
{
	return emailAddress;
}

/**
 * Update the employee's full-time/part-time status
 * @param _fullTime the employee's new full/part-time status
 */
inline void Employee::setFullTime(const bool _fullTime)
{
	fullTime = _fullTime;
}

/**
 * @return True if the employee is full-time, otherwise retrun False
 */
inline bool Employee::isFullTime() const
{
	return fullTime;
}

/**
 * @return the pointer to the employee's team
 */
inline Team* Employee::getTeam() const {return team;}

/**
 * Update the pointer to the employe's team
 * @param _team the pointer to the employee's new team
 */
inline void Employee::setTeam(Team* _team) {team = _team;}

#endif