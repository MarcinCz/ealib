#include <ealib/EvolutionaryAlgorithm.h>
#include <ealib/ObjectFactory.h>
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
	pop.genIndividual(0, 1, 100);
	NormalMutationOperatorPtr mutation = CPUObjectFactory::getInstance().getNormalMutationOperator(2,4);
	CrossoverOperatorPtr crossover = CPUObjectFactory::getInstance().getCrossoverOperator(0.1);
	SelectionPtr selection = CPUObjectFactory::getInstance().getSelection(Selection::RANKIG);
	StopCondition stop_condition = StopCondition(1000, 8);
	EvolutionaryAlgorithm algorithm = EvolutionaryAlgorithm(pop,
															stop_condition,
															&myFitnessFunction,
															selection,
															mutation);

	Result result = algorithm.run();
	
	cout.precision(15);
	cout<<"Steps: "<<result.getStepsTaken()<<endl;
	cout<<"Best result: "<<result.getBestIndividual().getFitnessValue()<<endl;
	cout<<"Running time: "<<result.getRunningTime()<<endl;
	cin.get();
}

