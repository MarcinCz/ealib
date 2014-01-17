#pragma once
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Individual.h"

namespace ealib{

	typedef boost::shared_ptr<Individual> IndividualP;
	///A class for individuals population
	class Population
	{
	public:
		Population()
		{
			individuals = std::vector<IndividualP>();
			representation_size = 8;
		}
		~Population(){}
		void addIndividual(std::vector<double> _representation);
		void genIndividual(double _min, double _max);
		std::vector<IndividualP> getIndividuals() const { return individuals; }
		void clearPopulation() { individuals.clear(); }
		IndividualP getBestIndividual();
		double getFitnessValueSum(); ///Returns sum of fitness values of every individual.
		int getPopulationSize() const { return individuals.size(); }
		///Sets size of individual representation(vector), default is 8.
		void setRepresentationSize(int _representation_size);
		int getRepresentationSize() const { return representation_size; }
	private: 
		std::vector<IndividualP> individuals;
		int representation_size;
	};

	class PopulationException :public std::runtime_error
	{
	public:
		PopulationException() :std::runtime_error("Population exception"){}
		PopulationException(std::string msg) :std::runtime_error(msg.c_str()){}
	};
}