#pragma once
#include <string>

class Point
{
public:
	int x = 0;
	int y = 0;

	Point(int newX, int newY);

	bool operator == (const Point& pointA)
	{
		return pointA.x == x && pointA.y == y;
	}

	Point operator + (const Point& other)
	{
		return Point(x + other.x, y + other.y);
	}

	std::string toString()
	{
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}
};