#pragma once
#include <random>
#include "mutationoperator.h"

namespace ealib
{
	namespace eaoperator {

		///An abstract class for uniform distribution mutation operator.
		class UniformMutationOperator:
			virtual public MutationOperator
		{
		public:
			/**
			* UniformMutationOperator constructor.
			* @param _standard_deviation Standard deviation for mutation.
			* @param _probability Mutation probability.
			*/
			UniformMutationOperator(double _range, double _probability):
				range(_range)
			{
				setProbability(_probability);
				distribution = std::uniform_real_distribution<double>(-range, range);
				prob_distribution = std::uniform_real_distribution<double>(0,100);
			}
			~UniformMutationOperator() {}

			/**
			* Starts population mutation.
			* @param _population Population to be mutated.
			*/
			virtual void doMutation(Population& _population) = 0;
			void setRange(double _range) { range = _range; }
			double getRange() { return range; }

		protected:
			std::default_random_engine generator;
			std::uniform_real_distribution<double> prob_distribution;
			std::uniform_real_distribution<double> distribution;
			double range;
		};

		///A class for CPU-based uniform distribution mutation operator.
		class UniformMutationOperatorCPU:
			public UniformMutationOperator, public MutationOperatorCPU
		{
		public:
			/**
			* UniformMutationOperatorCPU constructor.
			* @param _standard_deviation Standard deviation for mutation.
			* @param _probability Mutation probability.
			*/
			UniformMutationOperatorCPU(double _range, double _probability):
				UniformMutationOperator(_range, _probability) {};
			~UniformMutationOperatorCPU() {};

			/**
			* Starts population mutation.
			* @param _population Population to be mutated.
			*/
			void doMutation(Population& _population);
		};

		///A class for GPU-based uniform distribution mutation operator.
		class UniformMutationOperatorGPU:
			public UniformMutationOperator, public MutationOperatorGPU
		{
		public:
			/**
			* UniformMutationOperatorGPU constructor.
			* @param _standard_deviation Standard deviation for mutation.
			* @param _probability Mutation probability.
			*/
			UniformMutationOperatorGPU(double _range, double _probability):
				UniformMutationOperator(_range, _probability) {};
			~UniformMutationOperatorGPU() {};

			/**
			* Starts population mutation.
			* @param _population Population to be mutated.
			*/
			void doMutation(Population& _population);
		};

		typedef boost::shared_ptr<UniformMutationOperator> UniformMutationOperatorPtr;
	}
}



