#pragma once
#include <random>
#include "mutationoperator.h"

namespace ealib
{

	class UniformDistMutationOperator :
	public MutationOperator
	{
	public:
		UniformDistMutationOperator(double _range, double _probability):
			range(_range)
		{
			if(_probability < 0 || _probability > 100)
				throw exception::MutationOperatorException("Probability must be between or equal to 0 and 100.");

			probability = _probability;
			distribution = std::uniform_real_distribution<double>(-range, range);
			prob_distribution = std::uniform_real_distribution<double>(0,100);
		}
		~UniformDistMutationOperator() {}
		void doMutationCPU(PopulationPtr& _population);
		void doMutationGPU(PopulationPtr& _population);
		void setRange(double _range) { range = _range; }
		double getRange() { return range; }
		void setProbability(double _probability)
		{
			if(_probability < 0 || _probability > 100)
				throw exception::MutationOperatorException("Probability must be between or equal to 0 and 100.");

			probability = _probability;
		}
		double getProbability() { return probability; }

	private:
		std::default_random_engine generator;
		std::uniform_real_distribution<double> prob_distribution;
		std::uniform_real_distribution<double> distribution;
		double range;
		double probability;
	};
}



