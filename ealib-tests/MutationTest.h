#include <SearchSpace.h>
#include <Population.h>
#include <Individual.h>
#include <NormalMutationOperator.h>
#include <UniformMutationOperator.h>
#include <OperatorFabric.h>
#include <cppunit\TestCase.h>
#include <cppunit\TestSuite.h>
#include <cppunit\TestCaller.h>
#include <vector>


class MutationTest : CppUnit::TestFixture
{
public:

	static CppUnit::TestSuite* suite()
	{
		CppUnit::TestSuite *suite = new CppUnit::TestSuite("PopulationTests");
		suite->addTest(new CppUnit::TestCaller<MutationTest>(
			"doMutationTest", &MutationTest::doMutationTest));
		suite->addTest(new CppUnit::TestCaller<MutationTest>(
			"wrongProbabilityTest", &MutationTest::wrongProbabilityTest));
		return suite;
	}

	double myFitnessFunction(const ealib::Individual& ind)
	{
		return ind.getRepresentation()->at(0);
	}

	void setUp()
	{
		sp = new ealib::SearchSpace(boost::bind(&MutationTest::myFitnessFunction, this, _1));
		sp->getPopulation()->setRepresentationSize(8);
		sp->getPopulation()->genIndividual(0, 1, 100);
	}

	void tearDown()
	{
		delete sp;
	}

	void doMutationTest()
	{
		ealib::eaoperator::MutationOperatorPtr uniform_mutation_opeator = ealib::OperatorCPUFabric::getInstance().getUniformMutationOperator(2, 100);
		CPPUNIT_ASSERT_NO_THROW(uniform_mutation_opeator->doMutation(sp->getPopulation()));

		ealib::eaoperator::MutationOperatorPtr normal_mutation_opeator = ealib::OperatorCPUFabric::getInstance().getNormalMutationOperator(2, 100);
		CPPUNIT_ASSERT_NO_THROW(normal_mutation_opeator->doMutation(sp->getPopulation()));

		CPPUNIT_ASSERT(true);
		
	}

	void wrongProbabilityTest()
	{
		CPPUNIT_ASSERT_THROW_MESSAGE("Probability must be between or equal to 0 and 100.",
			ealib::OperatorCPUFabric::getInstance().getUniformMutationOperator(2, 101),
			ealib::exception::MutationOperatorException);
		
		CPPUNIT_ASSERT_THROW_MESSAGE("Probability must be between or equal to 0 and 100.",
			ealib::OperatorCPUFabric::getInstance().getNormalMutationOperator(2, 101),
			ealib::exception::MutationOperatorException);
	}

private:
	ealib::SearchSpace *sp;
};

