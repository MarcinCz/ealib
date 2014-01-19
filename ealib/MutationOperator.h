#pragma once
#include <random>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Population.h"

namespace ealib{

	namespace eaoperator {

		//typedef boost::shared_ptr<Population> PopulationPtr;

		/** Class for mutation operator, provided by user when creating an algorithm.
		*/
		class MutationOperator
		{
		public:
			virtual ~MutationOperator() {};
			virtual void doMutation(const PopulationPtr& _population) = 0;
		};


		class MutationOperatorCPU: virtual public MutationOperator
		{
		public:
			virtual ~MutationOperatorCPU() {};
			virtual void doMutation(const PopulationPtr& _population) = 0;
		};

		class MutationOperatorGPU: virtual public MutationOperator
		{
		public:
			virtual ~MutationOperatorGPU() {};
			virtual void doMutation(const PopulationPtr& _population) = 0;
		};

		typedef boost::shared_ptr<MutationOperator> MutationOperatorPtr;
	}
	
	namespace exception {
		class MutationOperatorException :public std::runtime_error
		{
		public:
			MutationOperatorException() :std::runtime_error("Mutation operator exception"){}
			MutationOperatorException(std::string msg) :std::runtime_error(msg.c_str()){}
		};
	}
	
	
}



