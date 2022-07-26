#include "Map.h"

std::vector <std::string> Map::makeMapOverlay()
{
	std::vector <std::string> overlay = mapData;
	std::vector <Point> pointVector = Vector::getPointVector(mapData, charsToChange);

	for (int i = 0; i < pointVector.size(); i++)
	{
		overlay[pointVector[i].x][pointVector[i].y] = destinationChar;
	}

	return overlay;
}

std::vector <std::string> Map::setFirstAndLastPathChar()
{
	std::vector <std::string> overlay = mapOverlay;
	overlay[pathVector[0].y][pathVector[0].x] = 'B';
	overlay[pathVector[pathVectorLastIndex].y][pathVector[pathVectorLastIndex].x] = 'E';

	return overlay;
}
