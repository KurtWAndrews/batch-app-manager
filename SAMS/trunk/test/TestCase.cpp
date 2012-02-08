#include "TestCase.h"
#include "TestResult.h"

#include <iostream>

using namespace std;


// Constructs a test case
TestCase::TestCase (const std::string& name) 
: m_name (name) 
{

}


// Destructs a test case
TestCase::~TestCase ()
{

}


// Returns the name of the test case
std::string TestCase::name ()
{ 
	return m_name; 
}


// A hook for fixture set up
void TestCase::setUp ()
{

}

// A hook for fixture tear down
void TestCase::tearDown ()
{

}

// Returns the name of the test case instance
std::string TestCase::toString ()
{ 
	const type_info& thisClass = typeid (*this); 
	return std::string (thisClass.name ()) + "." + name (); 
}

void TestCase::run()
{
	(TestResult::getInstance())->startTest(this);
	runTest();
	(TestResult::getInstance())->endTest(this);
}


void TestCase::runTest()
{

}
