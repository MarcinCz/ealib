#pragma once
#include "Individual.h"

namespace ealib {

	/// An algorithm result class.
	/**It contains best individual, steps taken to by an algorithm and the time it lasted.
	*/
	class Result
	{
	public:
		Result();
		~Result();
		Individual getBestIndividual() { return bestIndividual; }
		int getStepsNumber() const { return steps_number; }
		///Returns algorithm's running time in seconds.
		double getRunningTime() const { return running_time; }

	private:
		Individual bestIndividual;
		int steps_number;
		double running_time;
	};

}

