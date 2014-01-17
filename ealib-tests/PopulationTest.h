#include <SearchSpace.h>
#include <Population.h>
#include <Individual.h>
#include <cppunit\TestCase.h>
#include <cppunit\TestSuite.h>
#include <cppunit\TestCaller.h>
#include <vector>

double myFitnessFunction(const ealib::Individual& ind)
{
	return ind.getRepresentation()->at(0);
}

class PopulationTest : CppUnit::TestFixture
{
public:

	static CppUnit::TestSuite* suite()
	{
		CppUnit::TestSuite *suite = new CppUnit::TestSuite("PopulationTests");
		suite->addTest(new CppUnit::TestCaller<PopulationTest>(
			"addIndividualsTest", &PopulationTest::addIndividualsTest));
		suite->addTest(new CppUnit::TestCaller<PopulationTest>(
			"addIndividualWrongRepresentationTest", &PopulationTest::addIndividualWrongRepresentationTest));
		suite->addTest(new CppUnit::TestCaller<PopulationTest>(
			"setRepresentationSizeTest", &PopulationTest::setRepresentationSizeTest));
		return suite;
	}

	void setUp()
	{
		sp = new ealib::SearchSpace(&myFitnessFunction);
		sp->getPopulation()->setRepresentationSize(8);
	}

	void tearDown()
	{
		delete sp;
	}

	void addIndividualsTest()
	{
		std::vector<double> representation;
		for (int i = 1; i < 9; i++)
		{
			representation.push_back(i);
		}
		sp->getPopulation()->addIndividual(representation);
		sp->getPopulation()->genIndividual(0, 10);
		sp->getPopulation()->genIndividual(4.5, 15.5);

		CPPUNIT_ASSERT_EQUAL(3, sp->getPopulation()->getPopulationSize());
	}

	void addIndividualWrongRepresentationTest()
	{
		std::vector<double> representation;
		for (int i = 1; i < 8; i++)
		{
			representation.push_back(i);
		}
		CPPUNIT_ASSERT_THROW_MESSAGE(
			"Wrong representation size. Current size set is 8",
			sp->getPopulation()->addIndividual(representation),
			ealib::exception::PopulationException);
	}

	void setRepresentationSizeTest()
	{
		sp->getPopulation()->setRepresentationSize(6);
		CPPUNIT_ASSERT_EQUAL(6, sp->getPopulation()->getRepresentationSize());

		sp->getPopulation()->genIndividual(0, 1);
		CPPUNIT_ASSERT_THROW_MESSAGE(
			"Population need to be empty before representation size change.",
			sp->getPopulation()->setRepresentationSize(7),
			ealib::exception::PopulationException);

	}

private:
	ealib::SearchSpace *sp;
};

