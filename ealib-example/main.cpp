#include <EvolutionaryAlgorithm.h>
#include <SearchSpace.h>
#include <Individual.h>
#include <vector>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace ealib;

double myFitnessFunction(const ealib::Individual& ind)
{
	return ind.getRepresentation().at(0);
}

int main()
{
	
	SearchSpace my_sp(*myFitnessFunction);
	vector<double> representation1;
	vector<double> representation2;
	vector<double> representation3;
	vector<double> representation4;
	for (int i = 1; i < 10; i++)
	{
		representation1.push_back(i);
		representation2.push_back(3*i);
		representation3.push_back(2*i);
		representation4.push_back(4*i);
	}
	my_sp.getPopulation()->addIndividual(representation1);
	my_sp.getPopulation()->addIndividual(representation2);
	my_sp.getPopulation()->addIndividual(representation3);
	my_sp.getPopulation()->addIndividual(representation4);
	vector<IndividualP> population_old = my_sp.getPopulation()->getIndividuals();
	vector<IndividualP> population_new_ranking = my_sp.getSelection()->doSelectionCPU(*(my_sp.getPopulation()), *myFitnessFunction, 6);
	my_sp.getSelection()->setSelectionType(Selection::SelectionType::PROPORTIONAL);
	vector<IndividualP> population_new_proportional = my_sp.getSelection()->doSelectionCPU(*(my_sp.getPopulation()), *myFitnessFunction, 7);
	return 0;
	//ealib::StopCondition sc = ealib::StopCondition(10, 5.0);
	//ealib::EvolutionaryAlgorithm(my_sp, sc);
}

