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
 * User entry point to the system operations related to teams
 */
int selectProgramOption(AppManager& am, char option);

int main() {
  vector<string> menus;
  menus.push_back("\n\n M A I N  M E N U\n\n");
  menus[MAIN_MENU] += "E) Manage Employees\n";
  menus[MAIN_MENU] += "T) Manage Teams\n";
  menus[MAIN_MENU] += "P) Manage Programs\n";
  menus[MAIN_MENU] += "\nQ) Quit\n\n";

  menus.push_back("\n\n E M P L O Y E E  M E N U\n\n");
  menus[EMPLOYEE_MENU] += "A) Add Employee\n";
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
    case 'E': menu = EMPLOYEE_MENU;
      break;
    case 'T': menu = TEAM_MENU;
      break;
    case 'P': menu = PROGRAM_MENU;
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

