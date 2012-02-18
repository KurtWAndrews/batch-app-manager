/**
 * @file InternationalTeam.cpp
 * @brief International Team Definition
 * @author Kurt Andrews & Brian Royer
 */

#include <iostream>
#include <ctime>
#include "InternationalTeam.h"

using namespace std;

InternationalTeam::InternationalTeam(const string& _country,
					 const string& _continent) : Team() {
	setCountry(_country);
	setContinent(_continent);
}

InternationalTeam::~InternationalTeam() {
	cout << "Executing InternationalTeam Destructor" << endl;

	map<string, Date*>::iterator iter;

	for(iter = empJoinDates.begin(); iter != empJoinDates.end(); ++ iter) {
		delete iter->second;
	}

	empJoinDates.clear();
}

void InternationalTeam::addMember(EmployeeList* employees) {
	Team::addMember(employees);
	
	map<string, Date*>::const_iterator iter;
	std::vector<Employee*>* members = getMembersToChange();

	for(int i = (members->size() - 1); i > -1; i--)
	{
		iter = empJoinDates.find(members->at(i)->getEmployeeId());
		if(iter == empJoinDates.end())
		{
			time_t t = time(0);   // get time now
			struct tm * now = localtime( & t );
			Date* date = new Date(now->tm_mon + 1, now->tm_mday, now->tm_year + 1900, members->at(i));
			empJoinDates.insert(pair<string, Date*>(members->at(i)->getEmployeeId(), date));
		}
		else
		{
			return;
		}
	}
}

void InternationalTeam::display() const{
	map<string, Date*>::const_iterator iter;
	std::vector<Employee*> const* members = getMembers();

	cout << "Team ID:\t" << getTeamId() << endl;
	cout << "Description:\t" << getDesc() << endl;
	cout << "defaultApplication:\t" << getDefaultApp() << endl;
	cout << "Location:\t" << getCountry() << ", " << getContinent() << endl << endl;
	
	cout << "*** T E A M  R O S T E R***" << endl << endl;
	
	for (int i = 0; i < members->size(); i++) {
		iter = empJoinDates.find(members->at(i)->getEmployeeId());

		cout << members->at(i)->getEmployeeId() << " - "
				 << members->at(i)->getLastName() << ", "
				 << members->at(i)->getFirstName()
				 << " | Joined on: ";
		iter->second->display();
		cout << endl;
	}
}

void InternationalTeam::populate() {
	string _country;
	string _continent;
	
	Team::populate();
	
	cout << "Enter the team's country: ";
	getline(cin, _country);
	cout << "Enter the team's continent: ";
	getline(cin, _continent);
	
	setCountry(_country);
	setContinent(_continent);
}

void InternationalTeam::removeEmployee(Employee* emp)
{	
	Team::removeEmployee(emp);

	string id = emp->getEmployeeId();
	map<string, Date*>::const_iterator iter;
	iter = empJoinDates.find(id);

	delete iter->second;
	empJoinDates.erase(id);
}

void InternationalTeam::startup(ifstream& inFile, EmployeeList* employees) {
	std::vector<Employee*>* members = getMembersToChange();

	string _country;
	getline(inFile, _country, '|');
	setCountry(_country);
	
	string _continent;
	getline(inFile, _continent, '|');
	setContinent(_continent);
	
	Team::startup(inFile, employees);
	
	int recs;
	string _employeeId;
	Employee* member = NULL;
	inFile >> recs;
	inFile.ignore();
	
	for (int rec = 0; rec < recs; ++rec) {
		getline(inFile, _employeeId, '|');
		member = employees->find(_employeeId);
		
		if (member != NULL) {
			member->setTeam((Team*) this);
			members->push_back(member);
		}

		string _month;
		string _day;
		string _year;
		getline(inFile, _month, '.');
		getline(inFile, _day, '.');
		getline(inFile, _year);

		Date* date = new Date(atoi(_month.c_str()), atoi(_day.c_str()), atoi(_year.c_str()), member);
		empJoinDates.insert(pair<string, Date*>(_employeeId, date));
	}
}

void InternationalTeam::shutdown(ofstream& outFile)
{
	std::vector<Employee*> const* members = getMembers();
	std::string empId;

	outFile << "1|"
					<< getCountry() << '|'
					<< getContinent() << '|';
	
	Team::shutdown(outFile);
	
	map<string, Date*>::const_iterator iter;

	for (long int rec = 0; rec < members->size(); rec++) {
		empId = members->at(rec)->getEmployeeId();
		iter = empJoinDates.find(empId);
		outFile << empId << '|'
						<< iter->second->getMonth() << '.'
						<< iter->second->getDay() << '.'
						<< iter->second->getYear() << endl;
	}
} 