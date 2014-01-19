#pragma once
#include "NormalMutationOperator.h"
#include "UniformMutationOperator.h"
#include "CrossoverOperator.h"
#include "Selection.h"

namespace ealib {

	using namespace eaoperator;

	class AbstractObjectFactory
	{
	public:

		virtual NormalMutationOperatorPtr getNormalMutationOperator(double _standard_deviation, double _probability) const = 0;
		virtual UniformMutationOperatorPtr getUniformMutationOperator(double _range, double _probability) const = 0;
		virtual CrossoverOperatorPtr getCrossoverOperator(double _population_ratio) const = 0;
		virtual SelectionPtr getSelection(Selection::SelectionType _selection_type) const = 0;
	};

	class CPUObjectFactory
		:public AbstractObjectFactory
	{
	public:
		static CPUObjectFactory& getInstance();

		NormalMutationOperatorPtr getNormalMutationOperator(double _standard_deviation, double _probability) const
		{
			return NormalMutationOperatorPtr(new NormalMutationOperatorCPU(_standard_deviation, _probability));
		}
		UniformMutationOperatorPtr getUniformMutationOperator(double _range, double _probability) const
		{
			return UniformMutationOperatorPtr(new UniformMutationOperatorCPU(_range, _probability));
		}
		CrossoverOperatorPtr getCrossoverOperator(double _population_ratio) const
		{
			return CrossoverOperatorPtr(new CrossoverOperatorCPU(_population_ratio));
		}
		SelectionPtr getSelection(Selection::SelectionType _selection_type) const
		{
			return SelectionPtr(new SelectionCPU(_selection_type));
		}

	private:
		CPUObjectFactory() {};
		CPUObjectFactory(const CPUObjectFactory&) {};
		CPUObjectFactory& operator=(const CPUObjectFactory&) {};

	};

	class GPUObjectFactory
		:public AbstractObjectFactory
	{
	public:
		static GPUObjectFactory& getInstance();

		NormalMutationOperatorPtr getNormalMutationOperator(double _standard_deviation, double _probability) const
		{
			return NormalMutationOperatorPtr(new NormalMutationOperatorGPU(_standard_deviation, _probability));
		}
		UniformMutationOperatorPtr getUniformMutationOperator(double _range, double _probability) const
		{
			return UniformMutationOperatorPtr(new UniformMutationOperatorGPU(_range, _probability));
		}
		CrossoverOperatorPtr getCrossoverOperator(double _population_ratio) const
		{
			return CrossoverOperatorPtr(new CrossoverOperatorGPU(_population_ratio));
		}
		SelectionPtr getSelection(Selection::SelectionType _selection_type) const
		{
			return SelectionPtr(new SelectionGPU(_selection_type));
		}
	private:
		GPUObjectFactory() {};
		GPUObjectFactory(const GPUObjectFactory&) {};
		GPUObjectFactory& operator=(const GPUObjectFactory&) {};
	};
}


