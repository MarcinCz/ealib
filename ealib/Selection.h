#pragma once
#include <vector>
#include "Individual.h"
#include "Population.h"

namespace ealib {

	///A class for selection of new population
	/**User can set selection type and selection ratio (amount of selected individuals compared to population size).
	*/
	class Selection
	{
	public:
		enum SelectionType { RANNKIG, PROPORTIONAL };

		Selection(SelectionType _selection_type, double _selection_ratio)
		{
			selection_type = _selection_type;
			selection_ratio = _selection_ratio;
		}
		~Selection();
		std::vector<Individual> doSelectionCPU(const Population& _population);
		std::vector<Individual> doSelectionGPU(const Population& _population);
		void setSelectionType(SelectionType _selection_type) { selection_type = _selection_type; }

	private: 
		SelectionType selection_type;
		double selection_ratio;
	};
}


