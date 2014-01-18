#pragma once
#include <boost/shared_ptr.hpp>
#include <random>
#include <time.h>
#include "Population.h"


namespace ealib {

	/** Class for crossover operator, provided by user when creating an algorithm
	*/
	class CrossoverOperator
	{
	public:
		CrossoverOperator(int _population_ratio): population_ratio(_population_ratio)
		{
			generator.seed(time(NULL));
		}
		~CrossoverOperator() {};
		void doCrossoverCPU(PopulationPtr& _population);
		void doCrossoverGPU(PopulationPtr& _population);
		void setPopulationRatio(const int _population_ratio) { population_ratio = _population_ratio; }
		int getPopulationRatio() const { return population_ratio; }

	private:
		int population_ratio;
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution;
	};

	typedef boost::shared_ptr<CrossoverOperator> CrossoverOperatorPtr;
}


