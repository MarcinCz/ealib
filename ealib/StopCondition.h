#pragma once

namespace ealib {

	namespace exception {
		class StopConditionException :public std::runtime_error
		{
		public:
			StopConditionException() :std::runtime_error("Stop condition exception"){}
			StopConditionException(std::string msg) :std::runtime_error(msg.c_str()){}
		};
	}

	/// A stop condition class for evolutionary algorithm
	/**	User can specify number of steps or minimal fitness function value.
	*/
	class StopCondition
	{
	public:
		StopCondition(int _max_steps)
		{
			setMaxSteps(_max_steps);
			min_fitness_value_set = false;
			max_steps_set = true;
		}

		StopCondition(double _min_fitness_value)
		{
			min_fitness_value = _min_fitness_value;
			min_fitness_value_set = true;
			max_steps_set = false;
		}

		StopCondition(int _max_steps, double _min_fitness_value)
		{
			setMaxSteps(_max_steps);
			min_fitness_value = _min_fitness_value;
			min_fitness_value_set = true;
			max_steps_set = true;
		}
		~StopCondition() {}
		void setMaxSteps(const int _max_steps) 
		{ 
			if(_max_steps <= 0)
				throw exception::StopConditionException("Steps number must be positive");
			max_steps = _max_steps; max_steps_set = true; 
		} 
		void setMinFitnessValue(const double _min_fitness_value) { min_fitness_value = _min_fitness_value; min_fitness_value_set = true; }
		/**Returns max number of steps before algorithm stops. 0 if not set.
		*
		*Throw StopConditionException if not set.
		*/
		int getMaxSteps() const 
		{
			if(!max_steps_set)
				throw exception::StopConditionException("Max steps number not set.");
			return max_steps; 
		}
		/**Returns min fitness value before algorithm stops. 
		*
		*Throw StopConditionException if not set.
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


