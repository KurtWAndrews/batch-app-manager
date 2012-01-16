/**
 * @file Employee.cpp
 * @brief Employee class member function definitions
 * @author Brian Royer
 * @author Kurt Andrews
 */

#include <iostream>
#include "Employee.h"

using namespace std;

/**
 * Default Employee constructor
 */
Employee::Employee(const string & _id,
                   const string & _firstName,
                   const string & _lastName,
                   const string & _preferredName,
                   const string & _email)
{
	setEmployeeId(_id);
	setFirstName(_firstName);
	setLastName(_lastName);
	setPrefName(_preferredName);
	setEmailAddress(_email);
}

/**
 * Employee Destructor
 */
Employee::~Employee()
{
  cout << "Executing Employee's Destructor" << endl;
}

/**
 * Retrieves employee information from user to populate an employee object
 * Returns a pointer to the new employee object
 */
void Employee::populate()
{
  string firstName,
         lastName,
         preferredName,
         id,
         email;

  if (getEmployeeId() == "") {
    cout << "What is the employee's id? ";
    getline(cin, id);

    setEmployeeId(id);
  }

	cout << "What is the employee's first name? ";
	getline(cin, firstName);
	cout << "What is the employee's last name? ";
	getline(cin, lastName);
  cout << "What is the employee's preferred name? ";
  getline(cin, preferredName);
	cout << "What is the employee's email address? ";
	getline(cin, email);

	setFirstName(firstName);
	setLastName(lastName);
	setPrefName(preferredName);
	setEmailAddress(email);
}

/**
 * Displays a Employee object
 */
void Employee::display()const
{
  cout << "Employee Id:\t" << getEmployeeId() << endl;
	cout << "Last Name:\t" << getLastName() << endl;
	cout << "First Name:\t" << getFirstName() << endl;
	cout << "Preferred Name:\t" << getPrefName() << endl;
	cout << "Email Address:\t" << getEmailAddress() << endl;
}
