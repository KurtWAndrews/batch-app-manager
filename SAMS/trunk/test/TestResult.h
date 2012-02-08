#ifndef CPPUNIT_TESTRESULT_H
#define CPPUNIT_TESTRESULT_H

#include <vector>

#ifndef CPPUNIT_GUARDS_H
#include "Guards.h"
#endif

#ifndef CPPUNIT_TESTFAILURE_H
#include "TestFailure.h"
#endif


class CppUnitException;
class Test;


/*
 * A TestResult collects the results of executing a test case. It is an 
 * instance of the Collecting Parameter pattern.
 *
 */

class TestResult
{
   REFERENCEOBJECT (TestResult)

public:

    ~TestResult();
    void addFailure(Test *test, CppUnitException *e);
    void startTest(Test *test);
    void endTest(Test *test);
    int runTests();
    int testFailures();
    bool wasSuccessful();
	void displayFailures();
	void displayResults();
    std::vector<TestFailure *>& failures();

	static TestResult* getInstance();

private:
    TestResult();
    std::vector<TestFailure *>  m_failures;
    int                         m_runTests;

	static TestResult* instance_;
};


#endif


