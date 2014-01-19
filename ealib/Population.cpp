#include "Population.h"
#include <boost/bind/bind.hpp>
#include <stdlib.h> 

namespace ealib {

	using namespace std;
	using namespace exception;

	IndividualPtr Population::getBestIndividual()
	{
		vector<IndividualPtr>::iterator iterator = max_element(individuals.begin(), individuals.end(),
			[](const IndividualPtr ind1, const IndividualPtr ind2)
			{
				return ind1->getFitnessValue() < ind2->getFitnessValue();
			});
		return *iterator;
	}

	void Population::genIndividual(double _min, double _max, int _number)
	{
		double range = _max - _min;

		for (int j = 0; j < _number; ++j)
		{
			vector<double> representation;
			for (int i = 0; i < representation_size; ++i)
			{
				uniform_real_distribution<double> distribution = uniform_real_distribution<double>(_min, _max);
				double random_number = distribution(generator);
				representation.push_back(random_number);
			}
			individuals.push_back(IndividualPtr(new Individual(representation)));
		}	
	}

	void Population::setRepresentationSize(int _representation_size)
	{
		if (_representation_size < 1)
			throw PopulationException("Representation size must be positive.");
		if (getRepresentationSize() == _representation_size)
			return;	
		if (getPopulationSize() != 0)
			throw PopulationException("Population need to be empty before representation size change.");
		representation_size = _representation_size;
	}

	void Population::addIndividual(vector<double> _representation)
	{
		if (getRepresentationSize() != _representation.size())
			throw PopulationException("Wrong representation size. Current size set is " + getRepresentationSize());
		individuals.push_back(IndividualPtr(new Individual(_representation)));
	}

}

