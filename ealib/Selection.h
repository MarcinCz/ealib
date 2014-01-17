#pragma once
#include <vector>
#include <random>
#include <time.h>   
#include <boost/shared_ptr.hpp>
#include "Individual.h"
#include "Population.h"

namespace ealib {

	typedef boost::shared_ptr<Individual> IndividualP;
	typedef boost::shared_ptr<Population> PopulationP;
	typedef std::function<double(const Individual&)> FitnessFunction;

	///A class for selection of new population
	/**User can set selection type.
	*Default selection type is ranking.*/
	class Selection
	{
	public:
		enum SelectionType { RANNKIG, PROPORTIONAL };
		Selection()
		{
			selection_type = SelectionType::RANNKIG;
			generator.seed(static_cast<unsigned long>(time(NULL)));
		}
		Selection(SelectionType _selection_type)
		{
			selection_type = _selection_type;
			generator.seed(static_cast<unsigned long>(time(NULL)));
		}
		~Selection();
		std::vector<IndividualP> doSelectionCPU(const PopulationP _population, const FitnessFunction& _fitness_function, int _number_to_select);
		std::vector<IndividualP> doSelectionGPU(const PopulationP _population, const FitnessFunction& _fitness_function, int _number_to_select);
		void setSelectionType(SelectionType _selection_type) { selection_type = _selection_type; }

	private: 
		std::vector<IndividualP> doSelectionRankingCPU(const PopulationP _population, int _number_to_select);
		std::vector<IndividualP> doSelectionProportionalCPU(const PopulationP _population, int _number_to_select);

		SelectionType selection_type;
		std::default_random_engine generator;
	};
}


