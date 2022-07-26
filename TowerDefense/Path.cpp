#include "Path.h"
#include <iostream>


Point Path::getSpawnPoint(const std::vector <std::string>& data)
{
	for (int y = 0; y < data.size(); y++)
	{
		for (int x = 0; x < data[y].size(); x++)
		{
			char c = data[y][x];

			if (c == ',' || c == '.' || c == 'v' || c == '6')
			{
				return Point(x, y);
			}
		}
	}

	return Point(0, 0);
}

Point Path::getCharDisplacement(char c)
{
	if (c == '<') return Point(-1, 0);
	else if (c == '>') return Point(1, 0);
	else if (c == 'V') return Point(0, 1);
	else if (c == '^') return Point(0, -1);
	else if (c == ',') return Point(-1, 0);
	else if (c == '.') return Point(1, 0);
	else if (c == 'v') return Point(0, 1);
	else if (c == '6') return Point(0, -1);

	return Point(0, 0);
}

std::vector <Point> Path::makePathVector(const std::vector <std::string>& data)
{
	std::vector <Point> pathData;
	Point currentPos = getSpawnPoint(data);

	int buffer = 0;

	while (data[currentPos.y][currentPos.x] != 'E')
	{
		buffer++;

		if (buffer > 1000)
		{
			std::cout << "Path is too long or map txt file is not write correct!" << std::endl;
			exit(0);
		}

		pathData.push_back(currentPos);
		currentPos = currentPos + getCharDisplacement(data[currentPos.y][currentPos.x]);
	}

	pathData.push_back(currentPos);
	/*
	WRITE PATH VERTOR
	for (int i = 0; i < pathData.size(); i++)
	{
		std::cout << pathData[i].toString() << std::endl;
	}
	*/
	return pathData;
}
