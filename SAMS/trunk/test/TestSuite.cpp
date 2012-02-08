#include "TestSuite.h"

#include <iostream>
using namespace std;

// Default constructor
TestSuite::TestSuite (const std::string& name)
: m_name (name)
{

}

// Destructor
TestSuite::~TestSuite ()
{ 
	deleteContents (); 
}

// Adds a test to the suite. 
void TestSuite::addTest (Test *test)
{ 
	m_tests.push_back (test); 
}


// Returns a string representation of the test suite.
std::string TestSuite::toString ()
{ 
	return "suite " + m_name; 
}

void TestSuite::deleteContents()
{

}

void TestSuite::run()
{
	vector<Test*>::iterator iter;

	for (iter = m_tests.begin(); iter != m_tests.end(); ++iter) {

		(*iter)->run();
	}

}