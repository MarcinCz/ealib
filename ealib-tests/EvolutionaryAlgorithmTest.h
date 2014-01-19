#include <ealib\ObjectFactory.h>
#include <ealib\EvolutionaryAlgorithm.h>
#include <boost\bind.hpp>
#include <cppunit\TestCase.h>
#include <cppunit\TestSuite.h>
#include <cppunit\TestCaller.h>
#include <vector>


class EvolutionaryAlgorithmTest : CppUnit::TestFixture
{
public:

	static CppUnit::TestSuite* suite()
	{
		CppUnit::TestSuite *suite = new CppUnit::TestSuite("PopulationTests");
		suite->addTest(new CppUnit::TestCaller<EvolutionaryAlgorithmTest>(
			"doSelectionRankingCPUTest", &EvolutionaryAlgorithmTest::runAlgorithmNoCrossoverNormalCPUTest));

		return suite;

	}
	
	double myFitnessFunction(const ealib::Individual& ind)
	{
		return ind.getRepresentation()->at(0);
	}

	void runAlgorithmNoCrossoverNormalCPUTest()
	{
		ealib::eaoperator::NormalMutationOperatorPtr mutation = ealib::CPUObjectFactory::getInstance().getNormalMutationOperator(2,2);
		ealib::SelectionPtr selection = ealib::CPUObjectFactory::getInstance().getSelection(ealib::Selection::RANKIG);
		ealib::StopCondition stop_condition = ealib::StopCondition(1000, 5);
		ealib::EvolutionaryAlgorithm algorithm = ealib::EvolutionaryAlgorithm(pop,
																		stop_condition,
																		boost::bind(&EvolutionaryAlgorithmTest::myFitnessFunction, this, _1),
																		selection,
																		mutation);

		ealib::Result result = algorithm.run();
		CPPUNIT_ASSERT(result.getBestIndividual().getFitnessValue() > 2);
	}

	void setUp()
	{
		pop.setRepresentationSize(1);
		for (int i = 0; i < 100; ++i)
			pop.genIndividual(0, 1);
	}

	void tearDown()
	{
		pop.clearPopulation();
	}

private:
	ealib::Population pop;
};

