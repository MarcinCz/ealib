#include <ealib/Population.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <boost/bind.hpp>
#include <vector>



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
		suite->addTest(new CppUnit::TestCaller<PopulationTest>(
			"setNegativeRepresentationSizeTest", &PopulationTest::setNegativeRepresentationSizeTest));
		return suite;
	}

	double myFitnessFunction(const ealib::Individual& ind)
	{
		return ind.getRepresentation()->at(0);
	}

	void setUp()
	{
		pop.setRepresentationSize(8);
	}

	void tearDown()
	{
		pop.clearPopulation();
	}

	void addIndividualsTest()
	{
		std::vector<double> representation;
		for (int i = 1; i < 9; i++)
		{
			representation.push_back(i);
		}
		pop.addIndividual(representation);
		pop.genIndividual(0, 10);
		pop.genIndividual(4.5, 15.5);

		CPPUNIT_ASSERT_EQUAL(3, static_cast<int>(pop.getPopulationSize()));
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
			pop.addIndividual(representation),
			ealib::exception::PopulationException);
	}

	void setRepresentationSizeTest()
	{
		pop.setRepresentationSize(6);
		CPPUNIT_ASSERT_EQUAL(6, pop.getRepresentationSize());

		pop.genIndividual(0, 1);
		CPPUNIT_ASSERT_THROW_MESSAGE(
			"Population need to be empty before representation size change.",
			pop.setRepresentationSize(7),
			ealib::exception::PopulationException);

	}

	void setNegativeRepresentationSizeTest()
	{
		CPPUNIT_ASSERT_THROW_MESSAGE(
			"Representation size must be positive.",
			pop.setRepresentationSize(0),
			ealib::exception::PopulationException);
	}

private:
	ealib::Population pop;
};

