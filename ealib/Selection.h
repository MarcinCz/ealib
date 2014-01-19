#pragma once
#include <vector>
#include <random>
#include <time.h>   
#include <boost/shared_ptr.hpp>
#include "Individual.h"
#include "Population.h"

namespace ealib {

	///\typedef Typedef for fitness function.
	typedef std::function<double(const Individual&)> FitnessFunction;

	///An abstract class for selection of new population.
	class Selection
	{
	public:
		/**
		* Selection type enum.
		*/
		enum SelectionType { RANKIG, PROPORTIONAL };

		/**
		* Selection constructor.
		* @param _selection_type Selection type.
		*/
		Selection(SelectionType _selection_type)
		{
			selection_type = _selection_type;
			generator.seed(static_cast<unsigned long>(time(NULL)));
		}
		~Selection() {}

		/**
		* Starts population selection, new population replaces old one.
		* @param _population Population.
		* @param _fitness_function Fitness function.
		* @param _number_to_select Size of population after selection.
		*/
		virtual void doSelection(Population& _population, const FitnessFunction& _fitness_function, int _number_to_select) = 0;

		/**
		* Sets selection type.
		* @param new selection type.
		*/
		void setSelectionType(SelectionType _selection_type) { selection_type = _selection_type; }

	protected: 
		SelectionType selection_type;
		std::default_random_engine generator;
	};


	///A class for CPU-based selection.
	class SelectionCPU
		:public Selection
	{
	public:
		/**
		* SelectionCPU constructor.
		* @param _selection_type Selection type.
		*/
		SelectionCPU(SelectionType _selection_type):
			Selection(_selection_type) {};
		~SelectionCPU() {};

		/**
		* Starts population selection, new population replaces old one.
		* @param _population Population.
		* @param _fitness_function Fitness function.
		* @param _number_to_select Size of population after selection.
		*/
		void doSelection(Population& _population, const FitnessFunction& _fitness_function, int _number_to_select);

	private:
		void doSelectionRanking(Population& _population, int _number_to_select);
		void doSelectionProportional(Population& _population, int _number_to_select);

	};
	
	///A class for GPU-based selection.
	class SelectionGPU
		:public Selection
	{
	public:
		/**
		* SelectionGPU constructor.
		* @param _selection_type Selection type.
		*/
		SelectionGPU(SelectionType _selection_type):
			Selection(_selection_type) {};
		~SelectionGPU() {};

		/**
		* Starts population selection, new population replaces old one.
		* @param _population Population.
		* @param _fitness_function Fitness function.
		* @param _number_to_select Size of population after selection.
		*/
		void doSelection(Population& _population, const FitnessFunction& _fitness_function, int _number_to_select);

	private:
		void doSelectionRanking(Population& _population, int _number_to_select);
		void doSelectionProportional(Population& _population, int _number_to_select);
	};
	typedef boost::shared_ptr<Selection> SelectionPtr;
}


