#pragma once
#include <cstdlib>
#include "Vector.h"
#include "Path.h"
#include "Wave.h"

class Map
{
private:

	// variables used in overlay creation process
	const std::string charsToChange = { "<,^6>.vVE" };
	const char destinationChar = ' ';

	// important map variables
	std::vector <std::string> mapData;


public:
	// variables used in main loop
	std::vector <Wave> waveVector;
	std::vector <std::string> mapOverlay;
	std::vector <Point> pathVector;
	int pathVectorLastIndex = 0;

	std::vector <std::string> makeMapOverlay();
	std::vector <std::string> setFirstAndLastPathChar();


	//inicjalizating variables by constructor

	Map(std::string mapName)
	{
		if (mapName == "Exit")
		{
			exit(0);
		}

		if (mapName == "New Game")
		{
			std::cout << "It is currently evolving." << std::endl;
			exit(0);
		}

		mapData = Vector::loadWholeFile("Maps\\" + mapName, mapName);
		pathVector = Path::makePathVector(mapData);
		pathVectorLastIndex = int(pathVector.size()) - 1;

		mapOverlay = makeMapOverlay();
		mapOverlay = setFirstAndLastPathChar();

		Wave firstWave = Wave(mapName);
		waveVector.push_back(firstWave);
	}
};
