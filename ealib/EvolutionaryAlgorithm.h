#pragma once
#include "Result.h"
#include "SearchSpace.h"
#include "StopCondition.h"

namespace ealib {

	///Main class for evolationary algorithm
	/**If mutation/crossover operator are set to null in search space, 
	*then there's no mutation/crossover in the algorithm.
	*/
	class EvolutionaryAlgorithm
	{
	public:
		EvolutionaryAlgorithm(const SearchSpace& _search_space, const StopCondition& _stop_condition)
		{
			*stop_condition = _stop_condition;
			*search_space = _search_space;
		}
		~EvolutionaryAlgorithm();
		Result solveCPU();
		Result solveGPU();

	private:
		StopCondition* stop_condition;
		SearchSpace *search_space;
	};
}
