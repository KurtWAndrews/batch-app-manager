#include "AccountTest.h"
#include "TestResult.h"
#include "TestSuite.h"

int main() {		
  Test* suite = AccountTest::suite();
	
  suite->run();
	
  (TestResult::getInstance())->displayResults();

  return 0;
}