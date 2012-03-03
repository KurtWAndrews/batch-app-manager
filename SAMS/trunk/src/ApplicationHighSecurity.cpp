/**
 * @file ApplicationHighSecurity.cpp
 * @brief High Security Application Definition
 * @author Kurt Andrews & Brian Royer
 */

#include <sstream>
#include "ApplicationHighSecurity.h"
#include "Team.h"

using namespace std;

/**
	 * High Security Application constructor
	 * @param _appId - new application id
	 * @param _desc - description of the new application
	 */
	ApplicationHighSecurity::ApplicationHighSecurity(int _riskLevel, const std::string& _appId,
			 const std::string& _desc, Team* _team)
			 : Application(_appId, _desc, _team)
	{
		setRiskLevel(_riskLevel);
	}
	
	/**
	 * High Security Application destructor
	 */
	ApplicationHighSecurity::~ApplicationHighSecurity()
	{
	}

	
	/**
	 * Add projects to an application
	 * @param projects - pointer to the project list
	 */
	void ApplicationHighSecurity::addProject(ProjectList* projects)
	{
	}
	
	/**
	 * Set all application attributes to empty strings, and null pointers etc
	 */
	void ApplicationHighSecurity::clearAttributes()
	{
		setRiskLevel(0);
		Application::clearAttributes();
	}
	
	/**
	 * Display the high security application
	 */
	void ApplicationHighSecurity::display() const
	{
		cout << "HIGH SECURITY APPLICATION" << endl << endl;
		cout << "Risk Level:\t" << getRiskLevel() << endl;
		Application::display();
	}
	
	/**
	 * Populate the high security application's attributes
	 */
	void ApplicationHighSecurity::populate()
	{
		int _riskLevel;

		Application::populate();
		
		cout << "Enter the risk level (1 - 5 : 5 being highest risk): ";
		cin >> _riskLevel;
	
		setRiskLevel(_riskLevel);
	}
	
	/**
	 * Start up method to call all necessary methods to load application data
	 */
	void ApplicationHighSecurity::startup(std::ifstream& inFile, ProjectList* projects)
	{
		std::string _riskLevel;
		int risk;
		std::istringstream stm;

		getline(inFile, _riskLevel, '|');
		stm.str(_riskLevel);
		stm >> risk;
		setRiskLevel(risk);

		Application::startup(inFile, projects);
	}
	
	/**
	 * Shut down method to call all necessary methods to persist application data 
	 */
	void ApplicationHighSecurity::shutdown(std::ofstream& outFile)
	{
		outFile << "1|"
				 << getRiskLevel() << '|';
		Application::shutdown(outFile);
	}