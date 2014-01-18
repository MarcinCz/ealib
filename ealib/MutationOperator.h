#pragma once
#include <random>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Population.h"

namespace ealib{

	//typedef boost::shared_ptr<Population> PopulationPtr;

	/** Class for mutation operator, provided by user when creating an algorithm.
	*/
	class MutationOperator
	{
	public:
		virtual ~MutationOperator() {};
		virtual void doMutationCPU(PopulationPtr& _population) = 0;
		virtual void doMutationGPU(PopulationPtr& _population) = 0;
	};

	namespace exception {
		class MutationOperatorException :public std::runtime_error
		{
		public:
			MutationOperatorException() :std::runtime_error("Mutation operator exception"){}
			MutationOperatorException(std::string msg) :std::runtime_error(msg.c_str()){}
		};
	}
	
	typedef boost::shared_ptr<MutationOperator> MutationOperatorPtr;
}



