#ifndef CPPUNIT_TESTSUITE_H
#define CPPUNIT_TESTSUITE_H

#include <vector>
#include <string>

#ifndef CPPUNIT_GUARDS_H
#include "Guards.h"
#endif

#ifndef CPPUNIT_TEST_H
#include "Test.h"
#endif


/*
 * A TestSuite is a Composite of Tests.
 * It runs a collection of test cases. Here is an example.
 * 
 * TestSuite *suite= new TestSuite();
 * suite->addTest(new TestCaller<MathTest> ("testAdd", testAdd));
 * suite->addTest(new TestCaller<MathTest> ("testDivideByZero", testDivideByZero));
 * 
 * Note that TestSuites assume lifetime
 * control for any tests added to them.
 *
 */


class TestSuite : public Test
{
    REFERENCEOBJECT (TestSuite)

public:
    TestSuite(const std::string& name = "");
    ~TestSuite();

	void run();

    void addTest(Test* test);
    std::string toString();

    virtual void deleteContents();

private:
    std::vector<Test*> m_tests;
    std::string  m_name;
};


#endif
