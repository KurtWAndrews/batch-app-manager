/**
 * @file ApplicationLowSecurity.cpp
 * @brief Low Security Application Definition
 * @author Kurt Andrews & Brian Royer
 */

#include "ApplicationLowSecurity.h"
#include "Team.h"

using namespace std;

/**
	 * Low Security Application constructor
	 * @param _appId - new application id
	 * @param _desc - description of the new application
	 */
	ApplicationLowSecurity::ApplicationLowSecurity(const std::string& _appId,
			 const std::string& _desc, Team* _team)
			 : Application(_appId, _desc, _team)
	{
	}
	
	/**
	 * Low Security Application destructor
	 */
	ApplicationLowSecurity::~ApplicationLowSecurity()
	{
	}

	
	/**
	 * Add projects to an application
	 * @param projects - pointer to the project list
	 */
	void ApplicationLowSecurity::addProject(ProjectList* projects)
	{
		Application::addProject(projects);
	}
	
	/**
	 * Set all application attributes to empty strings, and null pointers etc
	 */
	void ApplicationLowSecurity::clearAttributes()
	{
		Application::clearAttributes();
	}
	
	/**
	 * Display the Low security application
	 */
	void ApplicationLowSecurity::display() const
	{
		cout << "LOW SECURITY APPLICATION" << endl << endl;
		Application::display();
	}
	
	/**
	 * Populate the Low security application's attributes
	 */
	void ApplicationLowSecurity::populate()
	{
		Application::populate();
	}
	
	/**
	 * Start up method to call all necessary methods to load application data
	 */
	void ApplicationLowSecurity::startup(std::ifstream& inFile, ProjectList* projects)
	{
		Application::startup(inFile, projects);
	}
	
	/**
	 * Shut down method to call all necessary methods to persist application data 
	 */
	void ApplicationLowSecurity::shutdown(std::ofstream& outFile)
	{
		outFile << "0|";
		Application::shutdown(outFile);
	}