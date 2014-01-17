#include "NormalDistMutationOperator.h"

using namespace std;

namespace ealib
{
	
	void NormalDistMutationOperator::doMutationCPU(PopulationP& _population)
	{
		vector<IndividualPtr> individuals = _population->getIndividuals();

		for(IndividualPtr ind: individuals)
		{
			RepresentationPtr representation = ind->getRepresentation();
		}
	}

}
