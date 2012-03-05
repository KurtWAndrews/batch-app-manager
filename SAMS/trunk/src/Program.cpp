/**
 * @file Program.cpp
 * @brief Program class member function definitions
 * @author Brian Royer
 * @author Kurt Andrews
 */

#include "Program.h"
#include "Project.h"

using namespace std;

/**
 * Default Program constructor
 */
Program::Program(const std::string& _id,
                 const std::string& _name,
                 const std::string& _description,
                 Project* _project)
{
  setId(_id);
  setName(_name);
  setDescription(_description);
  setProject(_project);
}

/**
 * Program Destructor
 */
Program::~Program()
{
  if (project != NULL) {
    project->removeDeletedProgram(this);
  }
}

/**
  * Start up method to call all necessary methods to read in data
  */
void Program::startup(ifstream& inFile)
{
  string _id;
  getline(inFile, _id, '|');
  setId(_id);

  string _name;
  getline(inFile, _name, '|');
  setName(_name);

  string _description;
  getline(inFile, _description);
  setDescription(_description);
}

/**
 * Shut down method to call all necessary methods to persist data and delete all
 * variables from memory
 */
void Program::shutdown(ofstream& outFile)
{
  outFile << getId() << '|'
          << getName() << '|'
          << getDescription() << endl;
}

/**
 * Clears all of the attributes of the program
 */
void Program::clearAttributes()
{
  setId("");
  setName("");
  setDescription("");
  setProject(NULL);
}

/**
 * Retrieves program information from user to populate an program object
 * Returns a pointer to the new program object
 */
void Program::populate()
{
  std::string _id,
      _name,
      _description,
      _projectId;

  cout << "What is the program's id? ";
  getline(cin, _id);
  cout << "What is the program's name? ";
  getline(cin, _name);
  cout << "Write a very brief description of the program: ";
  getline(cin, _description);

  setId(_id);
  setName(_name);
  setDescription(_description);
}

/**
 * Displays a Program object
 */
void Program::display() const
{
  cout << "Program ID:\t" << getId() << endl;
  cout << "Program Name:\t" << getName() << endl;
  cout << "Program Description:\t" << getDescription() << endl;
  cout << "Associated Project:\t" << (project == NULL ? "Not assigned to a project" : project->getProjectId() + " - " + project->getDesc()) << endl;
}