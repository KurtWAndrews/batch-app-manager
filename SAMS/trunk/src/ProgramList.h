/**
 * @file ProgrmaList.h
 * @brief Program List declaration
 * @author Brian Royer & Kurt Andrews
 */

#ifndef PROGRAMLIST_H_
#define PROGRAMLIST_H_

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "Program.h"

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
	 * Select an program from the program list
	 * @return a pointer to the selected program
	 */
	Program* selectProgram();

	/**
	 * display the collection of system program
	 */
	void display() const;
	
	/**
	 * @return true if the program list is empty; false otherwise
	 */
	bool empty() const;
	
	/**
	 * @return the pointer to the program object that has programId == _programId
	 * or null if no match is found
	 */
	Program* find(const std::string& _programId);

private:
	std::map<std::string, Program*> programs;
};

inline bool ProgramList::empty() const {return(programs.empty());}

#endif /* PROGRAMLIST_H_ */
