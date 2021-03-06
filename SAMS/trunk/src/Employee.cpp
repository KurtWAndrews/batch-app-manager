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
                   Team* _team)
{
  setEmployeeId(_id);
  setFirstName(_firstName);
  setLastName(_lastName);
  setPrefName(_preferredName);
  setEmailAddress(_email);
  setTeam(_team);
}

/**
 * Employee Destructor
 */
Employee::~Employee()
{
  if (team != NULL) {
    team->removeDeletedMember(this);
  }
}

void Employee::clearAttributes()
{
  setEmployeeId("");
  setFirstName("");
  setLastName("");
  setPrefName("");
  setEmailAddress("");
  setTeam(NULL);
}

void Employee::populate()
{
  std::string firstName,
      lastName,
      preferredName,
      id,
      email;

  if (getEmployeeId() == "") {
    cout << "What is the employee's id? ";
    getline(cin, id);
  } else {
    id = getEmployeeId();
  }

  cout << "What is the employee's first name? ";
  getline(cin, firstName);
  cout << "What is the employee's last name? ";
  getline(cin, lastName);
  cout << "What is the employee's preferred name? ";
  getline(cin, preferredName);
  cout << "What is the employee's email address? ";
  getline(cin, email);

  populate(id, firstName, lastName, preferredName, email);
}

void Employee::populate(const string& _id,
                        const string& _firstName,
                        const string& _lastName,
                        const string& _preferredName,
                        const string& _email)
{
  setEmployeeId(_id);
  setFirstName(_firstName);
  setLastName(_lastName);
  setPrefName(_preferredName);
  setEmailAddress(_email);
}

void Employee::display() const
{
  cout << "Employee Id:\t" << getEmployeeId() << endl;
  cout << "Last Name:\t" << getLastName() << endl;
  cout << "First Name:\t" << getFirstName() << endl;
  cout << "Preferred Name:\t" << getPrefName() << endl;
  cout << "Email Address:\t" << getEmailAddress() << endl;
  cout << "Team Information:\t" << (team == NULL ? "Not Assigned to a team" : team->getTeamId() + " - " + team->getDesc()) << endl;
}

void Employee::startup(ifstream& inFile)
{
  string _id;
  getline(inFile, _id, '|');
  setEmployeeId(_id);

  string _firstName;
  getline(inFile, _firstName, '|');
  setFirstName(_firstName);

  string _lastName;
  getline(inFile, _lastName, '|');
  setLastName(_lastName);

  string _prefName;
  getline(inFile, _prefName, '|');
  setPrefName(_prefName);

  string _email;
  getline(inFile, _email, '|');
  setEmailAddress(_email);
}

void Employee::shutdown(ofstream& outFile)
{
  outFile << getEmployeeId() << '|'
          << getFirstName() << '|'
          << getLastName() << '|'
          << getPrefName() << '|'
          << getEmailAddress() << '|';
}

std::ostream& operator << (std::ostream& os, const Employee& emp)
{
  emp.display();
  return os;
}