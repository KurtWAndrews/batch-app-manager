/**
 * @file ApplicationList.cpp
 * @brief Application List definition
 * @author Brian Royer & Kurt Andrews
 */

#include "ApplicationList.h"
#include "ApplicationHighSecurity.h"
#include "ApplicationLowSecurity.h"

using namespace std;

ApplicationList::ApplicationList() {
  applications.clear();
}

ApplicationList::~ApplicationList() {
  map<string, Application*>::iterator iter;

  for(iter = applications.begin(); iter != applications.end(); ++ iter) {
    delete iter->second;
  }

  applications.clear();
}

void ApplicationList::addApplication(ProjectList* projects) {
  system("cls");
  cout << "Adding Application" << endl;
    
  Application* app;
  char _type;
  cout << "Is this a high or low security risk applicaton? (h/l): ";
  cin >> _type;
  cin.ignore();
  
  if(toupper(_type) == 'H')
  {
    app = new ApplicationHighSecurity;
  }
  else
  {
    app = new ApplicationLowSecurity;
  }
  
  map<string, Application*>::const_iterator iter;

  do {
    system("cls");
    cout << "Adding Application" << endl;

    if (app->getAppId() != "") {
      cout << "The " << app->getAppId()
           << " is already in the Applicaiton List" << endl << endl;
      app->clearAttributes();
    }

    app->populate();
    iter = applications.find(app->getAppId());
  } while (iter != applications.end());

  app->addProject(projects);
    
  applications.insert(pair<string, Application*>(app->getAppId(), app));

  system("cls");
  app->display();
}

void ApplicationList::changeApplication(ProjectList* projects) {
  system("cls");
  cout << "Change Application" << endl << endl;

  if (applications.empty()) {
    cout << "There are no applications in the system." << endl;
    return;
  }

  map<string, Application*>::iterator iter = applications.begin();
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Change Application" << endl << endl;

    iter->second->display();

    cout << endl
         << endl
         << "** (F)irst * (L)ast * (P)revious * (N)ext * (C)hange * (A)dd project * (R)emove project * (Q)uit ** ";

    cin >> option;
    cin.ignore();

    switch(toupper(option)) {
      case 'A':
        iter->second->addProject(projects);
        break;
      case 'R':
        iter->second->removeProject();
        break;
      case 'C':
        system("cls");
        cout << "Change  Application" << endl << endl;

        iter->second->display();
        iter->second->populate();
        iter->second->display();
        break;
      case 'F': iter = applications.begin();
        break;
      case 'L':
        iter = applications.end();
        -- iter;
        break;
      case 'P':
        if (iter == applications.begin()) {
          iter = applications.end();
        }

        -- iter;
        break;
      case 'N':
        ++ iter;

        if (iter == applications.end()) {
          iter = applications.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

void ApplicationList::display() const {
  system("cls");
  cout << "Display Applications" << endl << endl;

  if (applications.empty()) {
    cout << "There are no applications in the list." << endl;
    return;
  }

  map<string, Application*>::const_iterator iter = applications.begin();
  char option = 'N';

  while (option != 'Q') {
    system("cls");
    cout << "Display Applications" << endl << endl;

    iter->second->display();

    cout << endl
         << endl
         << "** (F)irst * (L)ast * (P)revious * (N)ext * (Q)uit ** ";

    cin >> option;
    cin.ignore();

    switch(toupper(option)) {
      case 'F': iter = applications.begin();
        break;
      case 'L':
        iter = applications.end();
        -- iter;
        break;
      case 'P':
        if (iter == applications.begin()) {
          iter = applications.end();
        }

        -- iter;
        break;
      case 'N':
        ++ iter;

        if (iter == applications.end()) {
          iter = applications.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

void ApplicationList::removeApplication() {
  system("cls");
  cout << "Remove Application" << endl << endl;
  
  map<string, Application*>::iterator iter = applications.begin();
  string id = "";
  char option = 'N';
  
  while (option != 'Q') {
    system("cls");
    cout << "Remove Application" << endl << endl;
    if (applications.empty()) {
      cout << "There are no applications in the system." << endl;
      
      option = 'Q';
    } else {
      iter->second->display();
      id = iter->second->getAppId();
      cout << endl << endl
           << "** (F)irst * (L)ast * (P)revious * (N)ext * (R)emove * (Q)uit ** ";
      
      cin >> option;
      cin.ignore();
    }
    switch(toupper(option)) {
      case 'R':
        iter->second->clearAllProjects();
        delete iter->second;
        applications.erase(id);
        iter = applications.begin();
        break;
      case 'F': iter = applications.begin();
        break;
      case 'L':
        iter = applications.end();
        -- iter;
        break;
      case 'P':
        if (iter == applications.begin()) {
          iter = applications.end();
        }
        
        -- iter;
        break;
      case 'N':
        ++ iter;
        
        if (iter == applications.end()) {
          iter = applications.begin();
        }
        break;
      case 'Q': option = 'Q'; break;
    }
  }
}

Application* ApplicationList::selectLowSecurityApplication() { 
  system("cls");
  cout << "Select Application" << endl << endl;
  
  if (applications.empty()) {
    cout << "There are no applications in the system." << endl;
    return 0;
  }
  
  ApplicationLowSecurity* lowRisk = 0;
  int direction = 0;
  map<string, Application*>::iterator iter = applications.begin();
  char option = 'N';
  
  Application* aPtr = NULL;
  while (option != 'Q') {
    system("cls");
    cout << "Select Application" << endl << endl;

    lowRisk = dynamic_cast<ApplicationLowSecurity*>(iter->second);

    if(lowRisk)
    {
      lowRisk->display();

      cout << endl
           << endl
           << "** (F)irst * (L)ast * (P)revious * (N)ext * (S)elect * (Q)uit ** ";

      cin >> option;
      cin.ignore();

      switch(toupper(option)) {
      case 'S':
        system("cls");
        cout << "Select Application\n\n"
        << "You have selected the following application from the application list:"
        << endl << endl;
        
        iter->second->display();
        
        cout << "\nIf this is correct please type (Y)es or any other key to continue."
        << endl << endl;
        
        cin >> option;
        cin.ignore();
        
        if (toupper(option) == 'Y') {
          aPtr = iter->second;
          option = 'Q';
        }
        break;
      case 'F':
        iter = applications.begin();
        direction = 1;
        break;
      case 'L':
        iter = applications.end();
        direction = 2;
        -- iter;
        break;
      case 'P':
        if (iter == applications.begin()) {
          iter = applications.end();
        }
        -- iter;
        direction = 2;
        break;
      case 'N':
        ++ iter;
        if (iter == applications.end()) {
          iter = applications.begin();
        }
        direction = 1;
        break;
      case 'Q': option = 'Q';
      }
    }
    else
    {
      if (direction == 1) {
        ++ iter;
        if (iter == applications.end()) {
          iter = applications.begin();
        }
      }
      else if (direction == 2) {
        if (iter == applications.begin()) {
          iter = applications.end();
        }
        -- iter;
      }
      else {
        ++ iter;
        if (iter == applications.end()) {
          cout << "There are no low security applications in the system" << endl << endl;
          cin.ignore();
          option = 'Q';
        }
      }
    }
  }

  return aPtr;
}

Application* ApplicationList::selectApplication() {
  system("cls");
  cout << "Select Application" << endl << endl;
  
  if (applications.empty()) {
    cout << "There are no applications in the system." << endl;
    return 0;
  }
  
  map<string, Application*>::iterator iter = applications.begin();
  char option = 'N';
  
  Application* aPtr = NULL;
  while (option != 'Q') {
    system("cls");
    cout << "Select Application" << endl << endl;
    
    iter->second->display();
    
    cout << endl << endl
         << "** (F)irst * (L)ast * (P)revious * (N)ext * (S)elect * (Q)uit ** ";
    
    cin >> option;
    cin.ignore();
    
    switch(toupper(option)) {
      case 'S':
        system("cls");
        cout << "Select Application\n\n"
        << "You have selected the following application from the application list:"
        << endl << endl;
        
        iter->second->display();
        
        cout << "\nIf this is correct please type (Y)es or any other key to continue."
        << endl << endl;
        
        cin >> option;
        cin.ignore();
        
        if (toupper(option) == 'Y') {
          aPtr = iter->second;
          option = 'Q';
        }
        break;
      case 'F': iter = applications.begin();
        break;
      case 'L':
        iter = applications.end();
        -- iter;
        break;
      case 'P':
        if (iter == applications.begin()) {
          iter = applications.end();
        }
        
        -- iter;
        break;
      case 'N':
        ++ iter;
        
        if (iter == applications.end()) {
          iter = applications.begin();
        }
        break;
      case 'Q': option = 'Q';
    }
  }
  
  return aPtr;
}

Application* ApplicationList::find(const std::string& _appId) {
  Application* _app = NULL;
    
  map<string, Application*>::iterator iter;
  iter = applications.find(_appId);
    
  if (iter != applications.end()) {
    _app = iter->second;
  }
    
  return(_app);
}

void ApplicationList::startup(ProjectList* projects)
{
  ifstream isApplications("applications.txt");
  if(isApplications)
  {
    Application* _app;
    int recs;
    
    isApplications >> recs;
    isApplications.ignore();
    
    for (int rec = 0; rec < recs; ++rec) {
      string _type;
      getline(isApplications, _type, '|');
      if(_type == "1")
      {
        _app = new ApplicationHighSecurity;
      }
      else
      {
        _app = new ApplicationLowSecurity;
      }

      _app->startup(isApplications, projects);
      
      applications.insert(pair<string, Application*>(_app->getAppId(), _app));
    }
  }
  
  isApplications.close();
}

void ApplicationList::shutdown()
{
  ofstream osApplications("applications.txt");
  
  osApplications << applications.size() << endl;
  
  map<string, Application*>::const_iterator iter;
  for(iter = applications.begin(); iter != applications.end(); ++ iter) {
    iter->second->shutdown(osApplications);
  }
  
  osApplications.close();
}