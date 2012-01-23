/**
 * @file Team.cpp
 * @brief Team Definition
 * @author Kurt Andrews & Brian Royer
 */
#include "Team.h"

using namespace std;

Team::Team(const string& _teamId,
           const string& _desc,
           const string& _defaultApp) {
  setTeamId(_teamId);
  setDesc(_desc);
  setDefaultApp(_defaultApp);
  
  members.clear();
}

Team::~Team() {
  members.clear();
}

void Team::clearAttributes(){
  setTeamId("");
  setDesc("");
  setDefaultApp("");
  
  members.clear();
}

void Team::_display() const {
  cout << "Team ID:\t" << getTeamId() << endl;
  cout << "Description:\t" << getDesc() << endl;
  cout << "defaultApplication:\t" << getDefaultApp() << endl << endl;
}

void Team::display() const {
  _display();
  cout << "*** T E A M  R O S T E R***" << endl << endl;
  
  for (int i = 0; i < members.size(); i++) {
    cout << members[i]->getEmployeeId() << " - " << members[i]->getLastName() ", " << members[i]->getFirstName() << endl;
  }
}

bool Team::hasFullTimeMember() {
  bool hasFullTimeMember = false;
  for (int i = 0; i < members.size(); i++) {
    hasFullTimeMember = (hasFullTimeMember || members[i]->isFullTime());
  }
  
  return hasFullTimeMember;
}

void Team::populate() {
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

void Team::addMember(EmployeeList* employees) {
  bool isValidTeam = false;
  do {
    system("cls");
    cout << "Adding Member" << endl;
      
    Employee* ePtr = employees->selectEmployee();
      
    if (ePtr != NULL) {
      ePtr->display();
      
      if (ePtr->getTeam() != NULL {
        ePtr->setTeam((Team*) this);
        members.push_back(ePtr);
      } else {
        cout << "This employee is already on a team" << endl;
      }
    } else {
      cout << "No employee was selected" << endl;
    }
    
    isValidTeam = (members.size() > 0 && hasFullTimeMember());
    if (! isValidTeam) {
      cout << "A team must have at least one full time employee." << endl;
    }
  } while (! isValidTeam);
}


void Team::removeMember() {
  int i = 0;
  bool isValidTeam = false;
  
  char option = 'N';
  while (option != 'Q') {
    system("cls");
    cout << "Remove Member" << endl << endl;
    _display();
    cout << members[i]->getEmployeeId() << " - " << members[i]->getLastName() << "' " << members[i]->getFirstname() << endl;
    cout << "** (F)irst * (L)ast * (P)revious * (N)ext * (R)emove * (Q)uit ** ";
      
    cin >> option;
    cin.ignore();
  
    switch(toupper(option)) {
      case 'R':
        if (members.size() > 1) {
          Employee* member = members[i]; // save the pointer to the employee so we can use it if the employee can't be removed
          members.erase(members.begin() + i); // remove the employee from the team
          
          if (hasFullTimeMember()) {   // team still has a full time employee...
            member->setTeam(NULL);     // ... so finish the removal
          } else {                     // ... other wise the team would be invalid so...
            members.push_back(member); // ... put him pack on the team
            cout << "The team must have at least one full time employee." << endl;
          }
        } else {
          cout << "The team must have at least one full time employee." << endl;
        }
        
        break;
      case 'F': i = 0;
        break;
      case 'L':i = members.size() - 1;
        break;
      case 'P':
        if (i == 0) {
          i = members.size() - 1;
        } ellse {
          -- i;
        }
        break;
      case 'N':
        ++ i;
        
        if (i == employees.size()) {
          i = 0;
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }

  do {
    system("cls");
    cout << "Remove Member" << endl;
    

    Employee* ePtr = employees->selectEmployee();

    if (ePtr != NULL) {
      ePtr->display();

      if (ePtr->getTeam() != NULL {
        ePtr->setTeam((Team*) this);
        members.push_back(ePtr);
      } else {
        cout << "This employee is already on a team" << endl;
      }
    } else {
      cout << "No employee was selected" << endl;
    }

    isValidTeam = (members.size() > 0 && hasFullTimeMember());
    if (! isValidTeam) {
      cout << "A team must have at least one full time employee." << endl;
    }
  } while (! isValidTeam);
}











