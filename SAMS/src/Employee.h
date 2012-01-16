//
//  File:         Employee.h
//
//  Author:       Brian Royer, Kurt Andrews
//
//  Description:  Employee class definition
//
//***************************************************************************
//
// Define statements
//
//***************************************************************************
#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
//***************************************************************************
//
// Include files
//
//***************************************************************************
#include <string>
#include <iostream>
#include <fstream>

//***************************************************************************
//
// Employee class definition
//
//***************************************************************************
class Employee
{
private:
  std::string employeeId;
  std::string firstName;
  std::string lastName;
  std::string prefName;
  std::string emailAddress;

public:
	Employee(const std::string & _id = "",
	         const std::string & _firstName = "",
	         const std::string & _lastName = "",
	         const std::string & _preferredName = "",
	         const std::string & _email = "");
	~Employee();
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
	void populate();
	void display() const;
};
//***************************************************************************
//
// Global function declaration to overload the << operator
//
//***************************************************************************
std::ostream & operator << (std::ostream & os, const Employee & emp);

//***************************************************************************
//
// Sets the value of Employee id
//
//***************************************************************************

inline void Employee::setEmployeeId(const std::string & _id)
{
	employeeId = _id;
}

//***************************************************************************
//
// Gets the value of Employee id
//
//***************************************************************************
inline std::string Employee::getEmployeeId()const
{
	return employeeId;
}
//***************************************************************************
//
// Sets the value of Employee first name
//
//***************************************************************************
inline void Employee::setFirstName(const std::string & _firstName)
{
	firstName = _firstName;
}
//***************************************************************************
//
// Gets the value of Employee first name
//
//***************************************************************************
inline std::string Employee::getFirstName()const
{
	return firstName;
}
//***************************************************************************
//
// Sets the value of Employee last name
//
//***************************************************************************
inline void Employee::setLastName(const std::string & _lastName)
{
	lastName = _lastName;
}
//***************************************************************************
//
// Gets the value of Employee preferred name
//
//***************************************************************************
inline std::string Employee::getPrefName()const
{
	return prefName;
}
//***************************************************************************
//
// Sets the value of Employee preferred name
//
//***************************************************************************
inline void Employee::setPrefName(const std::string & _preferredName)
{
	prefName = _preferredName;
}
//***************************************************************************
//
// Gets the value of Employee last name
//
//***************************************************************************
inline std::string Employee::getLastName()const
{
	return lastName;
}
//***************************************************************************
//
// Sets the value of Employee's email address
//
//***************************************************************************
inline void Employee::setEmailAddress(const std::string & _email)
{
	emailAddress = _email;
}
//***************************************************************************
//
// Gets the value of Employee's email address
//
//***************************************************************************
inline std::string Employee::getEmailAddress()const
{
	return emailAddress;
}
//***************************************************************************
#endif
//***************************************************************************
