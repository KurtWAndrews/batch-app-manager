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

      programs.insert(pair<string, Program*>(_program->getName(), _program));
    }
  }
}
  
/**
  * Shut down method to call all necessary methods to persist data and delete all variables from memory
  */
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

/**
  * add a program to the collection
  */
void ProgramList::addProgram() {
  Program* program = new Program;
  map<string, Program*>::const_iterator iter;

  do {
    system("cls");
    cout << "Adding Program" << endl;

    if (program->getName() != "") {
      cout << "The " << program->getName()
           << " is already in the Program List" << endl << endl;
      program->clearAttributes();
    }

    /*program->display();*/
    program->populate();

    iter = programs.find(program->getName());
  } while (iter != programs.end());

  system("cls");
  cout << "Added Program" << endl;
  program->display();

  programs.insert(pair<string, Program*>(program->getName(), program));
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
  string name = "";
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Remove Program" << endl << endl;
    if (programs.empty()) {
      cout << "There are no programs in the system." << endl << endl;

      option = 'Q';
    } else {
      iter->second->display();
      name = iter->second->getName();
      cout << endl
           << endl
           << "** (F)irst * (L)ast * (P)revious * (N)ext * (R)emove * (Q)uit ** ";

      cin >> option;
      cin.ignore();
    }
    switch(toupper(option)) {
      case 'R':
        delete iter->second;
        programs.erase(name);
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
