#include <SearchSpace.h>
#include <Population.h>
#include <Individual.h>
#include <NormalDistMutationOperator.h>
#include <UniformDistMutationOperator.h>
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

	void setUp()
	{
		sp = new ealib::SearchSpace(&myFitnessFunction);
		sp->getPopulation()->setRepresentationSize(8);
		sp->getPopulation()->genIndividual(0, 1, 100);
	}

	void tearDown()
	{
		delete sp;
	}

	void doMutationTest()
	{
		ealib::MutationOperatorPtr uniform_mutation_opeator = ealib::OperatorFabric::getInstance().getUniformDistMutationOperator(2, 100);
		CPPUNIT_ASSERT_NO_THROW(uniform_mutation_opeator->doMutationCPU(sp->getPopulation()));

		ealib::MutationOperatorPtr normal_mutation_opeator = ealib::OperatorFabric::getInstance().getNormalDistMutationOperator(2, 100);
		CPPUNIT_ASSERT_NO_THROW(normal_mutation_opeator->doMutationCPU(sp->getPopulation()));
		;
	}

	void wrongProbabilityTest()
	{
		CPPUNIT_ASSERT_THROW_MESSAGE("Probability must be between or equal to 0 and 100.",
			ealib::OperatorFabric::getInstance().getUniformDistMutationOperator(2, 101),
			ealib::exception::MutationOperatorException);
		
		CPPUNIT_ASSERT_THROW_MESSAGE("Probability must be between or equal to 0 and 100.",
			ealib::OperatorFabric::getInstance().getNormalDistMutationOperator(2, 101),
			ealib::exception::MutationOperatorException);
	}

private:
	ealib::SearchSpace *sp;
};

