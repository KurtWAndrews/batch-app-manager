
#ifndef CPPUNIT_TESTCALLER_H
#define CPPUNIT_TESTCALLER_H

#ifndef CPPUNIT_GUARDS_H
#include "Guards.h"
#endif

#ifndef CPPUNIT_TESTCASE_H
#include "TestCase.h"
#endif

/* 
 * A test caller provides access to a test case method 
 * on a test case class.  Test callers are useful when 
 * you want to run an individual test or add it to a 
 * suite.
 * 
 * You can use a TestCaller to bind any test method on a TestCase
 * class, as long as it returns accepts void and returns void.
 * 
 * See TestCase
 */
#include <memory>
#include <iostream>

using namespace std;

template <class Fixture> 
class TestCaller : public TestCase
{ 
    REFERENCEOBJECT (TestCaller)

	typedef void (Fixture::*TestMethod)();
    
public:
    TestCaller(std::string name, TestMethod test);

protected:
	void runTest();

    void setUp ();

    void tearDown ();

private:
   TestMethod               m_test;
   std::auto_ptr<Fixture>   m_fixture;

};

template <class Fixture>
TestCaller<Fixture>::TestCaller(std::string name, TestMethod test)
       : TestCase (name), m_fixture (new Fixture (name)), m_test (test)
{
	setUp();
}

template <class Fixture>
void TestCaller<Fixture>::runTest ()
{ 
	(m_fixture.get()->*m_test)(); 
}  

template <class Fixture>
void TestCaller<Fixture>::setUp()
{ 
	m_fixture.get()->setUp(); 
}

template <class Fixture>
void TestCaller<Fixture>::tearDown ()
{ 
	m_fixture.get()->tearDown(); 
}


#endif
