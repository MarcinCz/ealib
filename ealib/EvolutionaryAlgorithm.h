#pragma once
#include "Result.h"
#include "SearchSpace.h"
#include "StopCondition.h"
#include "NormalMutationOperator.h"
#include "UniformMutationOperator.h"
#include "CrossoverOperator.h"

namespace ealib {

	///Main class for evolationary algorithm
	/**If mutation/crossover operator are set to null in search space, 
	*then there's no mutation/crossover in the algorithm.
	*/
	class EvolutionaryAlgorithm
	{
	public:
		EvolutionaryAlgorithm(const Population& _population, 
							const eaoperator::NormalMutationOperatorPtr& _mutation_operator,
							const eaoperator::CrossoverOperatorPtr& _crossover_operator, 
							const StopCondition& _stop_condition)
		{
			BaseConstructor(_population, _crossover_operator, _stop_condition);
			mutation_operator = boost::dynamic_pointer_cast<eaoperator::MutationOperator>(_mutation_operator);
		}
		EvolutionaryAlgorithm(const Population& _population, 
							const eaoperator::UniformMutationOperatorPtr& _mutation_operator,
							const eaoperator::CrossoverOperatorPtr& _crossover_operator, 
							const StopCondition& _stop_condition)
		{
			BaseConstructor(_population, _crossover_operator, _stop_condition);
			mutation_operator = boost::dynamic_pointer_cast<eaoperator::MutationOperator>(_mutation_operator);
		}
		~EvolutionaryAlgorithm();
		Result run();

	private:
		void BaseConstructor(const Population& _population, const eaoperator::CrossoverOperatorPtr& _crossover_operator, const StopCondition& _stop_condition)
		{
			*stop_condition = _stop_condition;
			*population = _population;
			crossover_operator = _crossover_operator;
		}

		StopCondition* stop_condition;
		Population* population;
		eaoperator::MutationOperatorPtr mutation_operator;
		eaoperator::CrossoverOperatorPtr crossover_operator;
	};
}
