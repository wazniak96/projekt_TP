#include <iostream>
#include <string>
#include <functional>
#include <vector>

class NormalizeSets
{
	std::string Sets[3];
	std::vector<std::vector<int>> NormalizedSets;

	void Normalize()
	{
		for (int i = 0; i < 3; i++)
		{
			int x = 0;
			int y = 0;
			int z = 0;
			int number = 0;
			std::string temp = "";
			bool isNegative = false;
			bool afterEqual = false;
			for (int j = 0; j < Sets[i].length(); j++)
			{
				if (Sets[i][j] == '-')
				{
					if (!temp.empty())
					{
						int temp_numb = std::stoi(temp);
						if (afterEqual == false)
							temp_numb = std::negate<int>()(temp_numb);
						if (isNegative == true)
							temp_numb = std::negate<int>()(temp_numb);

						number += temp_numb;
						temp = "";
						isNegative = false;
					}
					isNegative = true;
				}

				else if (Sets[i][j] == '+' || Sets[i][j] == '=')
				{
					if (!temp.empty())
					{
						int temp_numb = std::stoi(temp);
						if(afterEqual == false)
							temp_numb = std::negate<int>()(temp_numb);
						if(isNegative == true)
							temp_numb = std::negate<int>()(temp_numb);

						number += temp_numb;
						temp = "";
						isNegative = false;
					}

					if (Sets[i][j] == '=')
						afterEqual = true;
				}

				else if (isdigit(Sets[i][j]))
					temp.push_back(Sets[i][j]);

				else if (Sets[i][j] == 'x' || Sets[i][j] == 'y' || Sets[i][j] == 'z')
				{
					int temp_numb;
					if (temp.empty())
					{
						temp_numb = 1;
					}
					else
					{
						temp_numb = std::stoi(temp);
					}
					if (afterEqual == true)
						temp_numb = std::negate<int>()(temp_numb);
					if (isNegative == true)
						temp_numb = std::negate<int>()(temp_numb);

					if (Sets[i][j] == 'x')
						x += temp_numb;
					else if (Sets[i][j] == 'y')
						y += temp_numb;
					else
						z += temp_numb;

					temp = "";
					isNegative = false;
				}
			}
			if (!temp.empty())
			{
				int temp_numb = std::stoi(temp);
				if (isNegative == true)
					temp_numb = std::negate<int>()(temp_numb);
				number += temp_numb;
			}

			NormalizedSets[i][0] = x;
			NormalizedSets[i][1] = y;
			NormalizedSets[i][2] = z;
			NormalizedSets[i][3] = number;
		}
	};

public:
	NormalizeSets(std::string firstSet, std::string secondSet, std::string thirdSet);
	std::vector<std::vector<int>> GetNormalized();
};

