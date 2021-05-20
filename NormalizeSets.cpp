#include "NormalizeSets.h"

NormalizeSets::NormalizeSets(std::string firstSet, std::string secondSet, std::string thirdSet)
{
	Sets[0] = firstSet;
	Sets[1] = secondSet;
	Sets[2] = thirdSet;

	NormalizedSets = std::vector<std::vector<int>>(3, std::vector<int>(4, 0));

	Normalize();
}

std::vector<std::vector<int>> NormalizeSets::GetNormalized()
{
	return NormalizedSets;
}
