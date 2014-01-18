#pragma once
#include "NormalDistMutationOperator.h"
#include "UniformDistMutationOperator.h"
#include "CrossoverOperator.h"

namespace ealib {

	class OperatorFabric
	{
	public:
		static OperatorFabric& getInstance();

		MutationOperatorPtr getNormalDistMutationOperator(double _standard_deviation, double _probability) const
		{
			return MutationOperatorPtr(new NormalDistMutationOperator(_standard_deviation, _probability));
		}
		MutationOperatorPtr getUniformDistMutationOperator(double _range, double _probability) const
		{
			return MutationOperatorPtr(new UniformDistMutationOperator(_range, _probability));
		}

	private:
		OperatorFabric() {};
		OperatorFabric(const OperatorFabric&) {};
		OperatorFabric& operator=(const OperatorFabric&) {};
	};
}


