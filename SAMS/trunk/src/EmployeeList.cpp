/**
 * @file EmployeeList.cpp
 * @brief EmployeeList definition
 * @author Kurt Andrews & Brian Royer
 */

#include "EmployeeList.h"

using namespace std;

EmployeeList::EmployeeList()
{
  employees.clear();
}

EmployeeList::~EmployeeList()
{
  map<string, Employee*>::iterator iter;

  for (iter = employees.begin(); iter != employees.end(); ++ iter) {
    delete iter->second;
  }

  employees.clear();
}

void EmployeeList::addEmployee()
{
  Employee* employee = NULL;
  map<string, Employee*>::const_iterator iter;
  char _fullTime;

  do {
    if (employee) {
      if (employee->getEmployeeId() != "") {
        cout << "\nThe " << employee->getEmployeeId()
             << " is already in the Employee List" << endl << endl;
        cout << "---Press <enter> to continue and choose a different id";
        cin.ignore();
        employee->clearAttributes();
      }
    }

    system("cls");
    cout << "Adding Employee" << endl;

    cout << "Employee Status (F)ull time or (P)art time: ";
    cin.get(_fullTime);
    cin.ignore();

    if (tolower(_fullTime) == 'f') {
      employee = new FullTimeEmployee();
    } else {
      employee = new PartTimeEmployee();
    }

    employee->populate();

    iter = employees.find(employee->getEmployeeId());
  } while (iter != employees.end());

  system("cls");
  cout << "Adding Employee" << endl;

  employee->display();

  employees.insert(pair<string, Employee*>(employee->getEmployeeId(), employee));
}

void EmployeeList::addEmployee(Employee* employee)
{
  map<string, Employee*>::const_iterator iter;

  if (employee != NULL) {
    if (employee->getEmployeeId() != "") {
      iter = employees.find(employee->getEmployeeId());

      if (iter == employees.end()) {
        employees.insert(pair<string, Employee*>(employee->getEmployeeId(), employee));
      }
    }
  }
}

void EmployeeList::manageBenefits()
{
  system("cls");
  map<string, FullTimeEmployee*> ftes = filterFullTimeEmployees();
  map<string, FullTimeEmployee*>::iterator iter = ftes.begin();
  cout << "Manage Benefits" << endl << endl;

  if (ftes.empty()) {
    cout << "There are no full-time employees in the system." << endl;
    return;
  }

  iter = ftes.begin();
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Manage Benefits" << endl << endl;

    iter->second->display();

    cout << endl
         << endl
         << "** (F)irst * (L)ast * (P)revious * (N)ext * (D)eposit * (W)ithdraw * (Q)uit ** ";

    cin >> option;
    cin.ignore();

    switch (toupper(option)) {
      case 'D':
        iter->second->makeDeposit();
        break;

      case 'W':
        iter->second->makeWithdrawal();
        break;

      case 'F':
        iter = ftes.begin();

        break;

      case 'L':
        iter = ftes.end();
        --iter;
        break;

      case 'P':
        if (iter == ftes.begin()) {
          iter = ftes.end();
        }

        -- iter;
        break;

      case 'N':
        ++iter;

        if (iter == ftes.end()) {
          iter = ftes.begin();
        }

        break;

      case 'Q':
        option = 'Q';
        break;
    }
  }
}

void EmployeeList::changeEmployee()
{

  system("cls");
  cout << "Change Employee" << endl << endl;

  if (employees.empty()) {
    cout << "There are no employees in the system." << endl;
    return;
  }

  Employee* tmp = NULL;
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

    switch (toupper(option)) {
      case 'C':
        system("cls");
        cout << "Change  Employee" << endl << endl;
        cout << "Employee Status (f)ull or (p)art time: ";
        char _fullTime;
        cin.get(_fullTime);
        cin.ignore();

        tmp = iter->second;

        if ((tolower(_fullTime) == 'f')  && (! iter->second->isFullTime())) {
          iter->second = new FullTimeEmployee(*tmp);
          delete tmp;
        } else if ((tolower(_fullTime) == 'p') && (iter->second->isFullTime())) {
          iter->second = new PartTimeEmployee(*tmp);
          delete tmp;
        }

        iter->second->display();
        iter->second->populate();
        break;

      case 'F':
        iter = employees.begin();
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

      case 'Q':
        option = 'Q';
        break;
    }
  }
}

void EmployeeList::display() const
{
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

    switch (toupper(option)) {
      case 'F':
        iter = employees.begin();
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

      case 'Q':
        option = 'Q';
        break;
    }
  }
}

map<string, FullTimeEmployee*> EmployeeList::filterFullTimeEmployees() const
{
  map<string, FullTimeEmployee*> ftes;

  map<string, Employee*>::const_iterator iter = employees.begin();

  while (iter != employees.end()) {
    if (iter->second->isFullTime()) {
      FullTimeEmployee* fte = dynamic_cast<FullTimeEmployee*>(iter->second);

      if (fte) {
        ftes.insert(pair<string, FullTimeEmployee*>(iter->second->getEmployeeId(), fte));
      }
    }

    iter++;
  }

  return ftes;
}

Employee* EmployeeList::find(const std::string& _employeeId)
{
  Employee* _employee = NULL;

  map<string, Employee*>::iterator iter;
  iter = employees.find(_employeeId);

  if (iter != employees.end()) {
    _employee = iter->second;
  }

  return(_employee);
}

bool EmployeeList::hasFullTimeEmployee() const
{
  bool hasFullTimeEmployee = false;

  map<string, Employee*>::const_iterator iter = employees.begin();

  while (! hasFullTimeEmployee && iter != employees.end()) {
    hasFullTimeEmployee = (iter->second->isFullTime());
    iter++;
  }

  return hasFullTimeEmployee;
}

void EmployeeList::removeEmployee()
{
  system("cls");
  cout << "Remove Employee" << endl << endl;

  map<string, Employee*>::iterator iter = employees.begin();
  string id = "";
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Remove Employee" << endl << endl;

    if (employees.empty()) {
      cout << "There are no employees in the system." << endl << endl;

      option = 'Q';
    } else {
      iter->second->display();
      id = iter->second->getEmployeeId();
      cout << endl
           << endl
           << "** (F)irst * (L)ast * (P)revious * (N)ext * (R)emove * (Q)uit ** ";

      cin >> option;
      cin.ignore();
    }

    switch (toupper(option)) {
      case 'R':
        delete iter->second;
        employees.erase(id);
        iter = employees.begin();
        break;

      case 'F':
        iter = employees.begin();
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

      case 'Q':
        option = 'Q';
        break;
    }
  }
}

Employee* EmployeeList::selectEmployee()
{
  system("cls");
  cout << "Select Employee" << endl << endl;

  if (employees.empty()) {
    cout << "There are no employees in the system." << endl;
    return 0;
  }

  map<string, Employee*>::iterator iter = employees.begin();
  char option = 'N';

  Employee* ePtr = NULL;

  while (option != 'Q') {
    system("cls");
    cout << "Select Employee" << endl << endl;

    iter->second->display();

    cout << endl
         << endl
         << "** (F)irst * (L)ast * (P)revious * (N)ext * (S)elect * (Q)uit ** ";

    cin >> option;
    cin.ignore();

    switch (toupper(option)) {
      case 'S':
        system("cls");
        cout << "Select Employee\n\n"
             << "You have selected the following employee from the employee list:"
             << endl << endl;

        iter->second->display();

        cout << "If this is correct please type (Y)es or any other key to continue."
             << endl << endl;

        cin >> option;
        cin.ignore();

        if (toupper(option) == 'Y') {
          ePtr = iter->second;
          option = 'Q';
        }

        break;

      case 'F':
        iter = employees.begin();
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

      case 'Q':
        option = 'Q';
    }
  }

  return ePtr;
}

void EmployeeList::startup()
{
  ifstream isEmployees("employees.txt");

  if (isEmployees) {
    Employee* emp;
    int employeeRecs;
    std::string _fullTime;

    isEmployees >> employeeRecs;
    isEmployees.ignore();

    for (int rec = 0; rec < employeeRecs; ++rec) {
      getline(isEmployees, _fullTime, '|');

      if (_fullTime == "F") {
        emp = new FullTimeEmployee();
      } else {
        emp = new PartTimeEmployee;
      }

      emp->startup(isEmployees);
      employees.insert(pair<string, Employee*>(emp->getEmployeeId(), emp));
    }

    isEmployees.close();
  }
}

void EmployeeList::shutdown()
{
  ofstream osEmployees("employees.txt");

  osEmployees << employees.size() << endl;

  map<string, Employee*>::const_iterator iter;

  for (iter = employees.begin(); iter != employees.end(); ++ iter) {
    iter->second->shutdown(osEmployees);
  }

  osEmployees.close();
}