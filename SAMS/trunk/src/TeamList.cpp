/**
 * @file TeamList.cpp
 * @brief TeamList definition
 * @author Brian Royer & Kurt Andrews
 */

#include "TeamList.h"

using namespace std;

TeamList::TeamList() {
  teams.clear();
}

TeamList::~TeamList() {
  cout << "Executing TeamList Destructor" << endl;

  map<string, Team*>::iterator iter;

  for(iter = teams.begin(); iter != teams.end(); ++ iter) {
    delete iter->second;
  }

  teams.clear();
}

void TeamList::addTeam(EmployeeList* employees) {
  system("cls");
  cout << "Adding Team" << endl;
  
  if (employees->empty()) {
    cout << "There are no employees in the system.  Please add employees before adding a team." << endl;
    return;
  } else if (! employees->hasFullTimeEmployee()) {
    cout << "There are no full-time employees.  Please add full-time employees before adding a team." << endl;
    return;
  }
    
  Team* team = new Team;
  map<string, Team*>::const_iterator iter;

  do {
    system("cls");
    cout << "Adding Team" << endl;

    if (team->getTeamId() != "") {
      cout << "The " << team->getTeamId()
           << " is already in the Team List" << endl << endl;
      team->clearAttributes();
    }

    team->populate();
    iter = teams.find(team->getTeamId());
  } while (iter != teams.end());

  team->addMember(employees);
    
  teams.insert(pair<string, Team*>(team->getTeamId(), team));
    
  system("cls");
  cout << "Team Added" << endl;
  team->display();
}

void TeamList::changeTeam(EmployeeList* employees) {
  system("cls");
  cout << "Change Team" << endl << endl;

  if (teams.empty()) {
    cout << "There are no teams in the system." << endl;
    return;
  }

  map<string, Team*>::iterator iter = teams.begin();
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Change Team" << endl << endl;

    iter->second->display();

    cout << endl
         << endl
         << "** (F)irst * (L)ast * (P)revious * (N)ext * (C)hange * (A)dd member * (R)emove member * (Q)uit ** ";

    cin >> option;
    cin.ignore();

    switch(toupper(option)) {
      case 'A':
        iter->second->addMember(employees);
        break;
      case 'R':
        iter->second->removeMember();
        break;
      case 'C':
        system("cls");
        cout << "Change  Team" << endl << endl;

        iter->second->display();
        iter->second->populate();
        iter->second->display();
        break;
      case 'F': iter = teams.begin();
        break;
      case 'L':
        iter = teams.end();
        -- iter;
        break;
      case 'P':
        if (iter == teams.begin()) {
          iter = teams.end();
        }

        -- iter;
        break;
      case 'N':
        ++ iter;

        if (iter == teams.end()) {
          iter = teams.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

void TeamList::display() const {
  system("cls");
  cout << "Display Teams" << endl << endl;

  if (teams.empty()) {
    cout << "There are no teams in the list." << endl;
    return;
  }

  map<string, Team*>::const_iterator iter = teams.begin();
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Display Teams" << endl << endl;

    iter->second->display();

    cout << endl
         << endl
         << "** (F)irst * (L)ast * (P)revious * (N)ext * (Q)uit ** ";

    cin >> option;
    cin.ignore();

    switch(toupper(option)) {
      case 'F': iter = teams.begin();
        break;
      case 'L':
        iter = teams.end();
        -- iter;
        break;
      case 'P':
        if (iter == teams.begin()) {
          iter = teams.end();
        }

        -- iter;
        break;
      case 'N':
        ++ iter;

        if (iter == teams.end()) {
          iter = teams.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

void TeamList::removeTeam() {
  system("cls");
  cout << "Remove Team" << endl << endl;
  
  map<string, Team*>::iterator iter = teams.begin();
  string name = "";
  char option = 'N';
  
  while (option != 'Q') {
    system("cls");
    cout << "Remove Team" << endl << endl;
    if (teams.empty()) {
      cout << "There are no teams in the system." << endl;
      
      option = 'Q';
    } else {
      iter->second->display();
      name = iter->second->getTeamId();
      cout << endl
      << endl
      << "** (F)irst * (L)ast * (P)revious * (N)ext * (R)emove * (Q)uit ** ";
      
      cin >> option;
      cin.ignore();
    }
    switch(toupper(option)) {
      case 'R':
        iter->second->clearAllMembers();
        delete iter->second;
        teams.erase(name);
        iter = teams.begin();
        break;
      case 'F': iter = teams.begin();
        break;
      case 'L':
        iter = teams.end();
        -- iter;
        break;
      case 'P':
        if (iter == teams.begin()) {
          iter = teams.end();
        }
        
        -- iter;
        break;
      case 'N':
        ++ iter;
        
        if (iter == teams.end()) {
          iter = teams.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

void TeamList::startup(EmployeeList* employees)
{
  ifstream isTeams("teams.txt");
  if(isTeams)
  {
    Team* _team;
    int recs;
    
    isTeams >> recs;
    isTeams.ignore();
    
    for (int rec = 0; rec < recs; ++rec) {
      _team = new Team;
      _team->startup(isTeams, employees);
      
      teams.insert(pair<string, Team*>(_team->getTeamId(), _team));
    }
  }
  
  isTeams.close();
}

void TeamList::shutdown()
{
  ofstream osTeams("teams.txt");
  
  osTeams << teams.size() << endl;
  
  map<string, Team*>::const_iterator iter;
  for(iter = teams.begin(); iter != teams.end(); ++ iter) {
    iter->second->shutdown(osTeams);
  }
  
  osTeams.close();
}



