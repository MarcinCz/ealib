#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TestRunner.h>
#include "PopulationTest.h"
#include "SelectionTest.h"

int main()
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(PopulationTest::suite());
	runner.addTest(SelectionTest::suite());
	runner.run();
	std::cin.get();
	return 0;
}