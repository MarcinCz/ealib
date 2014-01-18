#include "NormalDistMutationOperator.h"

using namespace std;

namespace ealib
{
	
	void NormalDistMutationOperator::doMutationCPU(PopulationPtr& _population)
	{
		vector<IndividualPtr> individuals = _population->getIndividuals();

		for(IndividualPtr ind: individuals)
		{
			RepresentationPtr representation = ind->getRepresentation();
			
			for(int i = 0; i < representation->size(); ++i)
			{
				if(prob_distribution(generator) <= probability)
					representation->at(i) += distribution(generator);
			}
		}
	}

	void NormalDistMutationOperator::doMutationGPU(PopulationPtr& _population)
	{

	}
}
