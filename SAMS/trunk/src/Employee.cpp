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
                   const string & _email,
                   bool _isFullTime,
                  Team* _team)
{
	setEmployeeId(_id);
	setFirstName(_firstName);
	setLastName(_lastName);
	setPrefName(_preferredName);
	setEmailAddress(_email);
  setFullTime(_isFullTime);
  setTeam(_team);
}

/**
 * Employee Destructor
 */
Employee::~Employee()
{
  cout << "Executing Employee's Destructor" << endl;
}

void Employee::clearAttributes()
{
	setEmployeeId("");
	setFirstName("");
	setLastName("");
	setPrefName("");
	setEmailAddress("");
  setFullTime(false);
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
  
  char isFullTime;

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
  cout << "Is the employee have full-time employment or part-time? (f/p): ";
  cin.get(isFullTime);
  cin.ignore();

	setFirstName(firstName);
	setLastName(lastName);
	setPrefName(preferredName);
	setEmailAddress(email);
  if(tolower(isFullTime) == 'f')
  {
    setFullTime(true);
  }
  else
  {
    setFullTime(false);
  }
}

/**
 * Displays a Employee object
 */
void Employee::display() const
{
  cout << "Employee Id:\t" << getEmployeeId() << endl;
	cout << "Last Name:\t" << getLastName() << endl;
	cout << "First Name:\t" << getFirstName() << endl;
	cout << "Preferred Name:\t" << getPrefName() << endl;
	cout << "Email Address:\t" << getEmailAddress() << endl;
  cout << "Employment Status:\t" << (isFullTime() ? "Full-Time" : "Part-Time") << endl;
  
  string teamInfo = "";
  if (getTeam() == NULL) {
    teamInfo = "No team assigned";
  } else {
    teamInfo = getTeam()->getTeamId() << " - " << getTeam()->getDesc();
  }
  
  cout << "Team:\t" << teamInfo << endl;
}
