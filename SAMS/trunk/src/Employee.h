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
public:
  /**
   * Default Employee constructor
   */
  Employee(const std::string& _id = "",
           const std::string& _firstName = "",
           const std::string& _lastName = "",
           const std::string& _preferredName = "",
           const std::string& _email = "",
           Team* _team = NULL);
  
  /**
   * Employee Destructor
   */
  virtual ~Employee();
  
  /**
   * Clears an employee's attributes
   */
  
  virtual void clearAttributes();
  
  /**
   * Update the employee id attribute
   * @param _id the new value of employee id
   */
  void setEmployeeId(const std::string& _id);
  
  /**
   * @return the employee id
   */
  std::string getEmployeeId() const;
  
  /**
   * Update the employee first name
   * @param _firstName the new value of the employee's first name
   */
  void setFirstName(const std::string& _firstName);
  
  /**
   * @return The employee's first name
   */
  std::string getFirstName() const;
  
  /**
   * Update the employee's last name
   * @param _lastName the new value of the employee's last name
   */
  void setLastName(const std::string& _lastName);
  
  /**
   * @return the employee's last name
   */
  std::string getLastName() const;
  
  /**
   * Update the employee's prefered name
   * @param _preferredName the new value for the employee's first name
   */
  void setPrefName(const std::string& _preferredName);
  
  /**
   * @return the employee's preferred name
   */
  std::string getPrefName() const;
  
  /**
   * Update the employee's email address
   * @param the employee's new email address
   */
  void setEmailAddress(const std::string& _email);
  
  /**
   * @return the employee's email address
   */
  std::string getEmailAddress() const;
  
  /**
   * @return True if the employee is full-time, otherwise retrun False
   */
  virtual bool isFullTime() const = 0;
  
  /**
   * @return the pointer to the employee's team
   */
  Team* getTeam() const;
  
  /**
   * Update the pointer to the employe's team
   * @param _team the pointer to the employee's new team
   */
  void setTeam(Team* _team);
  
  /**
   * Retrieves employee information from user to populate an employee object
   */
  virtual void populate();
  
  /**
   * Displays a Employee object
   */
  virtual void display() const;
  
  /**
   * Start up method to call all necessary methods to read in data
   */
  virtual void startup(std::ifstream& inFile);
  
  /**
   * Shut down method to call all necessary methods to persist data and delete all
   * variables from memory
   */
  virtual void shutdown(std::ofstream& outFile);
  
private:
  std::string employeeId;
  std::string firstName;
  std::string lastName;
  std::string prefName;
  std::string emailAddress;
  Team* team;
};

/**
 * Overload output operation for employee object
 */
std::ostream & operator << (std::ostream& os, const Employee& emp);

/**
 * Update the employee id attribute
 * @param _id the new value of employee id
 */
inline void Employee::setEmployeeId(const std::string& _id) {employeeId = _id;}

/**
 * @return the employee id
 */
inline std::string Employee::getEmployeeId() const {return employeeId;}

/**
 * Update the employee first name
 * @param _firstName the new value of the employee's first name
 */
inline void Employee::setFirstName(const std::string& _firstName) {firstName = _firstName;}

/**
 * @return The employee's first name
 */
inline std::string Employee::getFirstName() const {return firstName;}

/**
 * Update the employee's last name
 * @param _lastName the new value of the employee's last name
 */
inline void Employee::setLastName(const std::string& _lastName) {lastName = _lastName;}

/**
 * @return the employee's last name
 */
inline std::string Employee::getLastName() const {return lastName;}

/**
 * @return the employee's preferred name
 */
inline std::string Employee::getPrefName() const {return prefName;}

/**
 * Update the employee's prefered name
 * @param _preferredName the new value for the employee's first name
 */
inline void Employee::setPrefName(const std::string& _preferredName) {prefName = _preferredName;}

/**
 * Update the employee's email address
 * @param the employee's new email address
 */
inline void Employee::setEmailAddress(const std::string& _email) {emailAddress = _email;}

/**
 * @return the employee's email address
 */
inline std::string Employee::getEmailAddress() const {return emailAddress;}

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