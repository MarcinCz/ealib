#pragma once
#include "Result.h"
#include "StopCondition.h"
#include "NormalMutationOperator.h"
#include "UniformMutationOperator.h"
#include "CrossoverOperator.h"
#include "Selection.h"

namespace ealib {

	typedef std::function<double(const Individual&)> FitnessFunction;

	///Main class for evolationary algorithm
	/**If mutation/crossover operator are set to null in search space, 
	*then there's no mutation/crossover in the algorithm.
	*/
	class EvolutionaryAlgorithm
	{
	public:
		EvolutionaryAlgorithm(Population& _population, 
							StopCondition& _stop_condition,
							const FitnessFunction& _fitness_function,
							const SelectionPtr& _selection,
							const eaoperator::NormalMutationOperatorPtr& _mutation_operator,
							const eaoperator::CrossoverOperatorPtr& _crossover_operator = NULL)
		{
			BaseConstructor(_population, _fitness_function, _selection, _crossover_operator, _stop_condition);
			mutation_operator = boost::dynamic_pointer_cast<eaoperator::MutationOperator>(_mutation_operator);
		}

		EvolutionaryAlgorithm(Population& _population, 
							StopCondition& _stop_condition,
							const FitnessFunction& _fitness_function,
							const SelectionPtr& _selection,
							const eaoperator::UniformMutationOperatorPtr& _mutation_operator,
							const eaoperator::CrossoverOperatorPtr& _crossover_operator = NULL)
		{
			BaseConstructor(_population, _fitness_function, _selection, _crossover_operator, _stop_condition);
			mutation_operator = boost::dynamic_pointer_cast<eaoperator::MutationOperator>(_mutation_operator);
		}
		~EvolutionaryAlgorithm() {};
		Result run();

	private:
		void BaseConstructor(Population& _population, 
							const FitnessFunction& _fitness_function, 
							const SelectionPtr& _selection, 
							const eaoperator::CrossoverOperatorPtr& _crossover_operator, 
							StopCondition& _stop_condition)
		{
			stop_condition = &_stop_condition;
			population = &_population;
			fitness_function = _fitness_function;
			selection = _selection;
			if(crossover_operator)
			{
				crossover_operator = _crossover_operator;
				crossover_operator_set = true;
			}
			else
			{
				crossover_operator_set = false;
			}
			
		}
		bool crossover_operator_set;
		FitnessFunction fitness_function;
		StopCondition* stop_condition;
		Population* population;
		SelectionPtr selection;
		eaoperator::MutationOperatorPtr mutation_operator;
		eaoperator::CrossoverOperatorPtr crossover_operator;
	};
}
