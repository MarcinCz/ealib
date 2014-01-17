#pragma once
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Individual.h"
#include "Population.h"
//#include "SearchSpace.h"

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
		}
		Selection(SelectionType _selection_type, double _selection_ratio)
		{
			selection_type = _selection_type;
		}
		~Selection();
		std::vector<IndividualP> doSelectionCPU(const PopulationP _population, const FitnessFunction& _fitness_function, int _number_to_select);
		std::vector<IndividualP> doSelectionGPU(const PopulationP _population, const FitnessFunction& _fitness_function, int _number_to_select);
		void setSelectionType(SelectionType _selection_type) { selection_type = _selection_type; }

	private: 
		SelectionType selection_type;
//		SearchSpace* sp;
	};
}


