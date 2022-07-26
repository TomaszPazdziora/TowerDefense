#pragma once
#include "Point.h"

struct Attacker
{
	int pathIndex = 0;
	int power = 0;
	int delay = 0;

	Attacker(int pow, int del)
	{
		power = pow;
		delay = del;
	}
};