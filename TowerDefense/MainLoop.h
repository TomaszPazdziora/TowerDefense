#pragma once
#include "Menu.h"
#include "Map.h"

namespace MainLoop
{
	void run();
	std::string menu();

	Wave updatePossitions(Map map, int currentWaveNumber);
	void presentMap(Map newMap);
	Point getAttackerLocation(Map map, int waveVecCounter, int attackerVecCounter, int shift);

};
