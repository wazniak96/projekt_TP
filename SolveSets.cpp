#include "SolveSets.h"

SolveSets::SolveSets(std::vector<std::vector<int>> sets)
{
	Sets = sets;
	CalculateDeterminants();
}

std::string SolveSets::GetDetermination()
{
	if (Determinants[0] != 0)
		return "determinate";
	else if (Determinants[0] == 0 && Determinants[1] == 0 && Determinants[2] == 0 && Determinants[3] == 0)
		return "indeterminate";
	else
		return "contradictory";
}

std::vector <double> SolveSets::GetResoultion()
{
	std::vector<double> res = std::vector<double>(3, 0);
	
	res[0] = Determinants[1] / Determinants[0];
	res[1] = Determinants[2] / Determinants[0];
	res[2] = Determinants[3] / Determinants[0];

	return res;
}