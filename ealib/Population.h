#pragma once
#include <vector>
#include <random>
#include <boost/shared_ptr.hpp>
#include <stdexcept>
#include <time.h>     
#include "Individual.h"

namespace ealib{

	///A class for individuals population.
	class Population
	{
	public:
		/**
		* Constructor for population.
		*/
		Population()
		{
			std::vector<IndividualPtr> individuals = std::vector<IndividualPtr>();
			representation_size = 8;
			generator.seed(static_cast<unsigned long>(time(NULL)));
		}
		~Population(){}
		/**
		* Adds new individual with the given representation.
		* @param _representation Individual's number representation.
		*/
		void addIndividual(std::vector<double> _representation);
		
		/**
		* Generates individuals with random representation.
		* @param _min Minal value of generated representation element.
		* @param _max Maximal value of generated representation element.
		* @param _number Number of individuals to generate.
		* @throw ealib::exception::PopulationException When representation size is wrong.
		*/
		void genIndividual(double _min, double _max, int _number = 1);

		/**
		* Returns a vector with individual's pointers.
		* @return Vector with individual's pointers.
		*/

		std::vector<IndividualPtr> getIndividuals() const { return individuals; }
		void clearPopulation() { individuals.clear(); }
		/**
		* Returns a pointer to the individual with the best fitness value.
		* @return Pointer to the individual with the best fitness value.
		*/
		IndividualPtr getBestIndividual();

		/**
		* Returns a sum of individuals' fitness values.
		* @return Sum of individuals' fitness values.
		*/
		double getFitnessValueSum(); 

		size_t getPopulationSize() const { return individuals.size(); }
		/**
		* Sets size of individual representation, default is 8.
		* @param New representatin size.
		* @throw ealib::exception::PopulationException When population is not empty or size is not a positive number.
		*/
		void  setRepresentationSize(int _representation_size);

		int getRepresentationSize() const { return representation_size; }
	private: 
		std::vector<IndividualPtr> individuals;
		int representation_size;
		std::default_random_engine generator;
	};

	namespace exception {
	
		///A class for population-type exception.
		class PopulationException :public std::runtime_error
		{
		public:
			PopulationException() :std::runtime_error("Population exception"){}
			PopulationException(std::string msg) :std::runtime_error(msg.c_str()){}
		};
	}

	typedef boost::shared_ptr<Population> PopulationPtr;
}
