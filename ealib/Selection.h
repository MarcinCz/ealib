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
		enum SelectionType { RANKIG, PROPORTIONAL };

		Selection(SelectionType _selection_type)
		{
			selection_type = _selection_type;
			generator.seed(static_cast<unsigned long>(time(NULL)));
		}
		~Selection() {}
		virtual void doSelection(Population& _population, const FitnessFunction& _fitness_function, int _number_to_select) = 0;
		void setSelectionType(SelectionType _selection_type) { selection_type = _selection_type; }

	protected: 
		SelectionType selection_type;
		std::default_random_engine generator;
	};

	class SelectionCPU
		:public Selection
	{
	public:
		SelectionCPU(SelectionType _selection_type):
			Selection(_selection_type) {};
		~SelectionCPU() {};
		void doSelection(Population& _population, const FitnessFunction& _fitness_function, int _number_to_select);

	private:
		void doSelectionRanking(Population& _population, int _number_to_select);
		void doSelectionProportional(Population& _population, int _number_to_select);

	};
	
	class SelectionGPU
		:public Selection
	{
	public:
		SelectionGPU(SelectionType _selection_type):
			Selection(_selection_type) {};
		~SelectionGPU() {};
		void doSelection(Population& _population, const FitnessFunction& _fitness_function, int _number_to_select);

	private:
		void doSelectionRanking(Population& _population, int _number_to_select);
		void doSelectionProportional(Population& _population, int _number_to_select);
	};
	typedef boost::shared_ptr<Selection> SelectionPtr;
}


