#include <ealib\EvolutionaryAlgorithm.h>
#include <ealib\ObjectFactory.h>
#include <vld.h>
#include <vector>

using namespace std;
using namespace ealib;

double myFitnessFunction(const Individual& ind)
{
	return ind.getRepresentation()->at(0);
}

int main()
{
	Population pop;
	pop.setRepresentationSize(1);
		for (int i = 0; i < 100; ++i)
			pop.genIndividual(0, 1);
	NormalMutationOperatorPtr mutation = CPUObjectFactory::getInstance().getNormalMutationOperator(2,2);
	CrossoverOperatorPtr crossover = CPUObjectFactory::getInstance().getCrossoverOperator(0.1);
	SelectionPtr selection = CPUObjectFactory::getInstance().getSelection(Selection::RANKIG);
	StopCondition stop_condition = StopCondition(1000, 4);
	EvolutionaryAlgorithm algorithm = EvolutionaryAlgorithm(pop,
															stop_condition,
															&myFitnessFunction,
															selection,
															mutation);

	Result result = algorithm.run();

}

