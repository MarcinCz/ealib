#pragma once
#include "boost\shared_ptr.hpp"
#include "Individual.h"
#include "Population.h"
#include "MutationOperator.h"
#include "Selection.h"
#include "CrossoverOperator.h"

namespace ealib {

	typedef std::function<double(const Individual&)> FitnessFunction;

	///An abstract class for search space.
	/**User should inherit from it and declare his own fitness function.
	*/
	class SearchSpace
	{
	public:
		
		SearchSpace(const FitnessFunction& _fitness_function) :
			fitness_function(_fitness_function)
		{
		}
		virtual ~SearchSpace() {};
		//virtual double calcFitnessVal(const Individual& _individual) const = 0;
		void makeStepGPU();
		void makeStepCPU();
		Population getPopulation() const { return population; }
		MutationOperator getMutationOperator() const { return mutation_operator;  }
		Selection getSelection() const { return selection; }
		CrossoverOperator getCrossoverOperator() const { return crossover_operator; }

	private:
		Population population;
		MutationOperator mutation_operator;
		Selection selection;
		CrossoverOperator crossover_operator;
		FitnessFunction fitness_function;
	};
}


