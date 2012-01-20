/**
 * @file EmployeeList.cpp
 * @brief EmployeeList definition
 */

#include "EmployeeList.h"

using namespace std;

EmployeeList::EmployeeList() {
  employees.clear();
}

EmployeeList::~EmployeeList() {
  cout << "Executing EmployeeList Destructor" << endl;

  map<string, Employee*>::iterator iter;

  for(iter = employees.begin(); iter != employees.end(); ++ iter) {
    delete iter->second;
  }

  employees.clear();
}

void EmployeeList::addEmployee() {
  Employee* employee = new Employee;
  map<string, Employee*>::const_iterator iter;

  do {
    system("cls");
    cout << "Adding Employee" << endl;

    if (employee->getEmployeeId() != "") {
      cout << "The " << employee->getEmployeeId()
           << " is already in the Employee List" << endl << endl;
      employee->clearAttributes();
    }

    /*employee->display();*/
    employee->populate();

    iter = employees.find(employee->getEmployeeId());
  } while (iter != employees.end());

  system("cls");
  cout << "Employee Added" << endl;
  employee->display();

  employees.insert(pair<string, Employee*>(employee->getEmployeeId(), employee));
}

void EmployeeList::changeEmployee() {
  system("cls");
  cout << "Change Employee" << endl << endl;

  if (employees.empty()) {
    cout << "There are no employees in the system." << endl;
    return;
  }

  map<string, Employee*>::iterator iter = employees.begin();
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Change Employee" << endl << endl;

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
      case 'F': iter = employees.begin();
        break;
      case 'L':
        iter = employees.end();
        -- iter;
        break;
      case 'P':
        if (iter == employees.begin()) {
          iter = employees.end();
        }

        -- iter;
        break;
      case 'N':
        ++ iter;

        if (iter == employees.end()) {
          iter = employees.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

void EmployeeList::removeEmployee() {
  system("cls");
  cout << "Remove Employee" << endl << endl;

  map<string, Employee*>::iterator iter = employees.begin();
  string name = "";
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Remove Employee" << endl << endl;
    if (employees.empty()) {
      cout << "There are no employees in the system." << endl << endl;

      option = 'Q';
    } else {
      iter->second->display();
      name = iter->second->getEmployeeId();
      cout << endl
           << endl
           << "** (F)irst * (L)ast * (P)revious * (N)ext * (R)emove * (Q)uit ** ";

      cin >> option;
      cin.ignore();
    }
    switch(toupper(option)) {
      case 'R':
        delete iter->second;
        employees.erase(name);
        iter = employees.begin();
        break;
      case 'F': iter = employees.begin();
        break;
      case 'L':
        iter = employees.end();
        -- iter;
        break;
      case 'P':
        if (iter == employees.begin()) {
          iter = employees.end();
        }

        -- iter;
        break;
      case 'N':
        ++ iter;

        if (iter == employees.end()) {
          iter = employees.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

void EmployeeList::display() const {
  system("cls");
  cout << "Display Employees" << endl << endl;

  if (employees.empty()) {
    cout << "There are no employees in the list." << endl;
    return;
  }

  map<string, Employee*>::const_iterator iter = employees.begin();
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Display Employees" << endl << endl;

    iter->second->display();

    cout << endl
         << endl
         << "** (F)irst * (L)ast * (P)revious * (N)ext * (Q)uit ** ";

    cin >> option;
    cin.ignore();

    switch(toupper(option)) {
      case 'F': iter = employees.begin();
        break;
      case 'L':
        iter = employees.end();
        -- iter;
        break;
      case 'P':
        if (iter == employees.begin()) {
          iter = employees.end();
        }

        -- iter;
        break;
      case 'N':
        ++ iter;

        if (iter == employees.end()) {
          iter = employees.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}
