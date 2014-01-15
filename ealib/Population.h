#pragma once
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Individual.h"

namespace ealib{

	///A class for individuals population
	class Population
	{
	public:
		Population();
		~Population();
		void addIndividual(const std::vector<double> _representation) { individuals.push_back(Individual(_representation)); }
		std::vector<Individual> getIndividuals() const { return individuals; }
		Individual getBestIndividual();
		int getPopulationSize() const { return individuals.size(); }
	private: 
		std::vector<Individual> individuals;
	};
}