#pragma once
#include <random>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Population.h"

namespace ealib{

	namespace exception {
		
		///A class for mutation type exception.
		class MutationOperatorException :public std::runtime_error
		{
		public:
			MutationOperatorException() :std::runtime_error("Mutation operator exception"){}
			MutationOperatorException(std::string msg) :std::runtime_error(msg.c_str()){}
		};
	}

	namespace eaoperator {
	
		///An abstract class for mutation operator, provided by user when creating an algorithm.
		class MutationOperator
		{
		public:
			virtual ~MutationOperator() {};

			/**
			* Starts population mutation.
			* @param _population Population to be mutated.
			*/
			virtual void doMutation(Population& _population) = 0;

			/**
			* Sets mutation probability.
			* @throw ealib::exception::MutationOperatorException If new probability isn't between or equal to 0 and 100.
			*/
			void setProbability(double _probability)
			{
				if(_probability < 0 || _probability > 100)
					throw exception::MutationOperatorException("Probability must be between or equal to 0 and 100.");

				probability = _probability;
			}
			double getProbability() { return probability; }

		protected:
			double probability;
		};

		///An abstract class for CPU-based mutation operator, provided by user when creating an algorithm.
		class MutationOperatorCPU: virtual public MutationOperator
		{
		public:
			virtual ~MutationOperatorCPU() {};

			/**
			* Starts population mutation.
			* @param _population Population to be mutated.
			*/
			virtual void doMutation(Population& _population) = 0;
		};

		///An abstract class for GPU-based mutation operator, provided by user when creating an algorithm.
		class MutationOperatorGPU: virtual public MutationOperator
		{
		public:
			virtual ~MutationOperatorGPU() {};

			/**
			* Starts population mutation.
			* @param _population Population to be mutated.
			*/
			virtual void doMutation(Population& _population) = 0;
		};

		typedef boost::shared_ptr<MutationOperator> MutationOperatorPtr;
	}
}



