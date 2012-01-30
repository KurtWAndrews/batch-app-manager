/**
 * @file Employee.cpp
 * @brief Employee class member function definitions
 * @author Brian Royer & Kurt Andrews
 */

#include "Employee.h"
#include "Team.h"

using namespace std;

/**
 * Default Employee constructor
 */
Employee::Employee(const std::string& _id,
                   const std::string& _firstName,
                   const std::string& _lastName,
                   const std::string& _preferredName,
                   const std::string& _email,
                   const bool _isFullTime,
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
  setTeam(NULL);
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
  
  char _fullTime;

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
  cin.get(_fullTime);
  cin.ignore();

	setFirstName(firstName);
	setLastName(lastName);
	setPrefName(preferredName);
	setEmailAddress(email);
  if(tolower(_fullTime) == 'f')
  {
    setFullTime(true);
  }
  else
  {
    bool wasFullTime = isFullTime();
    setFullTime(false);
    if (getTeam() != NULL && wasFullTime) {
      if (! getTeam()->hasFullTimeMember()) {
        setFullTime(true);
        cout << "Changing this employee to part-time would violate the full-time rule for " + getTeam()->getDesc() << endl
             << "Please make sure that the team has another full time employee, or remove the team altogether," << endl
             << "before changing this employees status" << endl << endl;
        cout << "---Any character to continue";
        cin.get();
      }
    }
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
  cout << "Team Information:\t" << (team == NULL ? "Not Assigned to a team" : team->getTeamId() + " - " + team->getDesc()) << endl;
}

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

void Employee::shutdown(ofstream& outFile)
{
  outFile << getEmployeeId() << '\t'
  << getFirstName() << '\t'
  << getLastName() << '\t'
  << getPrefName() << '\t'
  << getEmailAddress() << '\t'
  << isFullTime() << endl;
}

