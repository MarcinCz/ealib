#pragma once
#include <vector>
#include <random>
#include <time.h>   
#include <boost/shared_ptr.hpp>
#include "Individual.h"
#include "Population.h"

namespace ealib {

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
		std::vector<IndividualPtr> doSelectionCPU(const PopulationPtr& _population, const FitnessFunction& _fitness_function, int _number_to_select);
		std::vector<IndividualPtr> doSelectionGPU(const PopulationPtr& _population, const FitnessFunction& _fitness_function, int _number_to_select);
		void setSelectionType(SelectionType _selection_type) { selection_type = _selection_type; }

	private: 
		std::vector<IndividualPtr> doSelectionRankingCPU(const PopulationPtr& _population, int _number_to_select);
		std::vector<IndividualPtr> doSelectionProportionalCPU(const PopulationPtr& _population, int _number_to_select);

		SelectionType selection_type;
		std::default_random_engine generator;
	};
}


