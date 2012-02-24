/**
 * @file main.cpp
 * @brief initialization and menu support for SAMS
 * @author Kurt Andrews & Bryan Royer
 */
#include <iostream>
#include <vector>

#include "AppManager.h"
#include "menu.h"

using namespace std;

void waitForKeyPress();

/**
 *  Display the menus and get selections from user
 */
int displayMenu(const string& options);

/**
 *  User selects one of the main menu options
 */
int selectMainOption(char option);

/**
 * User entry point to the system operations related to employees
 */
int selectEmployeeOption(AppManager& am, char option);

/**
 * User entry point to the system operations related to teams
 */
int selectTeamOption(AppManager& am, char option);

/**
 * User entry point to the system operations related to applications
 */
int selectApplicationOption(AppManager& am, char option);

/**
 * User entry point to the system operations related to projects
 */
int selectProjectOption(AppManager& am, char option);

/**
 * User entry point to the system operations related to teams
 */
int selectProgramOption(AppManager& am, char option);

int main() {
  vector<string> menus;
  menus.push_back("\n\n M A I N  M E N U\n\n");
  menus[MAIN_MENU] += "A) Manage Employees\n";
  menus[MAIN_MENU] += "B) Manage Teams\n";
  menus[MAIN_MENU] += "C) Manage Applications\n";
  menus[MAIN_MENU] += "D) Manage Projects\n";
  menus[MAIN_MENU] += "E) Manage Programs\n";
  menus[MAIN_MENU] += "\nQ) Quit\n\n";

  menus.push_back("\n\n E M P L O Y E E  M E N U\n\n");
  menus[EMPLOYEE_MENU] += "A) Add Employee\n";
  menus[EMPLOYEE_MENU] += "B) Manage Employee Benefits\n";
  menus[EMPLOYEE_MENU] += "C) Change Employee\n";
  menus[EMPLOYEE_MENU] += "R) Remove Employee\n";
  menus[EMPLOYEE_MENU] += "D) Display Employee\n";
  menus[EMPLOYEE_MENU] += "\nQ) Quit\n\n";

  menus.push_back("\n\n T E A M  M E N U\n\n");
  menus[TEAM_MENU] += "A) Add Team\n";
  menus[TEAM_MENU] += "C) Change Team\n";
  menus[TEAM_MENU] += "R) Remove Team\n";
  menus[TEAM_MENU] += "D) Display Team\n";
  menus[TEAM_MENU] += "\nQ) Quit\n\n";

  menus.push_back("\n\n A P P L I C A T I O N  M E N U\n\n");
  menus[APPLICATION_MENU] += "A) Add Application\n";
  menus[APPLICATION_MENU] += "C) Change Application\n";
  menus[APPLICATION_MENU] += "R) Remove Application\n";
  menus[APPLICATION_MENU] += "D) Display Application\n";
  menus[APPLICATION_MENU] += "\nQ) Quit\n\n";

  menus.push_back("\n\n P R O J E C T  M E N U\n\n");
  menus[PROJECT_MENU] += "A) Add Project\n";
  menus[PROJECT_MENU] += "C) Change Project\n";
  menus[PROJECT_MENU] += "R) Remove Project\n";
  menus[PROJECT_MENU] += "D) Display Project\n";
  menus[PROJECT_MENU] += "\nQ) Quit\n\n";
  
  menus.push_back("\n\n P R O G R A M  M E N U\n\n");
  menus[PROGRAM_MENU] += "A) Add Program\n";
  menus[PROGRAM_MENU] += "C) Change Program\n";
  menus[PROGRAM_MENU] += "R) Remove Program\n";
  menus[PROGRAM_MENU] += "D) Display Program\n";
  menus[PROGRAM_MENU] += "\nQ) Quit\n\n";
  
  AppManager am;
  char option = 0;

  int menu = MAIN_MENU;

  do {
    option = displayMenu(menus[menu]);

    switch(menu) {
      case MAIN_MENU:
        menu = selectMainOption(option);
        break;
      case EMPLOYEE_MENU:
        menu = selectEmployeeOption(am, option);
        break;
      case TEAM_MENU:
        menu = selectTeamOption(am, option);
        break;
      case APPLICATION_MENU:
        menu = selectApplicationOption(am, option);
        break;
      case PROJECT_MENU:
        menu = selectProjectOption(am, option);
        break;
      case PROGRAM_MENU:
        menu = selectProgramOption(am, option);
        break;
    }
  } while (menu != QUIT_MENU);

  return 0;
}

int displayMenu(const string& options)
{
  char option;

  system("cls");

  cout << options << endl;

  cout << "Enter option: ";
  cin >> option;
  cin.ignore();
  cout << "\n\n" << endl;

  return (toupper(option));
}

void waitForKeyPress() {
  cout << endl << "---Press <enter> to continue";
  cin.get();
}

int selectMainOption(char option) {

  int menu = MAIN_MENU;

  switch (option) {
    case 'A': menu = EMPLOYEE_MENU;
      break;
    case 'B': menu = TEAM_MENU;
      break;
    case 'C': menu = APPLICATION_MENU;
      break;
    case 'D': menu = PROJECT_MENU;
      break;
    case 'E': menu = PROGRAM_MENU;
      break;
    case 'Q': menu = QUIT_MENU;
      cout << "Quitting Application" << endl;
      waitForKeyPress();
      break;
    default: menu = MAIN_MENU;
      cout << "Unknown option" << endl;
      waitForKeyPress(); break;
  }
  return(menu);
}

int selectEmployeeOption(AppManager& am, char option) {
  int menu = EMPLOYEE_MENU;
  switch (option) {
    case 'A': am.addEmployees();
      break;
    case 'B': am.manageEmployeeBenefits();
      break;
    case 'C': am.changeEmployees();
      break;
    case 'R': am.removeEmployees();
      break;
    case 'D': am.displayEmployees();
      break;
    case 'Q':
      menu = MAIN_MENU;
      cout << "Quitting Employee Menu" << endl;
      break;
    default:
      cout << "Unknown option" << endl;
      break;
  }

  waitForKeyPress();

  return(menu);
}

int selectTeamOption(AppManager& am, char option) {
  int menu = TEAM_MENU;
  switch (option) {
    case 'A': am.addTeams();
      break;
    case 'C': am.changeTeams();
      break;
    case 'R': am.removeTeams();
      break;
    case 'D': am.displayTeams();
      break;
    case 'Q':
      menu = MAIN_MENU;
      cout << "Quitting Team Menu" << endl;
      break;
    default:
      cout << "Unknown option" << endl;
      break;
  }
  
  waitForKeyPress();
  
  return (menu);
}

int selectApplicationOption(AppManager& am, char option) {
  int menu = APPLICATION_MENU;
  switch (option) {
    case 'A': am.addApplications();
      break;
    case 'C': am.changeApplications();
      break;
    case 'R': am.removeApplications();
      break;
    case 'D': am.displayApplications();
      break;
    case 'Q':
      menu = MAIN_MENU;
      cout << "Quitting Applicaiton Menu" << endl;
      break;
    default:
      cout << "Unknown option" << endl;
      break;
  }
  
  waitForKeyPress();
  
  return (menu);
}

int selectProjectOption(AppManager& am, char option) {
  int menu = PROJECT_MENU;
  switch (option) {
    case 'A': am.addProjects();
      break;
    case 'C': am.changeProjects();
      break;
    case 'R': am.removeProjects();
      break;
    case 'D': am.displayProjects();
      break;
    case 'Q':
      menu = MAIN_MENU;
      cout << "Quitting Project Menu" << endl;
      break;
    default:
      cout << "Unknown option" << endl;
      break;
  }
  
  waitForKeyPress();
  
  return (menu);
}
  
int selectProgramOption(AppManager& am, char option) {
  int menu = PROGRAM_MENU;
  switch (option) {
    case 'A': am.addPrograms();
      break;
    case 'C': am.changePrograms();
      break;
    case 'R': am.removePrograms();
      break;
    case 'D': am.displayPrograms();
      break;
    case 'Q':
      menu = MAIN_MENU;
      cout << "Quitting Program Menu" << endl;
      break;
    default:
      cout << "Unknown option" << endl;
      break;
  }
    
  waitForKeyPress();
  
  return (menu);
}