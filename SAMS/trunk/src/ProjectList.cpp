/**
 * @file ProjectList.cpp
 * @brief Project List definition
 * @author Brian Royer & Kurt Andrews
 */

#include "ProjectList.h"

using namespace std;

ProjectList::ProjectList() {
  projects.clear();
}

ProjectList::~ProjectList() {
  map<string, Project*>::iterator iter;

  for(iter = projects.begin(); iter != projects.end(); ++ iter) {
    delete iter->second;
  }

  projects.clear();
}

void ProjectList::addProject(ProgramList* programs) {
  system("cls");
  cout << "Adding Project" << endl;
    
  Project* project = new Project;
  map<string, Project*>::const_iterator iter;

  do {
    system("cls");
    cout << "Adding Project" << endl;

    if (project->getProjectId() != "") {
      cout << "The " << project->getProjectId()
           << " is already in the Project List" << endl << endl;
      project->clearAttributes();
    }

    project->populate();
    iter = projects.find(project->getProjectId());
  } while (iter != projects.end());

  project->addProgram(programs);
    
  projects.insert(pair<string, Project*>(project->getProjectId(), project));

  project->display();
}

void ProjectList::changeProject(ProgramList* programs) {
  system("cls");
  cout << "Change Project" << endl << endl;

  if (projects.empty()) {
    cout << "There are no projects in the system." << endl;
    return;
  }

  map<string, Project*>::iterator iter = projects.begin();
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Change Project" << endl << endl;

    iter->second->display();

    cout << endl
         << endl
         << "** (F)irst * (L)ast * (P)revious * (N)ext * (C)hange * (A)dd member * (R)emove member * (Q)uit ** ";

    cin >> option;
    cin.ignore();

    switch(toupper(option)) {
      case 'A':
        iter->second->addProgram(programs);
        break;
      case 'R':
        iter->second->removeProgram();
        break;
      case 'C':
        system("cls");
        cout << "Change  Project" << endl << endl;

        iter->second->display();
        iter->second->populate();
        iter->second->display();
        break;
      case 'F': iter = projects.begin();
        break;
      case 'L':
        iter = projects.end();
        -- iter;
        break;
      case 'P':
        if (iter == projects.begin()) {
          iter = projects.end();
        }

        -- iter;
        break;
      case 'N':
        ++ iter;

        if (iter == projects.end()) {
          iter = projects.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

void ProjectList::display() const {
  system("cls");
  cout << "Display Projects" << endl << endl;

  if (projects.empty()) {
    cout << "There are no projects in the list." << endl;
    return;
  }

  map<string, Project*>::const_iterator iter = projects.begin();
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Display Projects" << endl << endl;

    iter->second->display();

    cout << endl
         << endl
         << "** (F)irst * (L)ast * (P)revious * (N)ext * (Q)uit ** ";

    cin >> option;
    cin.ignore();

    switch(toupper(option)) {
      case 'F': iter = projects.begin();
        break;
      case 'L':
        iter = projects.end();
        -- iter;
        break;
      case 'P':
        if (iter == projects.begin()) {
          iter = projects.end();
        }

        -- iter;
        break;
      case 'N':
        ++ iter;

        if (iter == projects.end()) {
          iter = projects.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

void ProjectList::removeProject() {
  system("cls");
  cout << "Remove Project" << endl << endl;
  
  map<string, Project*>::iterator iter = projects.begin();
  string name = "";
  char option = 'N';
  
  while (option != 'Q') {
    system("cls");
    cout << "Remove Project" << endl << endl;
    if (projects.empty()) {
      cout << "There are no projects in the system." << endl;
      
      option = 'Q';
    } else {
      iter->second->display();
      name = iter->second->getProjectId();
      cout << endl << endl
           << "** (F)irst * (L)ast * (P)revious * (N)ext * (R)emove * (Q)uit ** ";
      
      cin >> option;
      cin.ignore();
    }
    switch(toupper(option)) {
      case 'R':
        iter->second->clearAllPrograms();
        delete iter->second;
        projects.erase(name);
        iter = projects.begin();
        break;
      case 'F': iter = projects.begin();
        break;
      case 'L':
        iter = projects.end();
        -- iter;
        break;
      case 'P':
        if (iter == projects.begin()) {
          iter = projects.end();
        }
        
        -- iter;
        break;
      case 'N':
        ++ iter;
        
        if (iter == projects.end()) {
          iter = projects.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

Project* ProjectList::selectProject() {
  system("cls");
  cout << "Select Project" << endl << endl;
  
  if (projects.empty()) {
    cout << "There are no projects in the system." << endl;
    return 0;
  }
  
  map<string, Project*>::iterator iter = projects.begin();
  char option = 'N';
  
  Project* pPtr = NULL;
  while (option != 'Q') {
    system("cls");
    cout << "Select Project" << endl << endl;
    
    iter->second->display();
    
    cout << endl
    << endl
    << "** (F)irst * (L)ast * (P)revious * (N)ext * (S)elect * (Q)uit ** ";
    
    cin >> option;
    cin.ignore();
    
    switch(toupper(option)) {
      case 'S':
        system("cls");
        cout << "Select Project\n\n"
        << "You have selected the following project from the project list:"
        << endl << endl;
        
        iter->second->display();
        
        cout << "\nIf this is correct please type (Y)es or any other key to continue."
        << endl << endl;
        
        cin >> option;
        cin.ignore();
        
        if (toupper(option) == 'Y') {
          pPtr = iter->second;
          option = 'Q';
        }
        break;
      case 'F': iter = projects.begin();
        break;
      case 'L':
        iter = projects.end();
        -- iter;
        break;
      case 'P':
        if (iter == projects.begin()) {
          iter = projects.end();
        }
        
        -- iter;
        break;
      case 'N':
        ++ iter;
        
        if (iter == projects.end()) {
          iter = projects.begin();
        }
        break;
      case 'Q': option = 'Q';
    }
  }
  
  return pPtr;
}

Project* ProjectList::find(const std::string& _projectId) {
  Project* _project = NULL;
    
  map<string, Project*>::iterator iter;
  iter = projects.find(_projectId);
    
  if (iter != projects.end()) {
    _project = iter->second;
  }
    
  return(_project);
}

void ProjectList::startup(ProgramList* programs)
{
  ifstream isProjects("projects.txt");
  if(isProjects)
  {
    Project* _project;
    int recs;
    
    isProjects >> recs;
    isProjects.ignore();
    
    for (int rec = 0; rec < recs; ++rec) {
      _project = new Project;
      _project->startup(isProjects, programs);
      
      projects.insert(pair<string, Project*>(_project->getProjectId(), _project));
    }
  }
  
  isProjects.close();
}

void ProjectList::shutdown()
{
  ofstream osProjects("projects.txt");
  
  osProjects << projects.size() << endl;
  
  map<string, Project*>::const_iterator iter;
  for(iter = projects.begin(); iter != projects.end(); ++ iter) {
    iter->second->shutdown(osProjects);
  }
  
  osProjects.close();
}