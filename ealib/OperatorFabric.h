#pragma once
#include "NormalMutationOperator.h"
#include "UniformMutationOperator.h"
#include "CrossoverOperator.h"

namespace ealib {

	using namespace eaoperator;

	class AbstractOperatorFabric
	{
	public:

		virtual MutationOperatorPtr getNormalMutationOperator(double _standard_deviation, double _probability) const = 0;
		virtual MutationOperatorPtr getUniformMutationOperator(double _range, double _probability) const = 0;
		virtual CrossoverOperatorPtr getCrossoverOperator(double _population_ratio) const = 0;
	};

	class OperatorCPUFabric
		:public AbstractOperatorFabric
	{
	public:
		static OperatorCPUFabric& getInstance();

		MutationOperatorPtr getNormalMutationOperator(double _standard_deviation, double _probability) const
		{
			return MutationOperatorPtr(new NormalMutationOperatorCPU(_standard_deviation, _probability));
		}
		MutationOperatorPtr getUniformMutationOperator(double _range, double _probability) const
		{
			return MutationOperatorPtr(new UniformMutationOperatorCPU(_range, _probability));
		}
		CrossoverOperatorPtr getCrossoverOperator(double _population_ratio) const
		{
			return CrossoverOperatorPtr(new CrossoverOperatorCPU(_population_ratio));
		}

	private:
		OperatorCPUFabric() {};
		OperatorCPUFabric(const OperatorCPUFabric&) {};
		OperatorCPUFabric& operator=(const OperatorCPUFabric&) {};

	};

	class OperatorGPUFabric
		:public AbstractOperatorFabric
	{
	public:
		static OperatorGPUFabric& getInstance();

		MutationOperatorPtr getNormalMutationOperator(double _standard_deviation, double _probability) const
		{
			return MutationOperatorPtr(new NormalMutationOperatorGPU(_standard_deviation, _probability));
		}
		MutationOperatorPtr getUniformMutationOperator(double _range, double _probability) const
		{
			return MutationOperatorPtr(new UniformMutationOperatorGPU(_range, _probability));
		}
		CrossoverOperatorPtr getCrossoverOperator(double _population_ratio) const
		{
			return CrossoverOperatorPtr(new CrossoverOperatorGPU(_population_ratio));
		}
	private:
		OperatorGPUFabric() {};
		OperatorGPUFabric(const OperatorGPUFabric&) {};
		OperatorGPUFabric& operator=(const OperatorGPUFabric&) {};
	};
}


