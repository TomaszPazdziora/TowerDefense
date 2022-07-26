#include "Wave.h"

std::vector <Attacker> Wave::getAttackerVector(std::vector <std::string> waveData)
{
	std::vector <Attacker> attackerVector;
	std::string power;
	std::string delay;
	bool coma;

	for (int i = 0; i < waveData.size(); i++)
	{
		coma = false;
		delay = "";
		power = "";

		for (int j = 0; j < waveData[i].size(); j++)
		{
			// before ',' read power, after ',' read delay

			if (waveData[i][j] == ',')
			{
				coma = true;
				continue;
			}

			if (!coma)
			{
				power += waveData[i][j];
			}
			else
			{
				delay += waveData[i][j];
			}

			// last j loop circle
			if (waveData[i].size() - 1 == j)
			{
				attackerVector.push_back(Attacker(stoi(power), stoi(delay)));
			}

		}
	}

	return attackerVector;
}

void Wave::writeAttVec()
{
	for (int i = 0; i < attackerVector.size(); i++)
	{
		std::cout << attackerVector[i].power << ", " << attackerVector[i].delay << std::endl;
	}
}