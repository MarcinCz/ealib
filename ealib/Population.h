#pragma once
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Individual.h"

namespace ealib{

	typedef boost::shared_ptr<Individual> IndividualP;
	///A class for individuals population
	class Population
	{
	public:
		Population()
		{
			individuals = std::vector<IndividualP>();
		}
		~Population();
		void addIndividual(const std::vector<double> _representation)
		{ 
			individuals.push_back(IndividualP(new Individual(_representation)));
		}
		std::vector<IndividualP> getIndividuals() const { return individuals; }
		IndividualP getBestIndividual();
		double getFitnessValueSum(); ///Returns sum of fitness values of every individual.
		int getPopulationSize() const { return individuals.size(); }
	private: 
		std::vector<IndividualP> individuals;
	};
}