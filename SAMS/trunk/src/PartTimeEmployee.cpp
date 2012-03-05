/**
 * @file PartTimeEmployee.cpp
 * @brief Part Time Employee class member function definitions
 * @author Brian Royer & Kurt Andrews
 */

#include "PartTimeEmployee.h"
#include "Team.h"

using namespace std;

PartTimeEmployee::PartTimeEmployee() : Employee()
{
}

PartTimeEmployee::PartTimeEmployee(Employee& e) : Employee(e.getEmployeeId(),
      e.getFirstName(),
      e.getLastName(),
      e.getPrefName(),
      e.getEmailAddress(),
      e.getTeam())
{
  cout << "Executing PartTimeEmployee(const Employee& e) copy constructor" << endl;

  if (! getTeam()->isDomestic()) {
    getTeam()->removeDeletedMember(this);
    setTeam(NULL);
  }
}

PartTimeEmployee::~PartTimeEmployee()
{
  cout << "Executing Part Time Employee's Destructor" << endl;
}

void PartTimeEmployee::display() const
{
  Employee::display();
  cout << "Employee Type:\tPart-Time" << endl;
}

bool PartTimeEmployee::isFullTime() const
{
  return(false);
}

void PartTimeEmployee::startup(ifstream& inFile)
{
  string _eol;
  Employee::startup(inFile);
  getline(inFile, _eol);
}

void PartTimeEmployee::shutdown(ofstream& outFile)
{
  outFile << "P|";
  Employee::shutdown(outFile);
  outFile << endl;
}
