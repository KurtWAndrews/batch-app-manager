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
           const string& _defaultApp) {
  setTeamId(_teamId);
  setDesc(_desc);
  setDefaultApp(_defaultApp);
  
  clearAllMembers();
}

Team::~Team() {
  clearAllMembers();
}

void Team::addMember(EmployeeList* employees) {
  bool isValidTeam = false;
  do {
    system("cls");
    cout << "Adding Member" << endl;
    
    Employee* ePtr = employees->selectEmployee();
    
    if (ePtr != NULL) {
      ePtr->display();
      
      if (ePtr->getTeam() == NULL) {
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

void Team::clearAttributes() {
  setTeamId("");
  setDesc("");
  setDefaultApp("");
  
  clearAllMembers();
}

void Team::clearAllMembers() {
  for (int i =0; i < members.size(); i++) {
    members[i]->setTeam(NULL);
  }
  
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
    cout << members[i]->getEmployeeId() << " - " << members[i]->getLastName() << ", " << members[i]->getFirstName() << endl;
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

void Team::removeMember() {
  unsigned long i = 0;
  
  char option = 'N';
  while (option != 'Q') {
    system("cls");
    cout << "Remove Member" << endl << endl;
    _display();
    cout << members[i]->getEmployeeId() << " - " << members[i]->getLastName() 
         << "' " << members[i]->getFirstName() << endl;
    cout << "** (F)irst * (L)ast * (P)revious * (N)ext * (R)emove * (Q)uit ** ";
    
    cin >> option;
    cin.ignore();
    
    switch(toupper(option)) {
      case 'R':
        if (members.size() > 1) {
          Employee* member = members[i]; // save the pointer to the employee so 
                                         // we can use it if the employee can't 
                                         // be removed
          
          members.erase(members.begin() + i); // remove the employee from the team
          
          if (hasFullTimeMember()) {   // team still has a full time employee...
            member->setTeam(NULL);     //   so finish the removal.
          } else {                     // otherwise the team would be invalid
                                       // without this member so...
            members.push_back(member); //...put him pack on the team
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
      case 'Q': option = 'Q'; break;
    }
  }
}

void Team::startup(ifstream& inFile, EmployeeList* employees) {
	string _teamId;
	getline(inFile, _teamId, '\t');
	setTeamId(_teamId);
  
	string _desc;
	getline(inFile, _desc, '\t');
  setDesc(_desc);
  
	string _defaultApp;
	getline(inFile, _defaultApp);
	setDefaultApp(_defaultApp);
  
  int recs;
  string _employeeId;
  Employee* member = NULL;
  
  inFile >> recs;
  inFile.ignore();
  
  for (int rec = 0; rec < recs; ++rec) {
    inFile >> _employeeId;
    member = employees->find(_employeeId);
    
    if (member != NULL) {
      member->setTeam((Team*) this);
      members.push_back(member);
    }
  }
}

void Team::shutdown(ofstream& outFile)
{
	outFile << getTeamId() << '\t'
  << getDesc() << '\t'
  << getDefaultApp() << endl;
  
  outFile << members.size() << endl;
  
  for (long int rec = 0; rec < members.size(); rec--) {
    outFile << members[rec]->getEmployeeId() << endl;
  }
}

  
