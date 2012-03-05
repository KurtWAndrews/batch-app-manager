/**
 * @file ApplicaitonList.h
 * @brief Application List declaration
 * @author Brian Royer & Kurt Andrews
 */

#ifndef APPLICATIONLIST_H_
#define APPLICATIONLIST_H_

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "Application.h"
#include "ProjectList.h"

/**
 * @brief A list of the of applications in the system
 * Manages all of the applications in the system
 */
class ApplicationList
{
  public:
    /**
     * default constructor for ApplicationList
     */
    ApplicationList();

    /**
     * ApplicationList destructor
     */
    virtual ~ApplicationList();

    /**
     * add an application to a collection for the applications
     */
    void addApplication(ProjectList* projects);

    /**
     * change an application in the collection
     */
    void changeApplication(ProjectList* projects);

    /**
     * displays the application from the collection
     */
    void display() const;

    /**
     * remove an application from the collection
     */
    void removeApplication();

    /**
     * Select an application from the project list
     * @return a pointer to the selected application
     */
    Application* selectApplication();

    /**
     * Select a low risk application from the project list
     * @return a pointer to the selected application
     */
    Application* selectLowSecurityApplication();

    /**
     * @return true if the projet list is empty; false otherwise
     */
    bool empty() const;

    /**
     * @return the pointer to the application object that has appId == _appId
     * or null if no match is found
     */
    Application* find(const std::string& _appId);

    /**
     * Start up method to call all necessary methods to load data for projects
     */
    void startup(ProjectList* projects);

    /**
     * Shut down method to call all necessary methods to persist data and delete
     * all applications from memory
     */
    void shutdown();

  private:
    std::map<std::string, Application*> applications;
};

inline bool ApplicationList::empty() const {return(applications.empty());}

#endif /* PROJECTLIST_H_ */