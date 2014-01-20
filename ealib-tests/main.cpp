#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TestRunner.h>
#include "PopulationTest.h"
#include "SelectionTest.h"
#include "MutationTest.h"
#include "CrossoverTest.h"
#include "StopConditionTest.h"
#include "EvolutionaryAlgorithmTest.h"

int main()
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(PopulationTest::suite());
	runner.addTest(SelectionTest::suite());
	runner.addTest(MutationTest::suite());
	runner.addTest(CrossoverTest::suite());
	runner.addTest(StopConditionTest::suite());
	runner.addTest(EvolutionaryAlgorithmTest::suite());
	runner.run();
	std::cin.get();
	return 0;
}
