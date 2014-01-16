#include "Selection.h"
#include <math.h>
#include <stdlib.h>     
#include <time.h>       

using namespace std;

namespace ealib
{
	Selection::~Selection()
	{
	}

	vector<IndividualP> doSelectionRankingCPU(const Population& _population)
	{
		vector<IndividualP> individuals = _population.getIndividuals();
		vector<IndividualP> new_individuals;

		sort(individuals.begin(),individuals.end(),
			[](const IndividualP ind1, const IndividualP ind2)
			{
			return ind1->getFitnessValue() > ind2->getFitnessValue();
			});
		
		int rank_sum = ((1 + individuals.size())*individuals.size()) / 2;
		int N = individuals.size();

		//selecting N elements
		for (int i = 0; i < N; ++i)
		{
			/*Every individual has got a rank from 1 to N.
			*1-worst, N-best.
			*Probability of selecting element with rank j is j/rank_sum.
			*/
			int rank_place = rand() % rank_sum;
			int currect_rank_place = 0;

			
			for (int j = 1; j <= N; ++j)
			{
				if (currect_rank_place >= rank_place && currect_rank_place < rank_place + j)
				{
					new_individuals.push_back(individuals.at(j-1));
					break;
				}
				currect_rank_place += j;
			}
		}

		return new_individuals;
	}

	vector<IndividualP> doSelectionProportionalCPU(const Population& _population)
	{
		vector<IndividualP> individuals = _population.getIndividuals();
		vector<IndividualP> new_individuals;

		sort(individuals.begin(), individuals.end(),
			[](const IndividualP ind1, const IndividualP ind2)
		{
			return ind1->getFitnessValue() < ind2->getFitnessValue();
		});

		double fitness_sum = 0;
		for_each(individuals.begin(), individuals.end(), [&fitness_sum](IndividualP ind){ fitness_sum += ind->getFitnessValue(); });
		int N = individuals.size();

		//selecting N elements
		for (int i = 0; i < N; ++i)
		{
			/*Every individual has got a probabilty of getting selected equal to fitness_value/fitness_sum
			*/
			double prop_place = (static_cast<double>(rand()) / RAND_MAX) * fitness_sum;
			double currect_prop_place = 0;


			for (int j = 0; j < N; ++j)
			{
				if (currect_prop_place >= prop_place && currect_prop_place < prop_place + individuals.at(j)->getFitnessValue())
				{
					new_individuals.push_back(individuals.at(j));
					break;
				}
				currect_prop_place += individuals.at(j)->getFitnessValue();
			}
		}

		return new_individuals;
	}

	vector<IndividualP> Selection::doSelectionCPU(const Population& _population, const FitnessFunction& _fitness_function)
	{
		int number_to_select = ceil(selection_ratio * static_cast<double>(_population.getPopulationSize()));
		for (IndividualP ind : _population.getIndividuals())
		{
			ind->setFitnessValue(_fitness_function(*ind));
		}

		srand(time(NULL));

		if (selection_type == SelectionType::PROPORTIONAL)
		{
			return doSelectionProportionalCPU(_population);
		}
		else
		{
			return doSelectionRankingCPU(_population);
		}
	}
}

