/**
 * @file Employee.cpp
 * @brief Employee class member function definitions
 * @author Brian Royer
 * @author Kurt Andrews
 */

#include "Program.h"

using namespace std;

/**
 * Default Program constructor
 */
Program::Program(const std::string & _name,
									 const std::string & _description,
									 const std::string & _projectId)
{
	setName(_name);
	setDescription(_description);
	setProjectId(_projectId);
}

/**
 * Program Destructor
 */
Program::~Program()
{
	cout << "Executing Program's Destructor" << endl;
}

/**
	* Start up method to call all necessary methods to read in data
	*/
void Program::startup(ifstream& inFile)
{
	string _name;
	getline(inFile, _name, '\t');
	setName(_name);

	string _description;
	getline(inFile, _description, '\t');
	setDescription(_description);

	string _projectId;
	getline(inFile, _projectId, '\t');
	setProjectId(_projectId);
}
	
/**
	* Shut down method to call all necessary methods to persist data and delete all variables from memory
	*/
void Program::shutdown(ofstream& outFile)
{
	outFile << getName() << '\t'
					<< getDescription() << '\t'
					<< getProjectId() << endl;
}

/**
 * Clears all of the attributes of the program
 */
void Program::clearAttributes()
{
	setName("");
	setDescription("");
	setProjectId("");
}

/**
 * Retrieves program information from user to populate an program object
 * Returns a pointer to the new program object
 */
void Program::populate()
{
	std::string _name,
							_description,
							_projectId;

	cout << "What is the program's name? ";
	getline(cin, _name);
	cout << "Write a very brief description of the program: ";
	getline(cin, _description);
	cout << "What is the project id that the program is associated to? ";
	getline(cin, _projectId);
	
	setName(_name);
	setDescription(_description);
	setProjectId(_projectId);
}

/**
 * Displays a Program object
 */
void Program::display() const
{
	cout << "Program Name:\t" << getName() << endl;
	cout << "Program Description:\t" << getDescription() << endl;
	cout << "Associated Project ID:\t" << getProjectId() << endl;
}
