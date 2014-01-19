#pragma once
#include "Individual.h"

namespace ealib {

	/// An algorithm result class.
	/**It contains best individual, steps taken to by an algorithm and the time it lasted.
	*/
	class Result
	{
	public:
		Result(int _steps_number, double _running_time, const Individual& _best_individual)
		{
			steps_number = _steps_number;
			running_time = _running_time;
			*best_individual = _best_individual;
		}
		~Result();
		Individual getBestIndividual() { return *best_individual; }
		int getStepsNumber() const { return steps_number; }
		///Returns algorithm's running time in seconds.
		double getRunningTime() const { return running_time; }

	private:
		Individual *best_individual;
		int steps_number;
		double running_time;
	};

}

