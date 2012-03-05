/**
 * @file Application.cpp
 * @brief Application Definition
 * @author Kurt Andrews & Brian Royer
 */

#include "Application.h"
#include "Team.h"

using namespace std;

Application::Application(const string& _appId,
                         const string& _desc,
                         Team* _team)
{
  setAppId(_appId);
  setDesc(_desc);
  setTeam(_team);

  clearAllProjects();
}

Application::~Application()
{
  if (team != NULL) {
    team->removeDeletedApplication(this);
  }

  clearAllProjects();
}

void Application::addProject(ProjectList* projects)
{
  system("cls");
  cout << "Adding Project" << endl;

  Project* pPtr = projects->selectProject();

  if (pPtr != NULL) {
    if (pPtr->getApplication() == NULL) {
      pPtr->setApplication((Application*) this);
      supportingProjects.push_back(pPtr);
      cout << "\n\nProject " << pPtr->getProjectId() << " added to the support list." << endl;
    } else {
      cout << "This project is already a part of the application" << endl;
    }

    cin.ignore();
  } else {
    cout << "\n\nNo projects were selected" << endl;
    cin.ignore();
  }
}

void Application::clearAttributes()
{
  setAppId("");
  setDesc("");

  clearAllProjects();
}

void Application::clearAllProjects()
{
  for (int i = 0; i < supportingProjects.size(); i++) {
    supportingProjects[i]->setApplication(NULL);
  }

  supportingProjects.clear();
}

void Application::_display() const
{
  cout << "Application ID:\t" << getAppId() << endl;
  cout << "Description:\t" << getDesc() << endl;
  cout << "Associated Team:\t" << (team == NULL ? "Not assigned to a team" : team->getTeamId() + " - " + team->getDesc()) << endl << endl;
}

void Application::display() const
{
  _display();

  cout << "*** P R O J E C T  S U P P O R T  L I S T***" << endl << endl;

  for (int i = 0; i < supportingProjects.size(); i++) {
    cout << supportingProjects[i]->getProjectId()  << " - " << supportingProjects[i]->getDesc() << endl;
  }
}

void Application::populate()
{
  string _appId;
  string _desc;

  if (getAppId() == "") {
    cout << "Enter the applicaiton id: ";
    getline(cin, _appId);

    setAppId(_appId);
  }

  cout << "Enter the application description: ";
  getline(cin, _desc);

  setDesc(_desc);
}

void Application::removeProject()
{
  if (supportingProjects.size() > 0) {
    unsigned long i = 0;

    char option = 'N';

    while (option != 'Q') {
      system("cls");
      cout << "Remove Project" << endl << endl;
      _display();
      cout << supportingProjects[i]->getProjectId() << " - " << supportingProjects[i]->getDesc() << endl << endl;
      cout << "** (F)irst * (L)ast * (P)revious * (N)ext * (R)emove * (Q)uit ** ";

      cin >> option;
      cin.ignore();

      switch (toupper(option)) {
        case 'R':
          supportingProjects.erase(supportingProjects.begin() + i); // remove the project from the application
          option = 'Q';
          break;

        case 'F':
          i = 0;
          break;

        case 'L':
          i = supportingProjects.size() - 1;
          break;

        case 'P':
          if (i == 0) {
            i = supportingProjects.size() - 1;
          } else {
            -- i;
          }

          break;

        case 'N':
          ++ i;

          if (i == supportingProjects.size()) {
            i = 0;
          }

          break;

        case 'Q':
          option = 'Q';
          break;
      }
    }
  } else {
    cout << "This application is not supporting any projects." << endl << endl;
    cin.ignore();
  }
}

void Application::removeDeletedProject(Project* program)
{
  supportingProjects.erase(std::remove(supportingProjects.begin(), supportingProjects.end(), program), supportingProjects.end());
}

void Application::startup(ifstream& inFile, ProjectList* projects)
{
  string _appId;
  getline(inFile, _appId, '|');
  setAppId(_appId);

  string _desc;
  getline(inFile, _desc);
  setDesc(_desc);

  int recs;
  string _projectId;
  Project* project = NULL;

  inFile >> recs;
  inFile.ignore();

  for (int rec = 0; rec < recs; ++rec) {
    inFile >> _projectId;
    project = projects->find(_projectId);

    if (project != NULL) {
      project->setApplication((Application*) this);
      supportingProjects.push_back(project);
    }
  }
}

void Application::shutdown(ofstream& outFile)
{
  outFile << getAppId() << '|'
          << getDesc() << endl;

  outFile << supportingProjects.size() << endl;

  for (long int rec = 0; rec < supportingProjects.size(); rec++) {
    outFile << supportingProjects[rec]->getProjectId() << endl;
  }
}