#include <ObjectFactory.h>
#include <Selection.h>
#include <Population.h>
#include <Individual.h>
#include <boost\bind.hpp>
#include <cppunit\TestCase.h>
#include <cppunit\TestSuite.h>
#include <cppunit\TestCaller.h>
#include <vector>


class SelectionTest : CppUnit::TestFixture
{
public:

	static CppUnit::TestSuite* suite()
	{
		CppUnit::TestSuite *suite = new CppUnit::TestSuite("PopulationTests");
		suite->addTest(new CppUnit::TestCaller<SelectionTest>(
			"doSelectionRankingCPUTest", &SelectionTest::doSelectionRankingCPUTest));
		suite->addTest(new CppUnit::TestCaller<SelectionTest>(
			"doSelectionProportionalCPUTest", &SelectionTest::doSelectionProportionalCPUTest));
		return suite;
	}
	
	double myFitnessFunction(const ealib::Individual& ind)
	{
		return ind.getRepresentation()->at(0);
	}

	void doSelectionRankingCPUTest()
	{
		ealib::SelectionPtr selection = ealib::CPUObjectFactory::getInstance().getSelection(ealib::Selection::SelectionType::RANKIG);
		selection->doSelection(pop, boost::bind(&SelectionTest::myFitnessFunction, this, _1), 6);
		CPPUNIT_ASSERT_EQUAL_MESSAGE("Population size after selection", 6, pop.getPopulationSize());
	}
	
	void doSelectionProportionalCPUTest()
	{
		ealib::SelectionPtr selection = ealib::CPUObjectFactory::getInstance().getSelection(ealib::Selection::SelectionType::PROPORTIONAL);
		selection->doSelection(pop, boost::bind(&SelectionTest::myFitnessFunction, this, _1), 6);
		CPPUNIT_ASSERT_EQUAL_MESSAGE("Population size after selection",6, pop.getPopulationSize());
	}

	void setUp()
	{
		pop.setRepresentationSize(8);
		for (int i = 0; i < 10; ++i)
			pop.genIndividual(0, 1);
	}

	void tearDown()
	{
		pop.clearPopulation();
	}

private:
	ealib::Population pop;
};

