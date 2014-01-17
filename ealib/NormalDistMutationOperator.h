#pragma once
#include <random>
#include "mutationoperator.h"

namespace ealib
{
	typedef boost::shared_ptr<Population> PopulationP;

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
		void doMutationCPU(PopulationP& _population);
		void doMutationGPU(PopulationP& _population);
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


