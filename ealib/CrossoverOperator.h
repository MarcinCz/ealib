#pragma once
#include <boost/shared_ptr.hpp>
#include <random>
#include <time.h>
#include "Population.h"


namespace ealib {

	namespace eaoperator {

		/** Class for crossover operator, provided by user when creating an algorithm
		*/
		class CrossoverOperator
		{
		public:
			CrossoverOperator(double _population_ratio): population_ratio(_population_ratio)
			{
				generator.seed(static_cast<unsigned long>(time(NULL)));
			}
			~CrossoverOperator() {};
			virtual void doCrossover(const PopulationPtr& _population) = 0;
			void setPopulationRatio(const int _population_ratio) { population_ratio = _population_ratio; }
			double getPopulationRatio() const { return population_ratio; }

		protected:
			double population_ratio;
			std::default_random_engine generator;
			std::uniform_int_distribution<int> distribution;
		};

		class CrossoverOperatorCPU:
			public CrossoverOperator
		{
		public:
			CrossoverOperatorCPU(double _population_ratio)
				:CrossoverOperator(_population_ratio) {};
			~CrossoverOperatorCPU() {};
			void doCrossover(const PopulationPtr& _population);
		};

		class CrossoverOperatorGPU:
			public CrossoverOperator
		{
		public:
			CrossoverOperatorGPU(double _population_ratio)
				:CrossoverOperator(_population_ratio) {};
			~CrossoverOperatorGPU() {};
			void doCrossover(const PopulationPtr& _population);
		};

		typedef boost::shared_ptr<CrossoverOperator> CrossoverOperatorPtr;
	}
	
}


