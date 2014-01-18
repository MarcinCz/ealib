#pragma once
#include <random>
#include <boost/shared_ptr.hpp>
#include "MutationOperator.h"

namespace ealib
{
	namespace eaoperator {

		class NormalMutationOperator
		{
		public:
			NormalMutationOperator(double _standard_deviation, double _probability):
				standard_deviation(_standard_deviation)
			{
				if(_probability < 0 || _probability > 100)
					throw exception::MutationOperatorException("Probability must be between or equal to 0 and 100.");

				probability = _probability;
				distribution = std::normal_distribution<double>(0.0, _standard_deviation);
				prob_distribution = std::uniform_real_distribution<double>(0,100);
			};
			~NormalMutationOperator() {};
			void setStandardDeviation(double _standard_deviation) { standard_deviation =_standard_deviation; }
			double getStandardDeviation() { return standard_deviation; }
			void setProbability(double _probability)
			{
				if(_probability < 0 || _probability > 100)
					throw exception::MutationOperatorException("Probability must be between or equal to 0 and 100.");

				probability = _probability;
			}
			double getProbability() { return probability; }
		protected:
			std::default_random_engine generator;
			std::uniform_real_distribution<double> prob_distribution;
			std::normal_distribution<double> distribution;
			double probability;
			double standard_deviation;
		};

		class NormalMutationOperatorCPU:
			public NormalMutationOperator, MutationOperatorCPU
		{
		public:
			NormalMutationOperatorCPU(double _standard_deviation, double _probability):
				NormalMutationOperator(_standard_deviation, _probability) {};
			~NormalMutationOperatorCPU() {};
			void doMutation(PopulationPtr& _population);
		};

		class NormalMutationOperatorGPU:
			public NormalMutationOperator, MutationOperatorGPU
		{
		public:
			NormalMutationOperatorGPU(double _standard_deviation, double _probability):
				NormalMutationOperator(_standard_deviation, _probability) {};
			~NormalMutationOperatorGPU() {};
			void doMutation(PopulationPtr& _population);
		};
	}
}


