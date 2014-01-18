#include <SearchSpace.h>
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
		std::vector<ealib::IndividualPtr> selected_individuals;
		sp->getSelection()->setSelectionType(ealib::Selection::SelectionType::RANKIG);
		selected_individuals = sp->getSelection()->doSelectionCPU(sp->getPopulation(), boost::bind(&SelectionTest::myFitnessFunction, this, _1), 6);
		size_t size = 6;
		CPPUNIT_ASSERT_EQUAL(size, selected_individuals.size());
	}
	
	void doSelectionProportionalCPUTest()
	{
		std::vector<ealib::IndividualPtr> selected_individuals;
		sp->getSelection()->setSelectionType(ealib::Selection::SelectionType::PROPORTIONAL);
		selected_individuals = sp->getSelection()->doSelectionCPU(sp->getPopulation(), boost::bind(&SelectionTest::myFitnessFunction, this, _1), 6);
		size_t size = 6;
		CPPUNIT_ASSERT_EQUAL(size, selected_individuals.size());
	}

	void setUp()
	{
		sp = new ealib::SearchSpace(boost::bind(&SelectionTest::myFitnessFunction, this, _1));
		sp->getPopulation()->setRepresentationSize(8);
		for (int i = 0; i < 10; ++i)
			sp->getPopulation()->genIndividual(0, 1);
	}

	void tearDown()
	{
		delete sp;
	}

private:
	ealib::SearchSpace *sp;
};

