#include "Selection.h"
#include <math.h>

using namespace std;

namespace ealib
{
	Selection::~Selection()
	{
	}

	vector<Individual> doSelectionRankingCPU(const Population& _population, int _number_to_select)
	{
		vector <Individual> individuals;
		return individuals;
	}

	vector<Individual> doSelectionProportionalCPU(const Population& _population, int _number_to_select)
	{
		vector <Individual> individuals;
		return individuals;
	}

	vector<Individual> Selection::doSelectionCPU(const Population& _population)
	{
		int number_to_select = ceil(static_cast<double>(_population.getPopulationSize())*selection_ratio);
		if (selection_type == SelectionType::PROPORTIONAL)
		{
			return doSelectionProportionalCPU(_population, number_to_select);
		}
		else
		{
			return doSelectionRankingCPU(_population, number_to_select);
		}
	}

	
}

