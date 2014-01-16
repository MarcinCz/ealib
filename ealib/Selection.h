#pragma once
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Individual.h"
#include "Population.h"
//#include "SearchSpace.h"

namespace ealib {

	typedef boost::shared_ptr<Individual> IndividualP;
	typedef std::function<double(const Individual&)> FitnessFunction;

	///A class for selection of new population
	/**User can set selection type and selection ratio (amount of selected individuals compared to population size).
	*Default selection type is ranking, default ratio is 0.2. */
	class Selection
	{
	public:
		enum SelectionType { RANNKIG, PROPORTIONAL };
		Selection()
		{
			selection_type = SelectionType::RANNKIG;
			selection_ratio = 0.2;
		}
		Selection(SelectionType _selection_type, double _selection_ratio)
		{
			selection_type = _selection_type;
			selection_ratio = _selection_ratio;
		}
		~Selection();
		std::vector<IndividualP> doSelectionCPU(const Population& _population, const FitnessFunction& _fitness_function);
		std::vector<IndividualP> doSelectionGPU(const Population& _population, const FitnessFunction& _fitness_function);
		void setSelectionType(SelectionType _selection_type) { selection_type = _selection_type; }

	private: 
		SelectionType selection_type;
//		SearchSpace* sp;
		double selection_ratio;
	};
}


