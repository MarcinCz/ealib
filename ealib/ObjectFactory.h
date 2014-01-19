#pragma once
#include "NormalMutationOperator.h"
#include "UniformMutationOperator.h"
#include "CrossoverOperator.h"
#include "Selection.h"

namespace ealib {

	using namespace eaoperator;

 
	///An abstract class for objects' factory.
	class AbstractObjectFactory
	{
	public:
		/**
		* Creates and returns pointer to normal distribution mutation operator.
		* @return Pointer to normal distribution mutation operator.
		*/
		virtual NormalMutationOperatorPtr getNormalMutationOperator(double _standard_deviation, double _probability) const = 0;
		/**
		* Creates and returns pointer to uniform distribution mutation operator.
		* @return Pointer to uniform distribution mutation operator.
		*/
		virtual UniformMutationOperatorPtr getUniformMutationOperator(double _range, double _probability) const = 0;
		/**
		* Creates and returns pointer to crossover operator.
		* @return Pointer to crossover operator.
		*/
		virtual CrossoverOperatorPtr getCrossoverOperator(double _population_ratio) const = 0;
		virtual SelectionPtr getSelection(Selection::SelectionType _selection_type) const = 0;
	};

	///A class for CPU-based objects' factory.
	class CPUObjectFactory
		:public AbstractObjectFactory
	{
	public:

		/**
		* Returns an CPUObjectFactory instance.
		* @return CPUObjectFactory instance.
		*/
		static CPUObjectFactory& getInstance();
		/**
		* Creates and returns pointer to normal distribution mutation operator.
		* @return Pointer to normal distribution mutation operator.
		*/
		NormalMutationOperatorPtr getNormalMutationOperator(double _standard_deviation, double _probability) const
		{
			return NormalMutationOperatorPtr(new NormalMutationOperatorCPU(_standard_deviation, _probability));
		}
		/**
		* Creates and returns pointer to uniform distribution mutation operator.
		* @return Pointer to uniform distribution mutation operator.
		*/
		UniformMutationOperatorPtr getUniformMutationOperator(double _range, double _probability) const
		{
			return UniformMutationOperatorPtr(new UniformMutationOperatorCPU(_range, _probability));
		}
		/**
		* Creates and returns pointer to crossover operator.
		* @return Pointer to crossover operator.
		*/
		CrossoverOperatorPtr getCrossoverOperator(double _population_ratio) const
		{
			return CrossoverOperatorPtr(new CrossoverOperatorCPU(_population_ratio));
		}
		/**
		* Creates and returns pointer to selection.
		* @return Pointer to selection.
		*/
		SelectionPtr getSelection(Selection::SelectionType _selection_type) const
		{
			return SelectionPtr(new SelectionCPU(_selection_type));
		}

	private:
		CPUObjectFactory() {};
		CPUObjectFactory(const CPUObjectFactory&) {};
		CPUObjectFactory& operator=(const CPUObjectFactory&) {};

	};

	///A class for GPU-based objects' factory.
	class GPUObjectFactory
		:public AbstractObjectFactory
	{
	public:
		/**
		* Returns an GPUObjectFactory instance.
		* @return GPUObjectFactory instance.
		*/
		static GPUObjectFactory& getInstance();
		/**
		* Creates and returns pointer to normal distribution mutation operator.
		* @return Pointer to normal distribution mutation operator.
		*/
		NormalMutationOperatorPtr getNormalMutationOperator(double _standard_deviation, double _probability) const
		{
			return NormalMutationOperatorPtr(new NormalMutationOperatorGPU(_standard_deviation, _probability));
		}
		/**
		* Creates and returns pointer to uniform distribution mutation operator.
		* @return Pointer to uniform distribution mutation operator.
		*/
		UniformMutationOperatorPtr getUniformMutationOperator(double _range, double _probability) const
		{
			return UniformMutationOperatorPtr(new UniformMutationOperatorGPU(_range, _probability));
		}
		/**
		* Creates and returns pointer to crossover operator.
		* @return Pointer to crossover operator.
		*/
		CrossoverOperatorPtr getCrossoverOperator(double _population_ratio) const
		{
			return CrossoverOperatorPtr(new CrossoverOperatorGPU(_population_ratio));
		}
		/**
		* Creates and returns pointer to selection.
		* @return Pointer to selection.
		*/
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


