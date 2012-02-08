#ifndef CPPUNIT_TESTCASE_H
#define CPPUNIT_TESTCASE_H

#include <string>
#include <typeinfo>
#include "Guards.h"
#include "Test.h"
#include "CppUnitException.h"
#include "TestResult.h"

/*
 */

#define assertEquals(condition)\
 if ((condition) == false) {\
 (TestResult::getInstance())->addFailure(this, new CppUnitException((#condition),\
			                                   __LINE__,\
											   __FILE__));\
											   return;\
}

#define assertMsg(message)\
 (TestResult::getInstance())->addFailure(this, new CppUnitException((#message),\
			                                   __LINE__,\
											   __FILE__));\
											   return;

class TestCase : public Test 
{
    REFERENCEOBJECT (TestCase)

public:
    TestCase(const std::string& name);
    ~TestCase();

	virtual void run();

    std::string name();
    std::string toString();

    virtual void setUp();
    virtual void tearDown();

protected:

	virtual void runTest();
    
private:
    std::string m_name;
};


#endif
