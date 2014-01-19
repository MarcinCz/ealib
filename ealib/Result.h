#pragma once
#include "Individual.h"

namespace ealib {

	/// An algorithm result class.
	/**It contains best individual, steps taken to by an algorithm and the time it lasted.
	*/
	class Result
	{
	public:
		Result(int _steps_taken, double _running_time, Individual& _best_individual)
		{
			steps_taken = _steps_taken;
			running_time = _running_time;
			best_individual = &_best_individual;
		}
		~Result() {};
		Individual getBestIndividual() { return *best_individual; }
		int getStepsTaken() const { return steps_taken; }
		///Returns algorithm's running time in seconds.
		double getRunningTime() const { return running_time; }

	private:
		Individual *best_individual;
		int steps_taken;
		double running_time;
	};

}

