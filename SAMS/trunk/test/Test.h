#ifndef CPPUNIT_TEST_H
#define CPPUNIT_TEST_H

#include <string>

/*
 * A Test can be run and collect its results.
 * See TestResult.
 * 
 */

class Test
{
public:
    virtual ~Test () = 0;
	virtual void run ()    = 0;
    virtual std::string toString () = 0;
};

#endif

