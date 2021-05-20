#include <vector>
#include <iostream>

class SolveSets
{
	std::vector<std::vector<int>> Sets;

	int Determinants[4];

	std::vector<std::vector<int>> shrinkSetsToMatrix3()
	{
		std::vector<std::vector<int>> temp = Sets;
		for (int i = 0; i < 3; i++)
		{
			temp[i].resize(3);
			temp[i].shrink_to_fit();
		}

		return temp;
	}

	void CalculateDeterminants()
	{
		std::vector<std::vector<int>> temp = shrinkSetsToMatrix3();
		Determinants[0] = CalculateDeteminant(temp);

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				temp[j][i] = Sets[j][3];
			}

			Determinants[i+1] = CalculateDeteminant(temp);
			temp = shrinkSetsToMatrix3();
		}
	}

	int CalculateDeteminant(std::vector<std::vector<int>> set)
	{
		int determinant = 0;
		for (int i = 0; i < 3; i++)
		{
			int temp = 1; 
			for (int j = 0; j < 3; j++)
			{
				temp *= set[j][(i + j) % 3];
			}
			determinant += temp;
		}

		for (int i = 0; i < 3; i++)
		{
			int temp = 1;
			for (int j = 0; j < 3; j++)
			{
				temp *= set[2-j][(j+i)%3];
			}
			determinant -= temp;
		}

		return determinant;
	}

public:
	
	SolveSets(std::vector<std::vector<int>> sets);
	std::string GetDetermination();
	std::vector<double> GetResoultion();
};

