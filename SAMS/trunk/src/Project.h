/**
 * @file Project.h
 * @brief Project declaration
 * @author Kurt Andrews & Brian Royer
 */
#ifndef PROJECT_H_
#define PROJECT_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// using class declarations here to avoid recursive includes caused by the 
// bi-directional relationship between Project and Team
class Program;
class ProgramList; // ProgramList.h includes Program.h

class Project {
public:
	/**
	 * The Project constructor
	 * @param _projectId - new project id
	 * @param _desc - description of the new project
	 */
	Project(const std::string& _teamId = "",
			 const std::string& _desc = "");
	
	/**
	 * Project destructor
	 */
	virtual ~Project();
	
	/**
	 * Add programs to a team
	 * @param programs - pointer to the program list
	 */
	void addProgram(ProgramList* programs);
	
	/**
	 * Set all project attributes to empty strings, and null pointers etc
	 */
	void clearAttributes();
	
	/**
	 * Set the project pointer for each program to NULL before clearing the programs vector
	 */
	void clearAllPrograms();
	
	/**
	 * Display the project
	 */
	void display() const;
	
	/**
	 * @return the projects id
	 */
	std::string getProjectId() const;

	/**
	 * @return the project description
	 */
	std::string getDesc() const;

	/**
	 * @return if the project is supported by a pager or not
	 */
	bool isPagerSupport() const;
	
	/**
	 * Populate the project's attributes
	 */
	void populate();
	
	/**
	 * Remove programs from the team
	 */
	void removeProgram();
  
	/**
	 * Remove program from the team
   * Called from program's destructor
	 */
  void removeDeletedProgram(Program* program);
	
	/**
	 * Update the project id with the specified value
	 * @param _projectId - the new project id
	 */
	void setProjectId(const std::string& _projectId);
	
	/**
	 * Update the project description with the specified value
	 * @param -_desc - the new project description
	 */
	void setDesc(const std::string& _desc);
	
	/**
	 * Sets true or false if the project is supported by a pager
	 * @param -_supportedByPager - true or false
	 */
	void setPagerSupport(bool _supportedByPager);
	
	/**
	 * Start up method to call all necessary methods to load project data
	 */
	void startup(std::ifstream& inFile, ProgramList* programs);
	
	/**
	 * Shut down method to call all necessary methods to persist team data 
	 */
	void shutdown(std::ofstream& outFile);
		
private:
	std::string projectId;
	std::string desc;
  bool supportedByPager;
	std::vector <Program*> supportingPrograms;
	
	/**
	 * Display Non member attributes
	 */
	void _display() const;  
};

inline std::string Project::getProjectId() const {return projectId;}
inline void Project::setProjectId(const std::string& _projectId) {projectId = _projectId;}
inline std::string Project::getDesc() const {return desc;}
inline void Project::setDesc(const std::string& _desc) {desc = _desc;}
inline bool Project::isPagerSupport() const {return supportedByPager;}
inline void Project::setPagerSupport(bool _supportedByPager) {supportedByPager = _supportedByPager;}

#endif /* PROJECT_H_ */
