#include "Selection.h"   
 
using namespace std;

namespace ealib
{
	void SelectionCPU::doSelectionRanking(Population& _population, int _number_to_select)
	{
		vector<IndividualPtr> individuals = _population.getIndividuals();
		_population.clearPopulation();
		
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
					_population.addIndividual(*(individuals.at(j-1)->getRepresentation()));
					_population.getIndividuals().at(i)->setFitnessValue(individuals.at(j-1)->getFitnessValue());
					break;
				}
				current_rank_place += j;
			}
		}

	}

	void SelectionGPU::doSelectionRanking(Population& _population, int _number_to_select)
	{

	}

	void SelectionCPU::doSelectionProportional(Population& _population, int _number_to_select)
	{
		vector<IndividualPtr> individuals = _population.getIndividuals();
		_population.clearPopulation();

		double fitness_sum = 0;
		for_each(individuals.begin(), individuals.end(), [&fitness_sum](IndividualPtr ind){ fitness_sum += ind->getFitnessValue(); });
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
					_population.addIndividual(*(individuals.at(j)->getRepresentation()));
					_population.getIndividuals().at(i)->setFitnessValue(individuals.at(j)->getFitnessValue());
					break;
				}
				currect_prop_place += individuals.at(j)->getFitnessValue();
			}
		}

	}

	void SelectionGPU::doSelectionProportional(Population& _population, int _number_to_select)
	{

	}

	void SelectionCPU::doSelection(Population& _population, const FitnessFunction& _fitness_function, int _number_to_select)
	{
		//calculating fitness values
		for (IndividualPtr ind : _population.getIndividuals())
		{
			ind->setFitnessValue(_fitness_function(*ind));
		}

		//sorting
		vector<IndividualPtr> individuals = _population.getIndividuals();

		sort(individuals.begin(), individuals.end(),
			[](const IndividualPtr ind1, const IndividualPtr ind2)
			{
				return ind1->getFitnessValue() < ind2->getFitnessValue();
			});

		//running selection
		if (selection_type == SelectionType::PROPORTIONAL)
		{
			doSelectionProportional(_population, _number_to_select);
		}
		else
		{
			doSelectionRanking(_population,_number_to_select);
		}
	}

	void SelectionGPU::doSelection(Population& _population, const FitnessFunction& _fitness_function, int _number_to_select)
	{

	}
}

