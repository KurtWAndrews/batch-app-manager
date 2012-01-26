/**
 * @file Employee.cpp
 * @brief Employee class member function definitions
 * @author Brian Royer
 * @author Kurt Andrews
 */

#include "Employee.h"

using namespace std;

/**
 * Default Employee constructor
 */
Employee::Employee(const std::string & _id,
                   const std::string & _firstName,
                   const std::string & _lastName,
                   const std::string & _preferredName,
                   const std::string & _email,
                   const bool _isFullTime)
{
	setEmployeeId(_id);
	setFirstName(_firstName);
	setLastName(_lastName);
	setPrefName(_preferredName);
	setEmailAddress(_email);
  setFullTime(_isFullTime);
}

/**
 * Employee Destructor
 */
Employee::~Employee()
{
  cout << "Executing Employee's Destructor" << endl;
}

/**
  * Start up method to call all necessary methods to read in data
  */
void Employee::startup(ifstream& inFile)
{
  string _id;
  getline(inFile, _id, '\t');
  setEmployeeId(_id);

  string _firstName;
  getline(inFile, _firstName, '\t');
  setFirstName(_firstName);

  string _lastName;
  getline(inFile, _lastName, '\t');
  setLastName(_lastName);

  string _prefName;
  getline(inFile, _prefName, '\t');
  setPrefName(_prefName);

  string _email;
  getline(inFile, _email, '\t');
  setEmailAddress(_email);

  string _fullTime;
  getline(inFile, _fullTime);
  if(_fullTime == "1")
  {
    setFullTime(true);
  }
  else
  {
    setFullTime(false);
  }
}
  
/**
  * Shut down method to call all necessary methods to persist data and delete all variables from memory
  */
void Employee::shutdown(ofstream& outFile)
{
  outFile << getEmployeeId() << '\t'
          << getFirstName() << '\t'
          << getLastName() << '\t'
          << getPrefName() << '\t'
          << getEmailAddress() << '\t'
          << isFullTime() << endl;
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
  std::string firstName,
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
}
