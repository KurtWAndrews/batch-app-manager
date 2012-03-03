/**
 * @file InternationalTeam.h
 * @brief International Team declaration
 * @author Kurt Andrews & Brian Royer
 */

#ifndef INTERNATIONALTEAM_H_
#define INTERNATIONALTEAM_H_

#include <fstream>
#include <map>

#include "Team.h"
#include "Date.h"
#include "EmployeeList.h"
#include "ApplicationLowSecurity.h"

class InternationalTeam : public Team
{
private:
	std::string country;
	std::string continent;
	std::map<std::string, Date*> empJoinDates;
public:
	/**
	 * The International Team constructor
	 * @param _country - country the team is from
	 * @param _continent - continent the team is from
	 */
	InternationalTeam(const std::string& _country = "",
			 const std::string& _continent = "",
			 const std::string& _teamId = "",
			 const std::string& _desc = "",
			 const std::string& _defaultApp = "");
	
	/**
	 * International Team destructor
	 */
	virtual ~InternationalTeam();
	
	/**
	 * Display the international team
	 */
	void display() const;

	/**
	 * Populate an international team
	 */
	void populate();
	
	/**
	 * Add employees to a team
	 * @param employees - pointer to the employee list
	 */
	void addMember(EmployeeList* employees);

	/**
	 * Remove employee from the team
	 * Used to delete the join date and remove from map
	 */
	void removeEmployee(Employee* emp);

	/**
	 * Add applications to a team
	 * @param applications - pointer to the application list
	 */
	void addApplication(ApplicationList* applications);

	/**
	 * Start up method to call all necessary methods to load international team data
	 * @param inFile - input file stream
	 * @param employees - pointer to the employee list
	 */
	void startup(std::ifstream& inFile, EmployeeList* employees, ApplicationList* applications);
	
	/**
	 * Shut down method to call all necessary methods to persist international team data
	 * @param outFile - output file stream
	 */
	void shutdown(std::ofstream& outFile);
	
	/**
	 * @return the international team's country
	 */
	std::string getCountry() const;
	
	/**
	 * @return the international team's continent
	 */
	std::string getContinent() const;
	
	/**
	 * Update the team's country with the specified value
	 * @param _country - the new country
	 */
	void setCountry(const std::string& _country);
	
	/**
	 * Update the team's continent with the specified value
	 * @param _continent - the new continent
	 */
	void setContinent(const std::string& _continent);
};

/**
 * Overload output operation for international team object
 */
std:: ostream & operator << (std::ostream& os, const InternationalTeam& team);

inline std::string InternationalTeam::getCountry() const {return country;}
inline void InternationalTeam::setCountry(const std::string& _country) {country = _country;}
inline std::string InternationalTeam::getContinent() const {return continent;}
inline void InternationalTeam::setContinent(const std::string& _continent) {continent = _continent;}

#endif /* INTERNATIONALTEAM_H_ */