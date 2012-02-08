#include "TestCase.h"
#include <string>

class AccountTest : public TestCase {
public:
  AccountTest(const std::string& name);
  void setUp();
	static Test* suite(); 
	void testCreate();

private:

};
