/**
 * @file Employee.h
 * @brief Employee class definition
 * @author Brian Royer
 * @author Kurt Andrews
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include <string>
#include <iostream>
#include <fstream>

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
  bool isFullTime;

public:
	Employee(const std::string & _id = "",
	         const std::string & _firstName = "",
	         const std::string & _lastName = "",
	         const std::string & _preferredName = "",
	         const std::string & _email = "",
           const bool & _isFullTime = false);
	~Employee();
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
  void setIsFullTime(const bool _isFullTime);
  bool getIsFullTime() const;
	void populate();
	void display() const;
};

/**
 * Overload output operation for employee object
 */
std::ostream & operator << (std::ostream & os, const Employee & emp);

/**
 * Inline set method for employee id
 */
inline void Employee::setEmployeeId(const std::string & _id)
{
	employeeId = _id;
}

/**
 * Inline get method for employee id
 */
inline std::string Employee::getEmployeeId()const
{
	return employeeId;
}

/**
 * Inline set method for employee first name
 */
inline void Employee::setFirstName(const std::string & _firstName)
{
	firstName = _firstName;
}

/**
 * Inline get method for employee first name
 */
inline std::string Employee::getFirstName()const
{
	return firstName;
}

/**
 * Inline set method for employee last name
 */
inline void Employee::setLastName(const std::string & _lastName)
{
	lastName = _lastName;
}

/**
 * Inline get method for employee last name
 */
inline std::string Employee::getLastName()const
{
	return lastName;
}

/**
 * Inline get method for employee preferred name
 */
inline std::string Employee::getPrefName()const
{
	return prefName;
}

/**
 * Inline set method for employee preferred name
 */
inline void Employee::setPrefName(const std::string & _preferredName)
{
	prefName = _preferredName;
}

/**
 * Inline set method for employee email
 */
inline void Employee::setEmailAddress(const std::string & _email)
{
	emailAddress = _email;
}

/**
 * Inline get method for employee email
 */
inline std::string Employee::getEmailAddress()const
{
	return emailAddress;
}

/**
 * Inline set method for employee employment status
 */
inline void Employee::setIsFullTime(const bool _isFullTime)
{
	isFullTime = _isFullTime;
}

/**
 * Inline get method for employee employement
 */
inline bool Employee::getIsFullTime()const
{
	return isFullTime;
}

#endif