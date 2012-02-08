#include "TestResult.h"
#include "Test.h"

#include <iostream>
using namespace std;

TestResult* TestResult::instance_ = 0;

TestResult* TestResult::getInstance()
{
	if (instance_ == 0) {
		instance_ = new TestResult();
	}
	return instance_;
}

// Construct a TestResult
TestResult::TestResult ()
{ 
	m_runTests = 0; 
}

//
//  Destructor
//
TestResult::~TestResult()
{
cout << "TestResult:: destr" << endl;
}

// Adds a failure to the list of failures. The passed in exception
// caused the failure.
void TestResult::addFailure (Test *test, CppUnitException *e)
{ 
	m_failures.push_back (new TestFailure (test, e)); 
}


// Informs the result that a test will be started.
void TestResult::startTest (Test *test)
{ 
	m_runTests++; 
}

  
// Informs the result that a test was completed.
void TestResult::endTest (Test *test)
{ 

}


// Gets the number of run tests.
int TestResult::runTests ()
{ 
	return m_runTests; 
}

// Gets the number of detected failures.
int TestResult::testFailures ()
{ 
	return m_failures.size(); 
}


// Returns whether the entire test was successful or not.
bool TestResult::wasSuccessful ()
{ 
	return m_failures.size () == 0; 
}

// Returns a vector of the failures.
std::vector<TestFailure *>& TestResult::failures()
{ 
	return m_failures; 
}

void TestResult::displayResults()
{
	cout << "Number of tests   : " << runTests() << "\n" << endl;

	displayFailures();
}


void TestResult::displayFailures()
{
	using namespace std;

	vector<TestFailure*>::iterator iter;

	cout << "   Number of failed tests: " << m_failures.size() << endl;
	cout << endl;
	if (m_failures.size() > 0) {

		cout << "      Displaying failures" << endl;
		cout << "      -------------------\n" << endl;

		for (iter = m_failures.begin(); iter != m_failures.end(); ++iter) {

			cout << "      Name of test: " << (*iter)->failedTest()->toString() << endl;

			cout << "      Test spec   : " << (*iter)->thrownException()->what() << endl;
			cout << "      Line number : " << (*iter)->thrownException()->lineNumber() << endl;
			cout << "      File name   : " << (*iter)->thrownException()->fileName() << endl;

			cout << "\n\n" << endl;
		}
	}

}

