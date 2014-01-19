#include <ealib\ObjectFactory.h>
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

	void setUp()
	{

		pop.setRepresentationSize(1);
		std::vector<double> representation1;
		representation1.push_back(1);
		std::vector<double> representation2;
		representation2.push_back(2);
		pop.addIndividual(representation1);
		pop.addIndividual(representation2);
	}

	void tearDown()
	{
		pop.clearPopulation();
	}

	void doCrossoverTest()
	{
		ealib::eaoperator::CrossoverOperatorPtr crosssover_operator = ealib::CPUObjectFactory::getInstance().getCrossoverOperator(0.5);
		crosssover_operator->doCrossover(pop);

		int new_population_size = pop.getPopulationSize();
		CPPUNIT_ASSERT_EQUAL_MESSAGE("Population size after crossover", 3, new_population_size);

		double new_ind_representation = pop.getIndividuals().at(2)->getRepresentation()->at(0);
		CPPUNIT_ASSERT_EQUAL_MESSAGE("New individual representation", 1.5, new_ind_representation);
	}
	

private:
	ealib::Population pop;
};

