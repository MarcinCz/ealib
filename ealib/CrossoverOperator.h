#pragma once
#include <boost/shared_ptr.hpp>
#include <random>
#include <time.h>
#include "Population.h"


namespace ealib {

	namespace eaoperator {

		///An abstract class for crossover operator.
		class CrossoverOperator
		{
		public:

			/**
			* Constructor for CrossoverOperator.
			* @param _population_ratio New crossovers number to population size ratio.
			*/
			CrossoverOperator(double _population_ratio): population_ratio(_population_ratio)
			{
				generator.seed(static_cast<unsigned long>(time(NULL)));
			}
			~CrossoverOperator() {};

			/**
			* Starts crossover operator.
			* @param _population. Population from which individuals will be selected and to which new ones will be added.
			*/
			virtual void doCrossover(Population& _population) = 0;
			void setPopulationRatio(const int _population_ratio) { population_ratio = _population_ratio; }
			double getPopulationRatio() const { return population_ratio; }

		protected:
			double population_ratio;
			std::default_random_engine generator;
			std::uniform_int_distribution<int> distribution;
		};

		///A class for CPU-based crossover operator.
		class CrossoverOperatorCPU:
			public CrossoverOperator
		{
		public:
			/**
			* Constructor for CrossoverOperatorCPU.
			* @param _population_ratio New crossovers number to population size ratio.
			*/
			CrossoverOperatorCPU(double _population_ratio)
				:CrossoverOperator(_population_ratio) {};
			~CrossoverOperatorCPU() {};

			/**
			* Starts crossover operator.
			* @param _population. Population from which individuals will be selected and to which new ones will be added.
			*/
			void doCrossover(Population& _population);
		};

		///A class for GPU-based crossover operator.
		class CrossoverOperatorGPU:
			public CrossoverOperator
		{
		public:
			/**
			* Constructor for CrossoverOperatorGPU.
			* @param _population_ratio New crossovers number to population size ratio.
			*/
			CrossoverOperatorGPU(double _population_ratio)
				:CrossoverOperator(_population_ratio) {};
			~CrossoverOperatorGPU() {};

			/**
			* Starts crossover operator.
			* @param _population. Population from which individuals will be selected and to which new ones will be added.
			*/
			void doCrossover(Population& _population);
		};

		typedef boost::shared_ptr<CrossoverOperator> CrossoverOperatorPtr;
	}
	
}


