#include "EvolutionaryAlgorithm.h"
#include <ctime>

namespace ealib {

	Result EvolutionaryAlgorithm::run()
	{
		
		int steps_run = 0;
		int population_size = population->getPopulationSize();
		IndividualPtr ind;

		clock_t begin = clock();
		for( ; ; ++steps_run)
		{
			if(stop_condition->isMaxStepsSet() && steps_run == stop_condition->getMaxSteps())
			{
				ind = population->getBestIndividual();
				break;
			}

			selection->doSelection(*population, fitness_function, population_size);
			if(stop_condition->isMinFitnessValueSet() 
				&& population->getBestIndividual()->getFitnessValue() >= stop_condition->getMinFitnessValue())
			{
				ind = population->getBestIndividual();
				break;
			}

			if(crossover_operator_set)
				crossover_operator->doCrossover(*population);
			mutation_operator->doMutation(*population);


		}
		clock_t end = clock();
		double running_time = static_cast<double>(end-begin)/CLOCKS_PER_SEC;

		Result result = Result(steps_run, running_time, *ind);
		return result;
	}
}

