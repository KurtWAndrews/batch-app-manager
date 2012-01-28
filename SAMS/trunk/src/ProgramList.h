/**
 * @file ProgrmaList.h
 * @brief ProgramList declaration
 */

#ifndef PROGRAMLIST_H_
#define PROGRAMLIST_H_

#include "Program.h"

#include <map>
#include <string>
#include <iostream>
#include <fstream>

/**
 * @brief A collection of the employees in the system
 */
class ProgramList {
public:
	/**
	 * Default constructor for ProgramList
	 */
	ProgramList();

	/**
	 * ProgramList destructor
	 */
	virtual ~ProgramList();

	/**
	 * Start up method to call all necessary methods to read in data
	 */
	void startup();
	
	/**
	 * Shut down method to call all necessary methods to persist data and delete all variables from memory
	 */
	void shutdown();

	/**
	 * add a program to the collection
	 */
	void addProgram();

	/**
	 * change a program in the collection
	 */
	void changeProgram();

	/**
	 * remove a program from the collection
	 */
	void removeProgram();

	/**
	 * display the collection of system program
	 */
	void display() const;

private:
	std::map<std::string, Program*> programs;
};

#endif /* PROGRAMLIST_H_ */
