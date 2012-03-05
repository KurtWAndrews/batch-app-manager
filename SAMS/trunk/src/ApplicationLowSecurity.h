/**
 * @file ApplicationLowSecurity.h
 * @brief Low Security Application declaration
 * @author Kurt Andrews & Brian Royer
 */
#ifndef APPLICATIONLOWSECURITY_H_
#define APPLICATIONLOWSECURITY_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Application.h"

class ApplicationLowSecurity : public Application
{
  public:
    /**
     * Low Security Application constructor
     * @param _appId - new application id
     * @param _desc - description of the new application
     * @param _team - pointer to associated team
     */
    ApplicationLowSecurity(const std::string& _appId = "",
                           const std::string& _desc = "", Team* _team = NULL);

    /**
     * Low Security Application destructor
     */
    virtual ~ApplicationLowSecurity();

    /**
     * Add projects to an application
     * @param projects - pointer to the project list
     */
    void addProject(ProjectList* projects);

    /**
     * Set all application attributes to empty strings, and null pointers etc
     */
    void clearAttributes();

    /**
     * Display the Low security application
     */
    void display() const;

    /**
     * Populate the Low security application's attributes
     */
    void populate();

    /**
     * Start up method to call all necessary methods to load application data
     */
    void startup(std::ifstream& inFile, ProjectList* projects);

    /**
     * Shut down method to call all necessary methods to persist application data
     */
    void shutdown(std::ofstream& outFile);

  private:
};

#endif /* APPLICATIONLOWSECURITY_H_ */
