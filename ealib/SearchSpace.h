#pragma once
#include "boost\shared_ptr.hpp"
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
		
		SearchSpace(const FitnessFunction& _fitness_function) :
			fitness_function(_fitness_function)
		{
			population = PopulationPtr(new Population());
			//selection = SelectionPtr(new Selection());
		}
		virtual ~SearchSpace() {};
		void makeStepGPU();
		void makeStepCPU();
		PopulationPtr getPopulation() const { return population; }
		SelectionPtr getSelection() const { return selection; }

	private:
		PopulationPtr population;
		SelectionPtr selection;
		FitnessFunction fitness_function;
	};
}


