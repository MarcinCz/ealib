#pragma once
#include <random>
#include "mutationoperator.h"

namespace ealib
{
	namespace eaoperator {

		class UniformMutationOperator:
			virtual public MutationOperator
		{
		public:
			UniformMutationOperator(double _range, double _probability):
				range(_range)
			{
				if(_probability < 0 || _probability > 100)
					throw exception::MutationOperatorException("Probability must be between or equal to 0 and 100.");

				probability = _probability;
				distribution = std::uniform_real_distribution<double>(-range, range);
				prob_distribution = std::uniform_real_distribution<double>(0,100);
			}
			~UniformMutationOperator() {}
			virtual void doMutation(const PopulationPtr& _population) = 0;
			void setRange(double _range) { range = _range; }
			double getRange() { return range; }
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
			std::uniform_real_distribution<double> distribution;
			double range;
			double probability;
		};

		class UniformMutationOperatorCPU:
			public UniformMutationOperator, public MutationOperatorCPU
		{
		public:
			UniformMutationOperatorCPU(double _range, double _probability):
				UniformMutationOperator(_range, _probability) {};
			~UniformMutationOperatorCPU() {};
			void doMutation(const PopulationPtr& _population);
		};


		class UniformMutationOperatorGPU:
			public UniformMutationOperator, public MutationOperatorGPU
		{
		public:
			UniformMutationOperatorGPU(double _range, double _probability):
				UniformMutationOperator(_range, _probability) {};
			~UniformMutationOperatorGPU() {};
			void doMutation(const PopulationPtr& _population);
		};

		typedef boost::shared_ptr<UniformMutationOperator> UniformMutationOperatorPtr;
	}
}



