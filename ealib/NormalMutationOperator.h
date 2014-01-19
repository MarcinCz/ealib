#pragma once
#include <random>
#include <boost/shared_ptr.hpp>
#include "MutationOperator.h"

namespace ealib
{
	namespace eaoperator {

		///An abstract class for normal mutation operator.
		class NormalMutationOperator:
			virtual public MutationOperator
		{
		public:
			/**
			* NormalMutationOperator constructor.
			* @param _standard_deviation Standard deviation for mutation.
			* @param _probability Mutation probability.
			*/
			NormalMutationOperator(double _standard_deviation, double _probability):
				standard_deviation(_standard_deviation)
			{
				setProbability(_probability);
				distribution = std::normal_distribution<double>(0.0, _standard_deviation);
				prob_distribution = std::uniform_real_distribution<double>(0,100);
			};
			~NormalMutationOperator() {};

			/**
			* Starts population mutation.
			* @param _population Population to be mutated.
			*/
			virtual void doMutation(Population& _population) = 0;
			void setStandardDeviation(double _standard_deviation) { standard_deviation =_standard_deviation; }
			double getStandardDeviation() { return standard_deviation; }

		protected:
			std::default_random_engine generator;
			std::uniform_real_distribution<double> prob_distribution;
			std::normal_distribution<double> distribution;
			double standard_deviation;
		};

		///A class for CPU-based normal distribution mutation operator.
		class NormalMutationOperatorCPU:
			public NormalMutationOperator, public MutationOperatorCPU
		{
		public:
			/**
			* NormalMutationOperator constructor.
			* @param _standard_deviation Standard deviation for mutation.
			* @param _probability Mutation probability.
			*/
			NormalMutationOperatorCPU(double _standard_deviation, double _probability):
				NormalMutationOperator(_standard_deviation, _probability) {};
			~NormalMutationOperatorCPU() {};

			/**
			* Starts population mutation.
			* @param _population Population to be mutated.
			*/
			void doMutation(Population& _population);
		};

		///A class for GPU-based normal distribution mutation operator.
		class NormalMutationOperatorGPU:
			public NormalMutationOperator, public MutationOperatorGPU
		{
		public:
			/**
			* NormalMutationOperator constructor.
			* @param _standard_deviation Standard deviation for mutation.
			* @param _probability Mutation probability.
			*/
			NormalMutationOperatorGPU(double _standard_deviation, double _probability):
				NormalMutationOperator(_standard_deviation, _probability) {};
			~NormalMutationOperatorGPU() {};

			/**
			* Starts population mutation.
			* @param _population Population to be mutated.
			*/
			void doMutation(Population& _population);
		};

		typedef boost::shared_ptr<NormalMutationOperator> NormalMutationOperatorPtr;
	}
}


