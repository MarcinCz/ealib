#include "Population.h"
#include <boost/bind/bind.hpp>

namespace ealib {

	using namespace std;


	Population::~Population()
	{
	}

	IndividualP Population::getBestIndividual()
	{
		vector<IndividualP>::iterator iterator = max_element(individuals.begin(), individuals.end(),
			[](const IndividualP ind1, const IndividualP ind2)
			{
				return ind1->getFitnessValue() < ind2->getFitnessValue();
			});
		return *iterator;
	}
}

