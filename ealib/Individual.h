#pragma once
#include <vector>

namespace ealib {

	///A class for individual.
	/**It holds representation and fitness function value.
	*/
	class Individual
	{
	public:
		Individual(const std::vector<double> _representation) { representation = _representation; }
		~Individual();
		double getFitnessValue() const { return fitness_value; }
		void setFitnessValue(double _fitness_value) { fitness_value = _fitness_value; }
		std::vector<double> getRepresentation() const { return representation; }
		void setRepresentation(const std::vector<double> _representation) { representation = _representation; }

	private:
		double fitness_value;
		std::vector<double> representation;
	};
}