/**
 * @file Team.cpp
 * @brief Team Definition
 * @author Kurt Andrews & Brian Royer
 */

#include "Team.h"
#include "EmployeeList.h"

using namespace std;

Team::Team(const string& _teamId,
           const string& _desc,
           const string& _defaultApp)
{
  setTeamId(_teamId);
  setDesc(_desc);
  setDefaultApp(_defaultApp);

  clearAllMembers();
  clearAllApplications();
}

Team::~Team()
{
  clearAllMembers();
  clearAllApplications();
}

void Team::addMember(EmployeeList* employees)
{
  bool isValidTeam = false;

  do {
    system("cls");
    cout << "Adding Member" << endl;

    Employee* ePtr = employees->selectEmployee();

    if (ePtr != NULL) {

      if (ePtr->getTeam() == NULL) {
        ePtr->setTeam((Team*) this);
        members.push_back(ePtr);
      } else {
        cout << "This employee is already on a team" << endl;
        cin.ignore();
      }
    } else {
      cout << "No employee was selected" << endl;
      cin.ignore();
    }

    isValidTeam = (members.size() > 0 && hasFullTimeMember());

    if (!isValidTeam) {
      cout << "A team must have at least one full time employee." << endl;
      cin.ignore();
    }
  } while (! isValidTeam);
}

void Team::clearAttributes()
{
  setTeamId("");
  setDesc("");
  setDefaultApp("");

  clearAllMembers();
  clearAllApplications();
}

void Team::clearAllMembers()
{
  for (int i = 0; i < members.size(); i++) {
    members[i]->setTeam(NULL);
  }

  members.clear();
}

void Team::_display() const
{
  cout << "Team ID:\t" << getTeamId() << endl;
  cout << "Description:\t" << getDesc() << endl;
  cout << "Default Application:\t" << getDefaultApp() << endl << endl;
}

void Team::display() const
{
  _display();

  cout << "*** T E A M  R O S T E R***" << endl << endl;

  for (int i = 0; i < members.size(); i++) {
    cout << members[i]->getEmployeeId() << " - " << members[i]->getLastName() << ", " << members[i]->getFirstName() << endl;
  }

  displaySupportList();
}

void Team::displaySupportList() const
{
  cout << endl << endl << "*** A P P L I C A T I O N  S U P P O R T  L I S T***" << endl << endl;

  for (int i = 0; i < supportingApplications.size(); i++) {
    cout << supportingApplications[i]->getAppId()  << " - " << supportingApplications[i]->getDesc() << endl;
  }
}

bool Team::hasFullTimeMember()
{
  bool hasFullTimeMember = false;
  int i = 0;

  while (! hasFullTimeMember && i < members.size()) {
    hasFullTimeMember = (members[i]->isFullTime());
    ++i;
  }

  return hasFullTimeMember;
}

void Team::populate()
{
  string _teamId;
  string _desc;
  string _defaultApp;

  if (getTeamId() == "") {
    cout << "Enter the team id: ";
    getline(cin, _teamId);

    setTeamId(_teamId);
  }

  cout << "Enter the team description: ";
  getline(cin, _desc);
  cout << "Enter the team default application name: ";
  getline(cin, _defaultApp);

  setDesc(_desc);
  setDefaultApp(_defaultApp);
}

void Team::removeMember()
{
  unsigned long i = 0;

  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Remove Member" << endl << endl;
    _display();
    cout << members[i]->getEmployeeId() << " - " << members[i]->getLastName()
         << "' " << members[i]->getFirstName() << endl << endl;
    cout << "** (F)irst * (L)ast * (P)revious * (N)ext * (R)emove * (Q)uit ** ";

    cin >> option;
    cin.ignore();

    switch (toupper(option)) {
      case 'R':
        if (members.size() > 1) {
          Employee* member = members[i]; // save the pointer to the employee so
          // we can use it if the employee can't
          // be removed

          members.erase(members.begin() + i); // remove the employee from the team

          if (hasFullTimeMember()) {   // team still has a full time employee...
            member->setTeam(NULL);     //   so finish the removal.
            i = 0;
          } else {                     // otherwise the team would be invalid
            // without this member so...
            members.push_back(member); //...put him pack on the team
            cout << "The team must have at least one full time employee." << endl;
            cin.ignore();
          }
        } else {
          cout << "The team must have at least one full time employee." << endl;
          cin.ignore();
        }

        option = 'Q';
        break;

      case 'F':
        i = 0;
        break;

      case 'L':
        i = members.size() - 1;
        break;

      case 'P':
        if (i == 0) {
          i = members.size() - 1;
        } else {
          -- i;
        }

        break;

      case 'N':
        ++ i;

        if (i == members.size()) {
          i = 0;
        }

        break;

      case 'Q':
        option = 'Q';
        break;
    }
  }
}

void Team::removeDeletedMember(Employee* emp)
{
  members.erase(std::remove(members.begin(), members.end(), emp), members.end());
}

void Team::addApplication(ApplicationList* applications)
{
  system("cls");
  cout << "Adding Application" << endl;

  Application* aPtr = applications->selectApplication();

  if (aPtr != NULL) {
    pushApplication(aPtr);
    cout << "\n\nApplication " << aPtr->getAppId() << " added to the support list." << endl;
    cin.ignore();
  } else {
    cout << "\n\nNo applications were selected" << endl;
    cin.ignore();
  }
}

void Team::pushApplication(Application* aPtr)
{
  supportingApplications.push_back(aPtr);
  aPtr->setTeam(this);
}

void Team::clearAllApplications()
{
  for (int i = 0; i < supportingApplications.size(); i++) {
    supportingApplications[i]->setTeam(NULL);
  }

  supportingApplications.clear();
}

void Team::removeApplication()
{
  if (supportingApplications.size() > 0) {
    unsigned long i = 0;

    char option = 'N';

    while (option != 'Q') {
      system("cls");
      cout << "Remove Application" << endl << endl;
      _display();
      cout << supportingApplications[i]->getAppId() << " - " << supportingApplications[i]->getDesc() << endl << endl;
      cout << "** (F)irst * (L)ast * (P)revious * (N)ext * (R)emove * (Q)uit ** ";

      cin >> option;
      cin.ignore();

      switch (toupper(option)) {
        case 'R':
          supportingApplications.erase(supportingApplications.begin() + i); // remove the application from the team support list
          option = 'Q';
          break;

        case 'F':
          i = 0;
          break;

        case 'L':
          i = supportingApplications.size() - 1;
          break;

        case 'P':
          if (i == 0) {
            i = supportingApplications.size() - 1;
          } else {
            -- i;
          }

          break;

        case 'N':
          ++ i;

          if (i == supportingApplications.size()) {
            i = 0;
          }

          break;

        case 'Q':
          option = 'Q';
          break;
      }
    }
  } else {
    cout << "This team is not supporting any applications." << endl << endl;
    cin.ignore();
  }
}

void Team::removeDeletedApplication(Application* app)
{
  supportingApplications.erase(std::remove(supportingApplications.begin(), supportingApplications.end(), app), supportingApplications.end());
}

void Team::startup(ifstream& inFile, EmployeeList* employees, ApplicationList* applications)
{
  string _teamId;
  getline(inFile, _teamId, '|');
  setTeamId(_teamId);

  string _desc;
  getline(inFile, _desc, '|');
  setDesc(_desc);

  string _defaultApp;
  getline(inFile, _defaultApp);
  setDefaultApp(_defaultApp);

  int recs;
  string _appId;
  Application* app = NULL;

  inFile >> recs;
  inFile.ignore();

  for (int rec = 0; rec < recs; ++rec) {
    inFile >> _appId;
    app = applications->find(_appId);

    if (app != NULL) {
      app->setTeam((Team*) this);
      supportingApplications.push_back(app);
    }
  }
}

void Team::shutdown(ofstream& outFile)
{
  outFile << getTeamId() << '|'
          << getDesc() << '|'
          << getDefaultApp() << endl;

  outFile << supportingApplications.size() << endl;

  for (long int rec = 0; rec < supportingApplications.size(); rec++) {
    outFile << supportingApplications[rec]->getAppId() << endl;
  }

  outFile << members.size() << endl;
}

std::ostream& operator << (std::ostream& os, const Team& team)
{
  team.display();
  return os;
}