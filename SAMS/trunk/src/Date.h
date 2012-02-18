/**
 * @file Date.h
 * @brief Date declaration
 * @author Kurt Andrews & Brian Royer
 */
#ifndef DATE_H_
#define DATE_H_

#include "Team.h"
#include "Employee.h"

class Date
{
private:
	int month;
	int day;
	int year;
	Employee* emp;
public:/**
	 * The Date constructor
	 * @param _month - month of the year
	 * @param _day - day of the month
	 * @param _year - the year
	 */
	Date(int _month = 1,
			 int _day = 1,
			 int _year = 1900,
			 Employee* _emp = NULL);
	
	/**
	 * Date destructor
	 */
	virtual ~Date();
	
	/**
	 * Display the international team
	 */
	void display() const;
	
	/**
	 * @return the date's month
	 */
	int getMonth() const;
	
	/**
	 * @return the date's day
	 */
	int getDay() const;
	
	/**
	 * @return the date's year
	 */
	int getYear() const;
	
	/**
	 * @return the date's associated employee
	 */
	Employee* getEmployee() const;
	
	/**
	 * Update the date's month
	 * @param _month - the new month
	 */
	void setMonth(int _month);
	
	/**
	 * Update the date's day
	 * @param _day - the new day
	 */
	void setDay(int _day);
	
	/**
	 * Update the date's year
	 * @param _year - the new year
	 */
	void setYear(int _year);
	
	/**
	 * Update the date's associated employee
	 * @param _emp - the employee object
	 */
	void setEmployee(Employee* _emp);
};

/**
 * Overload output operation for date object
 */
std::ostream & operator << (std::ostream& os, const Date& d);

inline int Date::getMonth() const {return month;}
inline void Date::setMonth(int _month) {month = _month;}
inline int Date::getDay() const {return day;}
inline void Date::setDay(int _day) {day = _day;}
inline int Date::getYear() const {return year;}
inline void Date::setYear(int _year) {year = _year;}
inline Employee* Date::getEmployee() const {return emp;}
inline void Date::setEmployee(Employee* _emp) {emp = _emp;}

#endif /* DATE_H_ */