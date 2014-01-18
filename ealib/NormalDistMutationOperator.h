#pragma once
#include <random>
#include <boost/shared_ptr.hpp>
#include "MutationOperator.h"

namespace ealib
{

	class NormalDistMutationOperator :
	public MutationOperator
	{
	public:
		NormalDistMutationOperator(double _standard_deviation, double _probability):
			standard_deviation(_standard_deviation)
		{
			if(_probability < 0 || _probability > 100)
				throw exception::MutationOperatorException("Probability must be between or equal to 0 and 100.");

			probability = _probability;
			distribution = std::normal_distribution<double>(0.0, _standard_deviation);
			prob_distribution = std::uniform_real_distribution<double>(0,100);
		}
		~NormalDistMutationOperator() {}
		void doMutationCPU(PopulationPtr& _population);
		void doMutationGPU(PopulationPtr& _population);
		void setStandardDeviation(double _standard_deviation) { standard_deviation =_standard_deviation; }
		double getStandardDeviation() { return standard_deviation; }
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
		std::normal_distribution<double> distribution;
		double probability;
		double standard_deviation;
	};

}


