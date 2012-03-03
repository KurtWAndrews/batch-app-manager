/**
 * @file ApplicationHighSecurity.h
 * @brief High Security Application declaration
 * @author Kurt Andrews & Brian Royer
 */
#ifndef APPLICATIONHIGHSECURITY_H_
#define APPLICATIONHIGHSECURITY_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Application.h"
#include "ProjectList.h"

class ApplicationHighSecurity : public Application {
public:
	/**
	 * High Security Application constructor
	 * @param _appId - new application id
	 * @param _desc - description of the new application
	 * @param _team - pointer to associated team
	 */
	ApplicationHighSecurity(int riskLevel = 0, const std::string& _appId = "",
			 const std::string& _desc = "", Team* _team = NULL);
	
	/**
	 * High Security Application destructor
	 */
	~ApplicationHighSecurity();
	
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
	 * Display the high security application
	 */
	void display() const;
	
	/**
	 * Populate the high security application's attributes
	 */
	void populate();

	/**
	 * @return the risk level of the application (1 - 5)
	 */
	int getRiskLevel() const;
	
	/**
	 * Update the application's risk level with the specified value
	 * @param -_riskLevel - the new risk level (1 - 5)
	 */
	void setRiskLevel(int _riskLevel);

	
	/**
	 * Start up method to call all necessary methods to load application data
	 */
	void startup(std::ifstream& inFile, ProjectList* projects);
	
	/**
	 * Shut down method to call all necessary methods to persist application data 
	 */
	void shutdown(std::ofstream& outFile);
		
private:
	int riskLevel;
};

inline int ApplicationHighSecurity::getRiskLevel() const {return riskLevel;}
inline void ApplicationHighSecurity::setRiskLevel(int _riskLevel) {riskLevel = _riskLevel;}

#endif /* APPLICATIONHIGHSECURITY_H_ */