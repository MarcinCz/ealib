#include <StopCondition.h>
#include <cppunit\TestCase.h>
#include <cppunit\TestSuite.h>
#include <cppunit\TestCaller.h>

class StopConditionTest : public CppUnit::TestFixture
{
public:

	static CppUnit::TestSuite* suite()
	{
		CppUnit::TestSuite *suite = new CppUnit::TestSuite("PopulationTests");
		suite->addTest(new CppUnit::TestCaller<StopConditionTest>(
			"createStopConditionTest", &StopConditionTest::createStopConditionTest));
		suite->addTest(new CppUnit::TestCaller<StopConditionTest>(
			"negativeStepsNumberTest", &StopConditionTest::negativeStepsNumberTest));
		suite->addTest(new CppUnit::TestCaller<StopConditionTest>(
			"getNotSetValuesTest", &StopConditionTest::getNotSetValuesTest));
		return suite;
	}

	void createStopConditionTest()
	{
		float fitness_val = 1.0;
		int steps = 5;
		ealib::StopCondition stop_condition = ealib::StopCondition(fitness_val);
		CPPUNIT_ASSERT_EQUAL(true, stop_condition.isMinFitnessValueSet());
		CPPUNIT_ASSERT_EQUAL(false, stop_condition.isMaxStepsSet());
		CPPUNIT_ASSERT_EQUAL(1.0, stop_condition.getMinFitnessValue());

		stop_condition = ealib::StopCondition(steps, fitness_val);
		CPPUNIT_ASSERT_EQUAL(true, stop_condition.isMaxStepsSet());
		CPPUNIT_ASSERT_EQUAL(5, stop_condition.getMaxSteps());

	}

	void negativeStepsNumberTest()
	{
		int steps = 1;
		ealib::StopCondition stop_condition = ealib::StopCondition(steps);
		CPPUNIT_ASSERT_THROW_MESSAGE(
			"Steps number must be positive.",
			stop_condition.setMaxSteps(-1),
			ealib::exception::StopConditionException);
	}

	void getNotSetValuesTest()
	{
		float fitness_val = 1.0;
		int steps = 5;
		ealib::StopCondition stop_condition = ealib::StopCondition(fitness_val);
		CPPUNIT_ASSERT_THROW_MESSAGE(
			"Max steps number not set.",
			stop_condition.getMaxSteps(),
			ealib::exception::StopConditionException);

		stop_condition = ealib::StopCondition(steps);
		CPPUNIT_ASSERT_THROW_MESSAGE(
			"Min fitness value not set.",
			stop_condition.getMinFitnessValue(),
			ealib::exception::StopConditionException);
	}

};

