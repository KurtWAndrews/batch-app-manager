#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int _month,
			 int _day,
			 int _year,
			 Employee* _emp)
{
	setMonth(_month);
	setDay(_day);
	setYear(_year);
	setEmployee(_emp);
}

Date::~Date()
{
}

void Date::display() const
{
	cout << getMonth() << "." << getDay() << "." << getYear();
}