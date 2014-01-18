#include "UniformMutationOperator.h"

using namespace std;

namespace ealib 
{
	namespace eaoperator {

		void UniformMutationOperatorCPU::doMutation(const PopulationPtr& _population)
		{
			vector<IndividualPtr> individuals = _population->getIndividuals();

			int representation_size = _population->getRepresentationSize();
			for(IndividualPtr ind: individuals)
			{
				RepresentationPtr representation = ind->getRepresentation();
			
				for(int i = 0; i < representation_size; ++i)
				{
					if(prob_distribution(generator) <= probability)
						representation->at(i) += distribution(generator);
				}
			}
		}

		void UniformMutationOperatorGPU::doMutation(const PopulationPtr& _population)
		{

		}
	}
	
}

