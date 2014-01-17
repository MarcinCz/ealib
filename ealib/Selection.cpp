#include "Selection.h"
#include <math.h>
#include <stdlib.h>     
 

using namespace std;

namespace ealib
{
	Selection::~Selection()
	{
	}

	vector<IndividualP> Selection::doSelectionRankingCPU(const PopulationP _population, int _number_to_select)
	{
		vector<IndividualP> individuals = _population->getIndividuals();
		vector<IndividualP> new_individuals;

		sort(individuals.begin(),individuals.end(),
			[](const IndividualP ind1, const IndividualP ind2)
			{
			return ind1->getFitnessValue() < ind2->getFitnessValue();
			});
		
		int rank_sum = ((1 + individuals.size())*individuals.size()) / 2;
		int N = individuals.size();
		uniform_int_distribution<int> distribution = uniform_int_distribution<int>(0, rank_sum-1);

		//selecting elements
		for (int i = 0; i < _number_to_select; ++i)
		{
			/*Every individual has got a rank from 1 to N.
			*1-worst, N-best.
			*Probability of selecting element with rank j is j/rank_sum.
			*/
			int rank_place = distribution(generator);
			int current_rank_place = 0;

			
			for (int j = 1; j <= N; ++j)
			{
				if (rank_place >= current_rank_place && rank_place < current_rank_place + j)
				{
					new_individuals.push_back(individuals.at(j-1));
					break;
				}
				current_rank_place += j;
			}
		}

		return new_individuals;
	}

	vector<IndividualP> Selection::doSelectionProportionalCPU(const PopulationP _population, int _number_to_select)
	{
		vector<IndividualP> individuals = _population->getIndividuals();
		vector<IndividualP> new_individuals;

		sort(individuals.begin(), individuals.end(),
			[](const IndividualP ind1, const IndividualP ind2)
			{
				return ind1->getFitnessValue() < ind2->getFitnessValue();
			});

		double fitness_sum = 0;
		for_each(individuals.begin(), individuals.end(), [&fitness_sum](IndividualP ind){ fitness_sum += ind->getFitnessValue(); });
		int N = individuals.size();
		uniform_real_distribution<double> distribution = uniform_real_distribution<double>(0, fitness_sum);

		//selecting elements
		for(int i = 0; i < _number_to_select; ++i)
		{
			/*Every individual has got a probabilty of getting selected equal to fitness_value/fitness_sum
			*/
			double prop_place = distribution(generator);
			double currect_prop_place = 0;


			for (int j = 0; j < N; ++j)
			{
				if (prop_place >= currect_prop_place && prop_place < currect_prop_place + individuals.at(j)->getFitnessValue())
				{
					new_individuals.push_back(individuals.at(j));
					break;
				}
				currect_prop_place += individuals.at(j)->getFitnessValue();
			}
		}

		return new_individuals;
	}

	vector<IndividualP> Selection::doSelectionCPU(const PopulationP _population, const FitnessFunction& _fitness_function, int _number_to_select)
	{
		for (IndividualP ind : _population->getIndividuals())
		{
			ind->setFitnessValue(_fitness_function(*ind));
		}

		if (selection_type == SelectionType::PROPORTIONAL)
		{
			return doSelectionProportionalCPU(_population, _number_to_select);
		}
		else
		{
			return doSelectionRankingCPU(_population,_number_to_select);
		}
	}
}

