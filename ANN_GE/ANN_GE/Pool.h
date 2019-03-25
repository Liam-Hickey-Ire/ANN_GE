#ifndef POOL_H
#define POOL_H

#include <vector>
#include <algorithm>
#include "Chromosome.h"
#include "MathUtil.h"

struct Member
{
	Chromosome chromosome;
	float fitness;
};

static bool sortMembersByFitness(const Member & a, const Member & b)
{
	return a.fitness < b.fitness;
}

class Pool
{
public:
	Pool(Chromosome baseChromosome, int populationSize, float mutationChance, float minWeight, float maxWeight);
	~Pool();
	void runGeneration();
	Chromosome getBestChromosome();
	std::vector<Member> & getMembers();
private:
	void genPopulation(Chromosome baseChromosome);
	void performCrossovers();
	Chromosome crossover(Chromosome parent1, Chromosome parent2);
	void performMutations();

	int m_populationSize;
	float m_mutationChance;
	float m_minWeight;
	float m_maxWeight;
	std::vector<Member> m_population;
};

#endif // !POOL_H
