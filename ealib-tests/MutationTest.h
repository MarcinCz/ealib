#include <ealib/ObjectFactory.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
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
		pop.setRepresentationSize(8);
		pop.genIndividual(0, 1, 100);
	}

	void tearDown()
	{
		pop.clearPopulation();
	}

	void doMutationTest()
	{

		ealib::eaoperator::UniformMutationOperatorPtr uniform_mutation_opeator = ealib::CPUObjectFactory::getInstance().getUniformMutationOperator(2, 100);
		CPPUNIT_ASSERT_NO_THROW(uniform_mutation_opeator->doMutation(pop));

		ealib::eaoperator::NormalMutationOperatorPtr normal_mutation_opeator = ealib::CPUObjectFactory::getInstance().getNormalMutationOperator(2, 100);
		CPPUNIT_ASSERT_NO_THROW(normal_mutation_opeator->doMutation(pop));

		CPPUNIT_ASSERT(true);
		
	}

	void wrongProbabilityTest()
	{
		CPPUNIT_ASSERT_THROW_MESSAGE("Probability must be between or equal to 0 and 100.",
			ealib::CPUObjectFactory::getInstance().getUniformMutationOperator(2, 101),
			ealib::exception::MutationOperatorException);
		
		CPPUNIT_ASSERT_THROW_MESSAGE("Probability must be between or equal to 0 and 100.",
			ealib::CPUObjectFactory::getInstance().getNormalMutationOperator(2, 101),
			ealib::exception::MutationOperatorException);
	}

private:
	ealib::Population pop;
};

