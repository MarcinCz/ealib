#pragma once

namespace ealib {

	/// A stop condition class for evolutionary algorithm
	/**	User can specify number of steps or minimal fitness function value.
	*/
	class StopCondition
	{
	public:
		StopCondition(int _max_steps)
		{
			max_steps = _max_steps;
			min_fitness_value = 0;
			min_fitness_set = true;
			max_steps_set = false;
		}

		StopCondition(float _min_fitness_value)
		{
			min_fitness_value = min_fitness_value;
			max_steps = 0;
			min_fitness_set = true;
			max_steps_set = false;
		}

		StopCondition(int _max_steps, float _min_fitness_value)
		{
			max_steps = _max_steps;
			min_fitness_value = min_fitness_value;
			min_fitness_set = true;
			max_steps_set = true;
		}
		~StopCondition() {}
		void setMaxSteps(const int _max_steps) { max_steps = _max_steps; max_steps_set = true; } 
		void setMinFitnessValue(const float _min_fitness_value) { min_fitness_value = _min_fitness_value; min_fitness_set = true; }
		///Returns max number of steps before algorithm stops. 0 if not set.
		int getMaxSteps() const { return max_steps; }
		///Returns min fitness value before algorithm stops. 0.0 if not set.
		float getMinFitnessValue() const { return min_fitness_value; }
		bool isMinFitnessValueSet() { return min_fitness_value; }
		bool isMaxStepsSet() { return max_steps_set; }

	private:
		int max_steps;
		float min_fitness_value;
		bool max_steps_set;
		bool min_fitness_set;
	};
}


