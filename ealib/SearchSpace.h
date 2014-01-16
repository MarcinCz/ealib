#pragma once
#include "boost\shared_ptr.hpp"
#include "Individual.h"
#include "Population.h"
#include "MutationOperator.h"
#include "Selection.h"
#include "CrossoverOperator.h"

namespace ealib {

	typedef std::function<double(const Individual&)> FitnessFunction;
	typedef boost::shared_ptr<Individual> IndividualP;
	typedef boost::shared_ptr<Population> PopulationP;
	typedef boost::shared_ptr<MutationOperator> MutationOperatorP;
	typedef boost::shared_ptr<Selection> SelectionP;
	typedef boost::shared_ptr<CrossoverOperator> CrossoverOperatorP;

	///An abstract class for search space.
	/**User should inherit from it and declare his own fitness function.
	*/
	class SearchSpace
	{
	public:
		
		SearchSpace(const FitnessFunction& _fitness_function) :
			fitness_function(_fitness_function)
		{
			population = PopulationP(new Population());
			selection = SelectionP(new Selection());
		}
		virtual ~SearchSpace() {};
		//virtual double calcFitnessVal(const Individual& _individual) const = 0;
		void makeStepGPU();
		void makeStepCPU();
		PopulationP getPopulation() const { return population; }
		MutationOperatorP getMutationOperator() const { return mutation_operator;  }
		SelectionP getSelection() const { return selection; }
		CrossoverOperatorP getCrossoverOperator() const { return crossover_operator; }

	private:
		PopulationP population;
		MutationOperatorP mutation_operator;
		SelectionP selection;
		CrossoverOperatorP crossover_operator;
		FitnessFunction fitness_function;
	};
}


