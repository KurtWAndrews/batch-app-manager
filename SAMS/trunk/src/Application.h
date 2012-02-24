/**
 * @file Application.h
 * @brief Application declaration
 * @author Kurt Andrews & Brian Royer
 */
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Team;

// using class declarations here to avoid recursive includes caused by the 
// bi-directional relationship between Application and Project
class Project;
class ProjectList; // ProjectList.h includes Project.h

class Application {
public:
	/**
	 * The Application constructor
	 * @param _appId - new application id
	 * @param _desc - description of the new application
	 */
	Application(const std::string& _appId = "",
			 const std::string& _desc = "",
			 Team* _team = NULL);
	
	/**
	 * Application destructor
	 */
	virtual ~Application();
	
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
	 * Set the application pointer for each program to NULL before clearing the projects vector
	 */
	void clearAllProjects();
	
	/**
	 * Display the application
	 */
	void display() const;
	
	/**
	 * @return the applications id
	 */
	std::string getAppId() const;

	/**
	 * @return the application description
	 */
	std::string getDesc() const;
	
	/**
	 * Populate the application's attributes
	 */
	void populate();
	
	/**
	 * Remove projects from the team
	 */
	void removeProject();
	
	/**
	 * Remove project from the application
	 * Called from project's destructor
	 */
	void removeDeletedProject(Project* project);
	
	/**
	 * Update the application id with the specified value
	 * @param _appId - the new application id
	 */
	void setAppId(const std::string& _appId);
	
	/**
	 * Update the application description with the specified value
	 * @param -_desc - the new application description
	 */
	void setDesc(const std::string& _desc);

	/**
 * Inline set method for team id the application belongs to
 */
	void setTeam(Team* _team);

	/**
 * Inline get method for team id the application belongs to
 */
	Team* getTeam() const;
	
	/**
	 * Start up method to call all necessary methods to load application data
	 */
	void startup(std::ifstream& inFile, ProjectList* projects);
	
	/**
	 * Shut down method to call all necessary methods to persist application data 
	 */
	void shutdown(std::ofstream& outFile);
		
private:
	std::string appId;
	std::string desc;
	Team* team;
	std::vector <Project*> supportingProjects;
	
	/**
	 * Display Non member attributes
	 */
	void _display() const;  
};

inline std::string Application::getAppId() const {return appId;}
inline void Application::setAppId(const std::string& _appId) {appId = _appId;}
inline std::string Application::getDesc() const {return desc;}
inline void Application::setDesc(const std::string& _desc) {desc = _desc;}
inline void Application::setTeam(Team* _team) {team = _team;}
inline Team* Application::getTeam() const {return team;}

#endif /* APPLICATION_H_ */
