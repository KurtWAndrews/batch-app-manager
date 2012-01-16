/**
 * @file main.cpp
 * @brief initialization and menu support for SAMS
 */
#include "AppManager.h"
#include "menu.h"
#include <iostream>
#include <vector>

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

int main() {
  vector<string> menus;
  menus.push_back("\n\n M A I N  M E N U\n\n");
  menus[MAIN_MENU] += "E) Manage Employees\n";
  menus[MAIN_MENU] += "\nQ) Quit\n\n";

  menus.push_back("\n\n E M P L O Y E E  M E N U\n\n");
  menus[EMPLOYEE_MENU] += "A) Add Employee\n";
  menus[EMPLOYEE_MENU] += "C) Change Employee\n";
  menus[EMPLOYEE_MENU] += "R) Remove Employee\n";
  menus[EMPLOYEE_MENU] += "D) Display Employee\n";
  menus[EMPLOYEE_MENU] += "\nQ) Quit\n\n";

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
  cout << "---Any character to continue";
  cin.get();
}

int selectMainOption(char option) {

  int menu = MAIN_MENU;

  switch (option) {
    case 'E': menu = EMPLOYEE_MENU;
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

