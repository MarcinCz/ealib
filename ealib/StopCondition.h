#pragma once
#include <stdexcept>

namespace ealib {

	namespace exception {
		///A class for stop condition type exception.
		class StopConditionException :public std::runtime_error
		{
		public:
			StopConditionException() :std::runtime_error("Stop condition exception"){}
			StopConditionException(std::string msg) :std::runtime_error(msg.c_str()){}
		};
	}

	
	///A stop condition class for evolutionary algorithm.
	/**
	* User can specify number of steps or minimal fitness function value.
	* If only one condition is set, the other one is ignored.
	*/
	class StopCondition
	{
	public:
		/** 
		* StopCondition constructor.
		* @param _max_steps Maximal number of steps to be taken.
		*/
		StopCondition(int _max_steps)
		{
			setMaxSteps(_max_steps);
			min_fitness_value_set = false;
			max_steps_set = true;
		}

		/** 
		* StopCondition constructor.
		* @param _max_steps Minimal sufficient fitness value.
		*/
		StopCondition(double _min_fitness_value)
		{
			min_fitness_value = _min_fitness_value;
			min_fitness_value_set = true;
			max_steps_set = false;
		}
		
		/** 
		* StopCondition constructor.
		* @param _max_steps Maximal number of steps to be taken.
		* @param _max_steps Minimal sufficient fitness value.
		*/
		StopCondition(int _max_steps, double _min_fitness_value)
		{
			setMaxSteps(_max_steps);
			min_fitness_value = _min_fitness_value;
			min_fitness_value_set = true;
			max_steps_set = true;
		}
		~StopCondition() {}

		/**
		* Sets new maximal steps number.
		* @param New maximal steps number.
		* @throw ealib::exception::StopConditionException If steps number is not a positive number.
		*/
		void setMaxSteps(const int _max_steps) 
		{ 
			if(_max_steps <= 0)
				throw exception::StopConditionException("Steps number must be positive");
			max_steps = _max_steps; max_steps_set = true; 
		} 
		void setMinFitnessValue(const double _min_fitness_value) { min_fitness_value = _min_fitness_value; min_fitness_value_set = true; }
		
		/**
		* Returns maximal number of steps before algorithm stops.
		* @throw ealib::exception::StopConditionException If maximal steps number is not set.
		*/
		int getMaxSteps() const 
		{
			if(!max_steps_set)
				throw exception::StopConditionException("Max steps number not set.");
			return max_steps; 
		}

		/**
		* Returns min fitness value before algorithm stops. 
		* @throw ealib::exception::StopConditionException If minimal fitness value is not set.
		*/
		double getMinFitnessValue() const 
		{
			if(!min_fitness_value_set)
				throw exception::StopConditionException("Min fitness value not set.");
			return min_fitness_value; 
		}
		bool isMinFitnessValueSet() { return min_fitness_value_set; }
		bool isMaxStepsSet() { return max_steps_set; }

	private:
		int max_steps;
		double min_fitness_value;
		bool max_steps_set;
		bool min_fitness_value_set;
	};	
}


