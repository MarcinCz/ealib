#pragma once

namespace ealib {

	/// A stop condition class for evolutionary algorithm
	/**	User can specify number of steps or minimal fitness function value
	*/
	class StopCondition
	{
	public:
		StopCondition();
		~StopCondition() {}
		void setMinSteps(const int _min_steps) { min_steps = _min_steps; } 
		void setMinFitnessValue(const float _min_fitness_value) { min_fitness_value = _min_fitness_value; }
		int getMinSteps() const { return min_steps; }
		float getMinFitnessValue() const { return min_fitness_value; }

	private:
		int min_steps;
		float min_fitness_value;
	};
}


