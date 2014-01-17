#pragma once
#include <random>
#include <vector>
#include "Population.h"

namespace ealib{

	typedef boost::shared_ptr<Population> PopulationP;

	/** Class for mutation operator, provided by user when creating an algorithm.
	*/
	class MutationOperator
	{
	public:
		virtual ~MutationOperator() = 0;
		virtual void doMutationCPU(PopulationP _population);
		virtual void doMutationGPU(PopulationP _population);
	};

	namespace exception {
		class MutationOperatorException :public std::runtime_error
		{
		public:
			MutationOperatorException() :std::runtime_error("Mutation operator exception"){}
			MutationOperatorException(std::string msg) :std::runtime_error(msg.c_str()){}
		};
	}
	
}



