#include "helpers.h"
#include "stdlib.h"

void tweakSolution(memberType* member)
{
	int y;

	int x = randInterval(0U, MAX_LENGTH);	// BUG: MAX_LENGTH must be upper threshold value
	do
	{
		y = randInterval(0U, MAX_LENGTH);
	}
	while (x == y);

	int temp = member->solution[x];
	member->solution[x] = member->solution[y];
	member->solution[y] = temp;
}

void initializeSolution(memberType* member)
{
	int i;

	// ��������� ������������� �������
	for (i = 0; i < MAX_LENGTH; ++i)
	{
		member->solution[i] = i;
	}

	// ��������� ������� ��������� �������
	for (i = 0; i < MAX_LENGTH; ++i)
	{
		tweakSolution(member);
	}
}

unsigned randInterval(unsigned min, unsigned max)
{
	int r;
	const unsigned int range = 1 + max - min;
	const unsigned int buckets = RAND_MAX / range;
	const unsigned int limit = buckets * range;
	
	do
	{
		r = rand();
	} while (r >= limit);

	return min + r / buckets;
}

void computeEnergy(memberType* member)
{
}