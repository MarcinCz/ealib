#include <SearchSpace.h>
#include <Population.h>
#include <Individual.h>
#include <cppunit\TestCase.h>
#include <vector>

using namespace CppUnit;
using namespace ealib;
using namespace std;

double myFitnessFunction(const ealib::Individual& ind)
{
	return ind.getRepresentation().at(0);
}


class PopulationTest : TestCase
{
	PopulationTest(string name) : TestCase(name){}

	void runTest()
	{
		SearchSpace sp(*myFitnessFunction);
		vector<double> representation1;
		for (int i = 1; i < 10; i++)
		{
			representation1.push_back(i);
		}
		sp.getPopulation()->addIndividual(representation1);
		sp.getPopulation()->genIndividual(0, 10);
		sp.getPopulation()->genIndividual(4.5, 15.5);

	}
};
	
