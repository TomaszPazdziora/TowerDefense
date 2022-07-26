#pragma once
#include <vector>
#include "Point.h"

namespace Path
{
	Point getCharDisplacement(char c);
	Point getSpawnPoint(const std::vector <std::string>& data);

	std::vector <Point> makePathVector(const std::vector <std::string>& data);
};

