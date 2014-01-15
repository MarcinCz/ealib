#pragma once
#include "Individual.h"
#include "Population.h"
#include "MutationOperator.h"
#include "Selection.h"
#include "CrossoverOperator.h"

namespace ealib {

	///An abstract class for search space.
	/**User should inherit from it and declare his own fitness function.
	*/
	class SearchSpace
	{
	public:
		virtual ~SearchSpace() = 0;
		virtual double calcFitnessVal(const Individual& _individual) const = 0;

	private:
		Population population;
		MutationOperator mutation_operator;
		Selection selection;
		CrossoverOperator crossover_operator;
	};
}


