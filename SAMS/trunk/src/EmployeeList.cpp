/**
 * @file EmployeeList.cpp
 * @brief EmployeeList definition
 * @author Kurt Andrews & Brian Royer
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
  Employee* employee = 0;
  map<string, Employee*>::const_iterator iter;
  char _fullTime;
  
  do {
    if(employee) {
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

    cout << "Is the employee have full-time employment or part-time? (f/p): ";
    cin.get(_fullTime);
    cin.ignore();
    if(tolower(_fullTime) == 'f')
    {
      employee = new FullTime();
      FullTime* fullTime = dynamic_cast<FullTime*>(employee);
      if(fullTime)
      {
        fullTime->populate();
      }
    }
    else
    {
      employee = new PartTime();
      PartTime* partTime = dynamic_cast<PartTime*>(employee);
      if(partTime)
      {
        partTime->populate();
      }
    }

    iter = employees.find(employee->getEmployeeId());
  } while (iter != employees.end());

  system("cls");
  cout << "Adding Employee" << endl;
  employee->display();

  employees.insert(pair<string, Employee*>(employee->getEmployeeId(), employee));
}

void EmployeeList::manageBenefits()
{
  system("cls");
  map<string, Employee*>::iterator iter = employees.begin();
  FullTime* fullTime = 0;
  bool hasFullTime = false;
  cout << "Manage Benefits" << endl << endl;

  if (employees.empty()) {
    cout << "There are no employees in the system." << endl;
    return;
  }

  while(!hasFullTime && iter != employees.end())
  {
    hasFullTime = iter->second->isFullTime();
    ++iter;
  }

  if (!hasFullTime) {
    cout << "There are no full time employees in the system." << endl;
    return;
  }
  
  iter = employees.begin();
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Manage Benefits" << endl << endl;

    while(!iter->second->isFullTime())
    {
      ++iter;
    }

    fullTime = dynamic_cast<FullTime*>(iter->second);

    if(fullTime)
    {
      fullTime->display();

      cout << endl
           << endl
           << "** (F)irst * (L)ast * (P)revious * (N)ext * (D)eposit * (W)ithdraw * (Q)uit ** ";

      cin >> option;
      cin.ignore();

      switch(toupper(option)) {
        case 'D':
            fullTime->deposit();
          break;
        case 'W':
            fullTime->withdraw();
          break;
        case 'F':
          iter = employees.begin();
          while(!iter->second->isFullTime())
          {
            ++iter;
          }
          break;
        case 'L':
          iter = employees.end();
          do
          {
            --iter;
          } while(!iter->second->isFullTime());
          break;
        case 'P':
          do
          {
            if (iter == employees.begin()) {
              iter = employees.end();
            }
            -- iter;
          } while(!iter->second->isFullTime());
          break;
        case 'N':
          do
          {
            ++iter;
            if (iter == employees.end()) {
              iter = employees.begin();
            }
          } while(!iter->second->isFullTime());
          break;
        case 'Q': option = 'Q'; break;
      }
    }
    else
    {
      cout << "The employee cannot be classified as a full-time employee." << endl;
      cin.ignore();
    }
  }
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
  FullTime* fullTime = 0;
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
    
    fullTime = dynamic_cast<FullTime*>(iter->second);
    if(fullTime)
    {
      fullTime->display();
    }
    else
    {
      iter->second->display();
    }
    
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

Employee* EmployeeList::find(const std::string& _employeeId) {
  Employee* _employee = NULL;
    
  map<string, Employee*>::iterator iter;
  iter = employees.find(_employeeId);
    
  if (iter != employees.end()) {
    _employee = iter->second;
  }
    
  return(_employee);
}

bool EmployeeList::hasFullTimeEmployee() const {
  bool hasFullTimeEmployee = false;

  for(map<string, Employee*>::const_iterator iter = employees.begin(); iter != employees.end(); iter++) {
    hasFullTimeEmployee = (hasFullTimeEmployee || iter->second->isFullTime());
  }
  
  return hasFullTimeEmployee;
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

Employee* EmployeeList::selectEmployee() {
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
    
    switch(toupper(option)) {
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
      case 'Q': option = 'Q';
    }
  }
  
  return ePtr;
}

void EmployeeList::startup()
{
  ifstream isEmployees("employees.txt");
  if(isEmployees)
  {
    Employee* emp;
    int employeeRecs;
    std::string _fullTime;
    
    isEmployees >> employeeRecs;
    isEmployees.ignore();
    
    for (int rec = 0; rec < employeeRecs; ++rec) {
      getline(isEmployees, _fullTime, '|');
      if(_fullTime == "1")
      {
        emp = new FullTime;
        FullTime* fullTime = dynamic_cast<FullTime*>(emp);
        if(fullTime)
        {
          fullTime->startup(isEmployees);
        }
      }
      else
      {
        emp = new PartTime;
        PartTime* partTime = dynamic_cast<PartTime*>(emp);
        if(partTime)
        {
          partTime->startup(isEmployees);
        }
      }
      
      employees.insert(pair<string, Employee*>(emp->getEmployeeId(), emp));
    }
    
    isEmployees.close();
  }
}

void EmployeeList::shutdown()
{
  FullTime* fullTime = 0;
  PartTime* partTime = 0;

  ofstream osEmployees("employees.txt");
  
  osEmployees << employees.size() << endl;
  
  map<string, Employee*>::const_iterator iter;
  for(iter = employees.begin(); iter != employees.end(); ++ iter) {
    fullTime = dynamic_cast<FullTime*>(iter->second);
    if(fullTime)
    {
      fullTime->shutdown(osEmployees);
    }
    else
    {
      partTime = dynamic_cast<PartTime*>(iter->second);
      if(partTime)
      {
        partTime->shutdown(osEmployees);
      }
    }
  }
  
  osEmployees.close();
}