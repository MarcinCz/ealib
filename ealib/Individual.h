#pragma once
#include <boost/shared_ptr.hpp>
#include <vector>

namespace ealib {

	typedef boost::shared_ptr<std::vector<double>> RepresentationPtr;

	///A class for individual.
	/**It holds representation and fitness function value.
	*/
	class Individual
	{
	public:
		Individual(std::vector<double> _representation) { representation = RepresentationPtr(new std::vector<double>(_representation)); }
		~Individual() {};
		double getFitnessValue() const { return fitness_value; }
		void setFitnessValue(double _fitness_value) { fitness_value = _fitness_value; }
		RepresentationPtr getRepresentation() const { return representation; }
		void setRepresentation(RepresentationPtr _representation) { representation = _representation; }

	private:
		double fitness_value;
		RepresentationPtr representation;
	};

	typedef boost::shared_ptr<Individual> IndividualPtr;
}