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
			"runAlgorithmNoCrossoverNormalCPUTest", &EvolutionaryAlgorithmTest::runAlgorithmNoCrossoverNormalCPUTest));
		suite->addTest(new CppUnit::TestCaller<EvolutionaryAlgorithmTest>(
			"runAlgorithmWithCrossoverNormalCPUTest", &EvolutionaryAlgorithmTest::runAlgorithmWithCrossoverNormalCPUTest));
		suite->addTest(new CppUnit::TestCaller<EvolutionaryAlgorithmTest>(
			"runAlgorithmNoCrossoverUniformCPUTest", &EvolutionaryAlgorithmTest::runAlgorithmNoCrossoverUniformCPUTest));
		suite->addTest(new CppUnit::TestCaller<EvolutionaryAlgorithmTest>(
			"runAlgorithmWithCrossoverUniformCPUTest", &EvolutionaryAlgorithmTest::runAlgorithmWithCrossoverUniformCPUTest));
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
		ealib::StopCondition stop_condition = ealib::StopCondition(1000, 4);
		ealib::EvolutionaryAlgorithm algorithm = ealib::EvolutionaryAlgorithm(pop,
																		stop_condition,
																		boost::bind(&EvolutionaryAlgorithmTest::myFitnessFunction, this, _1),
																		selection,
																		mutation);

		ealib::Result result = algorithm.run();
		CPPUNIT_ASSERT_MESSAGE("Try to test again if it fails.", result.getBestIndividual().getFitnessValue() > 4);
		CPPUNIT_ASSERT(result.getStepsTaken() <= 1000);
	}

	void runAlgorithmWithCrossoverNormalCPUTest()
	{
		ealib::eaoperator::NormalMutationOperatorPtr mutation = ealib::CPUObjectFactory::getInstance().getNormalMutationOperator(2,2);
		ealib::eaoperator::CrossoverOperatorPtr crossover = ealib::CPUObjectFactory::getInstance().getCrossoverOperator(0.1);
		ealib::SelectionPtr selection = ealib::CPUObjectFactory::getInstance().getSelection(ealib::Selection::PROPORTIONAL);
		ealib::StopCondition stop_condition = ealib::StopCondition(1000, 4);
		ealib::EvolutionaryAlgorithm algorithm = ealib::EvolutionaryAlgorithm(pop,
																		stop_condition,
																		boost::bind(&EvolutionaryAlgorithmTest::myFitnessFunction, this, _1),
																		selection,
																		mutation,
																		crossover);

		ealib::Result result = algorithm.run();
		CPPUNIT_ASSERT_MESSAGE("Try to test again if it fails.", result.getBestIndividual().getFitnessValue() > 4);
		CPPUNIT_ASSERT(result.getStepsTaken() <= 1000);
	}

	void runAlgorithmNoCrossoverUniformCPUTest()
	{
		ealib::eaoperator::UniformMutationOperatorPtr mutation = ealib::CPUObjectFactory::getInstance().getUniformMutationOperator(3,2);
		ealib::SelectionPtr selection = ealib::CPUObjectFactory::getInstance().getSelection(ealib::Selection::RANKIG);
		ealib::StopCondition stop_condition = ealib::StopCondition(1000, 4);
		ealib::EvolutionaryAlgorithm algorithm = ealib::EvolutionaryAlgorithm(pop,
																		stop_condition,
																		boost::bind(&EvolutionaryAlgorithmTest::myFitnessFunction, this, _1),
																		selection,
																		mutation);

		ealib::Result result = algorithm.run();
		CPPUNIT_ASSERT_MESSAGE("Try to test again if it fails.", result.getBestIndividual().getFitnessValue() > 4);
		CPPUNIT_ASSERT(result.getStepsTaken() <= 1000);
	}

	void runAlgorithmWithCrossoverUniformCPUTest()
	{
		ealib::eaoperator::UniformMutationOperatorPtr mutation = ealib::CPUObjectFactory::getInstance().getUniformMutationOperator(3,2);
		ealib::eaoperator::CrossoverOperatorPtr crossover = ealib::CPUObjectFactory::getInstance().getCrossoverOperator(0.1);
		ealib::SelectionPtr selection = ealib::CPUObjectFactory::getInstance().getSelection(ealib::Selection::RANKIG);
		ealib::StopCondition stop_condition = ealib::StopCondition(1000, 4);
		ealib::EvolutionaryAlgorithm algorithm = ealib::EvolutionaryAlgorithm(pop,
																		stop_condition,
																		boost::bind(&EvolutionaryAlgorithmTest::myFitnessFunction, this, _1),
																		selection,
																		mutation,
																		crossover);

		ealib::Result result = algorithm.run();
		CPPUNIT_ASSERT_MESSAGE("Try to test again if it fails.", result.getBestIndividual().getFitnessValue() > 4);
		CPPUNIT_ASSERT(result.getStepsTaken() <= 1000);
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

