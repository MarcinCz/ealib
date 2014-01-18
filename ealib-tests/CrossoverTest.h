#include <SearchSpace.h>
#include <Population.h>
#include <Individual.h>
#include <CrossoverOperator.h>
#include <OperatorFabric.h>
#include <cppunit\TestCase.h>
#include <cppunit\TestSuite.h>
#include <cppunit\TestCaller.h>
#include <boost\bind.hpp>
#include <vector>


class CrossoverTest : CppUnit::TestFixture
{
public:

	static CppUnit::TestSuite* suite()
	{
		CppUnit::TestSuite *suite = new CppUnit::TestSuite("PopulationTests");
		suite->addTest(new CppUnit::TestCaller<CrossoverTest>(
			"doCrossoverTest", &CrossoverTest::doCrossoverTest));

		return suite;
	}

	double myFitnessFunction(const ealib::Individual& ind)
	{
		return ind.getRepresentation()->at(0);
	}

	void setUp()
	{
		sp = new ealib::SearchSpace(boost::bind(&CrossoverTest::myFitnessFunction, this, _1));
		sp->getPopulation()->setRepresentationSize(1);
		std::vector<double> representation1;
		representation1.push_back(1);
		std::vector<double> representation2;
		representation2.push_back(2);
		sp->getPopulation()->addIndividual(representation1);
		sp->getPopulation()->addIndividual(representation2);
	}

	void tearDown()
	{
		delete sp;
	}

	void doCrossoverTest()
	{
		ealib::eaoperator::CrossoverOperatorPtr crosssover_operator = ealib::OperatorCPUFabric::getInstance().getCrossoverOperator(0.5);
		crosssover_operator->doCrossover(sp->getPopulation());

		int new_population_size = sp->getPopulation()->getPopulationSize();
		CPPUNIT_ASSERT_EQUAL_MESSAGE("Population size after crossover", 3, new_population_size);

		double new_ind_representation = sp->getPopulation()->getIndividuals().at(2)->getRepresentation()->at(0);
		CPPUNIT_ASSERT_EQUAL_MESSAGE("New individual representation", 1.5, new_ind_representation);
	}
	

private:
	ealib::SearchSpace *sp;
};

