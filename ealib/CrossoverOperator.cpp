#include "CrossoverOperator.h"

using namespace std;

namespace ealib { 

	void CrossoverOperator::doCrossoverCPU(PopulationPtr& _population)
	{
		int pairs_to_create = ceil(_population->getPopulationSize() * population_ratio);
		distribution = uniform_int_distribution<int>(0, _population->getPopulationSize());

		for(int i = 0; i < pairs_to_create; ++i);
		{
			int first_index = distribution(generator);
			int second_index;
			for(;;)
			{
				second_index = distribution(generator);
				if(second_index != first_index) break;
			}

			RepresentationPtr first_representation = _population->getIndividuals().at(first_index)->getRepresentation();
			RepresentationPtr second_representation = _population->getIndividuals().at(second_index)->getRepresentation();
			vector<double> representation = vector<double>();
			
			for(int j = 0; j < _population->getRepresentationSize(); ++j)
			{
				representation.push_back(
					(first_representation->at(j) + second_representation->at(j))/2);
			}

			_population->addIndividual(representation);
		}
	}

	void CrossoverOperator::doCrossoverGPU(PopulationPtr& _population)
	{

	}
}

