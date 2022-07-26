#pragma once
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include "Vector.h"

class Menu
{
private:

	int firstOptionLocation = 0;
	int lastOptionLocation = 0;
	int arrowLocation = 0;
	static const int choosen = 100;

public:

	Menu(std::vector <std::string> menuVector)
	{
		firstOptionLocation = getFirstOptionLocation(menuVector);
		lastOptionLocation = getLastOptionLocation(menuVector);
		arrowLocation = getArrowLocation(menuVector);
	}

	// getting variables
	int getArrowLocation(std::vector <std::string> menuOverlay);
	int getFirstOptionLocation(std::vector <std::string> menuOverlay);
	int getLastOptionLocation(std::vector <std::string> menuOverlay);

	// menu logic
	int chooseMenuOption(std::vector <std::string> menuOverlay);
	int menuNavigation(int currentLine);
};
