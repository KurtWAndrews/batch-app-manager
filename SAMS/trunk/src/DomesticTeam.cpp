/**
 * @file Domestic Team.cpp
 * @brief DOmestic Team Definition
 * @author Kurt Andrews & Brian Royer
 */

#include "DomesticTeam.h"

using namespace std;

DomesticTeam::DomesticTeam() : Team()
{
}

DomesticTeam::~DomesticTeam()
{
}

void DomesticTeam::display() const
{
  Team::display();
}

void DomesticTeam::populate()
{
  Team::populate();
}

void DomesticTeam::addMember(EmployeeList* employees)
{
  Team::addMember(employees);
}

void DomesticTeam::removeMember()
{
  Team::removeMember();
}

void DomesticTeam::addApplication(ApplicationList* applications)
{
  Team::addApplication(applications);
}

void DomesticTeam::startup(ifstream& inFile, EmployeeList* employees, ApplicationList* applications)
{
  Team::startup(inFile, employees, applications);

  std::vector<Employee*>* members = getMembersToChange();
  int recs;
  string _employeeId;
  Employee* member = NULL;
  inFile >> recs;
  inFile.ignore();

  for (int rec = 0; rec < recs; ++rec) {
    getline(inFile, _employeeId);
    member = employees->find(_employeeId);

    if (member != NULL) {
      member->setTeam((Team*) this);
      members->push_back(member);
    }
  }
}

void DomesticTeam::shutdown(ofstream& outFile)
{
  outFile << "0|";

  Team::shutdown(outFile);

  std::vector<Employee*> const* members = getMembers();
  std::string empId;

  for (long int rec = 0; rec < members->size(); rec++) {
    empId = members->at(rec)->getEmployeeId();
    outFile << empId << endl;
  }
}