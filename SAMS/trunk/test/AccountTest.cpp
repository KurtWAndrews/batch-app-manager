#include "AccountTest.h"
#include "TestSuite.h"
#include "TestCaller.h"
#include "Account.h"

 
AccountTest::AccountTest(const std::string& name) : TestCase(name) {}

void AccountTest::setUp() {}

Test* AccountTest::suite() {
	TestSuite* accountSuite = new TestSuite();
	accountSuite->addTest(new TestCaller<AccountTest>("testCreate", &AccountTest::testCreate));

//	stackSuite->addTest(new TestCaller<StackTest>("testPush", &StackTest::testPush));
//	stackSuite->addTest(new TestCaller<StackTest>("testTop", &StackTest::testTop));
//	stackSuite->addTest(new TestCaller<StackTest>("testPop", &StackTest::testPop));
//	stackSuite->addTest(new TestCaller<StackTest>("testPopExc", &StackTest::testPopExc));

	return accountSuite;
}

void AccountTest::testCreate() {
  Account* a = new Account();

	assertEquals(NULL != a);

	delete a;
}

/*
void StackTest::testPush()
{
	Stack* s = new Stack();

	s->push(25);

	assertEquals(1 == s->getSize());

//	assertEquals(1 == s->getTop());

	delete s;

}
*/
/*
void StackTest::testTop()
{
	Stack* s = new Stack();

	s->push(25);

	assertEquals(25 == s->getTop());

	delete s;

}
*/
/*

void StackTest::testPop()
{
	Stack* s = new Stack();

	s->push(25);

	int value = s->pop();

	assertEquals(value == 25);

	assertEquals(0 == s->getSize());

	delete s;
}
*/
/*
void StackTest::testPopExc()
{
	Stack* s = new Stack();

	try {
		int value;
		value = s->pop();
		assertMsg("No Exception Thrown");
	}
	catch (std::logic_error&) {
	
	}
	catch (...) {
		assertMsg("Wrong exception thrown");
	}

	delete s;
}
*/