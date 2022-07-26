#pragma once
#include "Attacker.h"
#include "Vector.h"

class Wave
{
public:

	std::vector <std::string> waveData;
	std::vector <Attacker> attackerVector;
	std::vector <Attacker> getAttackerVector(std::vector <std::string> waveData);

	Wave(std::string mapName)
	{
		waveData = Vector::loadWholeFile("Maps\\" + mapName + "\\waves", "\\wave0");
		attackerVector = getAttackerVector(waveData);
	}

	void writeAttVec();
};

