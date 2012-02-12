/**
 * @file ProgramList.cpp
 * @brief ProgramList definition
 */

#include "ProgramList.h"

using namespace std;

ProgramList::ProgramList() {
  programs.clear();
}

ProgramList::~ProgramList() {
  cout << "Executing ProgramList Destructor" << endl;
  map<string, Program*>::iterator iter;

  for(iter = programs.begin(); iter != programs.end(); ++ iter) {
    delete iter->second;
  }

  programs.clear();
}

/**
  * Start up method to call all necessary methods to read in data
  */
void ProgramList::startup()
{
  ifstream isPrograms("programs.txt");
  if(isPrograms)
  {
    Program* _program;
    int programRecs;

    isPrograms >> programRecs;
    isPrograms.ignore();

    for (int rec = 0; rec < programRecs; ++rec) {
      _program = new Program;
     _program->startup(isPrograms);

      programs.insert(pair<string, Program*>(_program->getId(), _program));
    }
    
    isPrograms.close();
  }
}
  
void ProgramList::shutdown()
{
  ofstream osPrograms("programs.txt");

  osPrograms << programs.size() << endl;

  map<string, Program*>::const_iterator iter;
  for(iter = programs.begin(); iter != programs.end(); ++ iter) {
    iter->second->shutdown(osPrograms);
  }

  osPrograms.close();
}

void ProgramList::addProgram() {
  Program* program = new Program;
  map<string, Program*>::const_iterator iter;

  do {
    system("cls");
    cout << "Adding Program" << endl;

    if (program->getId() != "") {
      cout << "The " << program->getId()
           << " is already in the Program List" << endl << endl;
      program->clearAttributes();
    }

    /*program->display();*/
    program->populate();

    iter = programs.find(program->getId());
  } while (iter != programs.end());

  system("cls");
  cout << "Added Program" << endl;
  program->display();

  programs.insert(pair<string, Program*>(program->getId(), program));
}

void ProgramList::changeProgram() {
  system("cls");
  cout << "Change Program" << endl << endl;

  if (programs.empty()) {
    cout << "There are no programs in the system." << endl;
    return;
  }

  map<string, Program*>::iterator iter = programs.begin();
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Change Program" << endl << endl;

    iter->second->display();

    cout << endl
         << endl
         << "** (F)irst * (L)ast * (P)revious * (N)ext * (C)hange * (Q)uit ** ";

    cin >> option;
    cin.ignore();

    switch(toupper(option)) {
      case 'C':
        system("cls");
        cout << "Change  Employee" << endl << endl;

        iter->second->display();
        iter->second->populate();
        iter->second->display();
        break;
      case 'F': iter = programs.begin();
        break;
      case 'L':
        iter = programs.end();
        -- iter;
        break;
      case 'P':
        if (iter == programs.begin()) {
          iter = programs.end();
        }

        -- iter;
        break;
      case 'N':
        ++ iter;

        if (iter == programs.end()) {
          iter = programs.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

void ProgramList::removeProgram() {
  system("cls");
  cout << "Remove Employee" << endl << endl;

  map<string, Program*>::iterator iter = programs.begin();
  string id = "";
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Remove Program" << endl << endl;
    if (programs.empty()) {
      cout << "There are no programs in the system." << endl << endl;

      option = 'Q';
    } else {
      iter->second->display();
      id = iter->second->getId();
      cout << endl
           << endl
           << "** (F)irst * (L)ast * (P)revious * (N)ext * (R)emove * (Q)uit ** ";

      cin >> option;
      cin.ignore();
    }
    switch(toupper(option)) {
      case 'R':
        delete iter->second;
        programs.erase(id);
        iter = programs.begin();
        break;
      case 'F': iter = programs.begin();
        break;
      case 'L':
        iter = programs.end();
        -- iter;
        break;
      case 'P':
        if (iter == programs.begin()) {
          iter = programs.end();
        }

        -- iter;
        break;
      case 'N':
        ++ iter;

        if (iter == programs.end()) {
          iter = programs.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

Program* ProgramList::selectProgram() {
  system("cls");
  cout << "Select Program" << endl << endl;
  
  if (programs.empty()) {
    cout << "There are no programs in the system." << endl;
    return 0;
  }
  
  map<string, Program*>::iterator iter = programs.begin();
  char option = 'N';
  
  Program* pPtr = NULL;
  while (option != 'Q') {
    system("cls");
    cout << "Select Program" << endl << endl;
    
    iter->second->display();
    
    cout << endl
    << endl
    << "** (F)irst * (L)ast * (P)revious * (N)ext * (S)elect * (Q)uit ** ";
    
    cin >> option;
    cin.ignore();
    
    switch(toupper(option)) {
      case 'S':
        system("cls");
        cout << "Select Program\n\n"
        << "You have selected the following program from the program list:"
        << endl << endl;
        
        iter->second->display();
        
        cout << "If this is correct please type (Y)es or any other key to continue."
        << endl << endl;
        
        cin >> option;
        cin.ignore();
        
        if (toupper(option) == 'Y') {
          pPtr = iter->second;
          option = 'Q';
        }
        break;
      case 'F': iter = programs.begin();
        break;
      case 'L':
        iter = programs.end();
        -- iter;
        break;
      case 'P':
        if (iter == programs.begin()) {
          iter = programs.end();
        }
        
        -- iter;
        break;
      case 'N':
        ++ iter;
        
        if (iter == programs.end()) {
          iter = programs.begin();
        }
        break;
      case 'Q': option = 'Q';
    }
  }
  
  return pPtr;
}

void ProgramList::display() const {
  system("cls");
  cout << "Display Programs" << endl << endl;

  if (programs.empty()) {
    cout << "There are no programs in the list." << endl;
    return;
  }

  map<string, Program*>::const_iterator iter = programs.begin();
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Display Programs" << endl << endl;

    iter->second->display();

    cout << endl
         << endl
         << "** (F)irst * (L)ast * (P)revious * (N)ext * (Q)uit ** ";

    cin >> option;
    cin.ignore();

    switch(toupper(option)) {
      case 'F': iter = programs.begin();
        break;
      case 'L':
        iter = programs.end();
        -- iter;
        break;
      case 'P':
        if (iter == programs.begin()) {
          iter = programs.end();
        }

        -- iter;
        break;
      case 'N':
        ++ iter;

        if (iter == programs.end()) {
          iter = programs.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

Program* ProgramList::find(const std::string& _programId) {
  Program* _program = NULL;
    
  map<string, Program*>::iterator iter;
  iter = programs.find(_programId);
    
  if (iter != programs.end()) {
    _program = iter->second;
  }
    
  return(_program);
}