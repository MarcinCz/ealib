#pragma once
#include "Individual.h"

namespace ealib {

	///An algorithm result class.
	class Result
	{
	public:
		/**
		* Result constructor class.
		* @param _steps_taken Steps taken by an algorithm.
		* @param _running_time Algorithm's run time.
		* @param _best_individual Best individual found by the algorithm.
		*/
		Result(int _steps_taken, double _running_time, Individual& _best_individual)
		{
			steps_taken = _steps_taken;
			running_time = _running_time;
			best_individual = &_best_individual;
		}
		~Result() {};

		/**
		* Returns best individual found.
		* @return Best individual.
		*/
		Individual getBestIndividual() { return *best_individual; }

		/**
		* Return steps taken by the algorithm.
		* @return Steps taken.
		*/
		int getStepsTaken() const { return steps_taken; }

		/**
		* Returns algorithm's run time in seconds.
		* @return Algorithm's run time.
		*/
		double getRunningTime() const { return running_time; }

	private:
		Individual *best_individual;
		int steps_taken;
		double running_time;
	};

}

