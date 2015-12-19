#include "CppUnit/TestRunner.h"
#include "ISO-8583-DTT-TestSuite.h"


//CppUnitMain(ALS::BASE::ADDR::BaseTestSuite)
int main(int ac, char **av)							
{													
std::vector<std::string> args;					
for (int i = 0; i < ac; ++i)					
	args.push_back(std::string(av[i]));			
	CppUnit::TestRunner runner;						
	runner.addTest("ISO-8583-2003-DTT-TestSuite", ISO_8583::DTT::TestSuite::suite());
	return runner.run(args) ? 0 : 1;				
}
