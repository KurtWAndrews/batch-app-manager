/**
 * @file Program.h
 * @brief Program class definition
 * @author Brian Royer
 * @author Kurt Andrews
 */

#ifndef PROGRAM_H
#define	PROGRAM_H

#include <iostream>
#include <fstream>
#include <string>

class Project;

/**
 * Program Class Definition
 */
class Program
{
private:
	std::string id;
	std::string name;
	std::string description;
	Project* project;

public:
	Program(const std::string & _id = "",
					 const std::string & _name = "",
					 const std::string & _description = "",
					 Project* _project = NULL);
	virtual ~Program();
	
	/**
	 * Start up method to call all necessary methods to read in data
	 */
	void startup(std::ifstream& inFile);
	
	/**
	 * Shut down method to call all necessary methods to persist data and delete 
	 * all variables from memory
	 */
	void shutdown(std::ofstream& outFile);

	void clearAttributes();
	void setId(const std::string & _id);
	std::string getId() const;
	void setName(const std::string & _name);
	std::string getName() const;
	void setDescription(const std::string & _description);
	std::string getDescription() const;
	void setProject(Project* _project);
	Project* getProject() const;
	void populate();
	void display() const;
};

/**
 * Overload output operation for employee object
 */
std::ostream & operator << (std::ostream & os, const Program & _program);

/**
 * Inline set method for program id
 */
inline void Program::setId(const std::string & _id)
{
	id = _id;
}

/**
 * Inline get method for program id
 */
inline std::string Program::getId() const
{
	return id;
}

/**
 * Inline set method for program name
 */
inline void Program::setName(const std::string & _name)
{
	name = _name;
}

/**
 * Inline get method for program name
 */
inline std::string Program::getName() const
{
	return name;
}

/**
 * Inline set method for program description
 */
inline void Program::setDescription(const std::string & _description)
{
	description = _description;
}

/**
 * Inline get method for program description
 */
inline std::string Program::getDescription() const
{
	return description;
}

/**
 * Inline set method for project id the program belongs to
 */
inline void Program::setProject(Project* _project)
{
	project = _project;
}

/**
 * Inline get method for project id the program belongs to
 */
inline Project* Program::getProject() const
{
	return project;
}

#endif