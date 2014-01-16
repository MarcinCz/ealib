#pragma once

namespace ealib {

	/// A stop condition class for evolutionary algorithm
	/**	User can specify number of steps or minimal fitness function value
	*/
	class StopCondition
	{
	public:
		StopCondition(int _max_steps, float _min_fitness_value)
		{
			max_steps = _max_steps;
			min_fitness_value = min_fitness_value;
		}
		~StopCondition() {}
		void setMaxSteps(const int _max_steps) { max_steps = _max_steps; } 
		void setMinFitnessValue(const float _min_fitness_value) { min_fitness_value = _min_fitness_value; }
		int getMaxSteps() const { return max_steps; }
		float getMinFitnessValue() const { return min_fitness_value; }

	private:
		int max_steps;
		float min_fitness_value;
	};
}


