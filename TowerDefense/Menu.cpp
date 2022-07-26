#include "Menu.h"

int Menu::menuNavigation(int currentLine)
{
    char key;
    key = _getch();

    if (key == ' ')
    {
        return currentLine + choosen;
    }
    else if ((key == 's' || key == 'S') && currentLine < lastOptionLocation)
    {
        currentLine++;
    }
    else if ((key == 'w' || key == 'W') && currentLine > firstOptionLocation)
    {
        currentLine--;
    }

    return currentLine;
}

int Menu::getArrowLocation(std::vector <std::string> menuOverlay)
{
    for (int i = 0; i < menuOverlay.size(); i++)
    {
        for (int j = 0; j < menuOverlay[i].size(); j++)
        {
            if (menuOverlay[i][j] == '!')
            {
                return j;
            }
        }
    }

    return 0;
}

int Menu::getFirstOptionLocation(std::vector <std::string> menuOverlay)
{
    for (int i = 0; i < menuOverlay.size(); i++)
    {
        for (int j = 0; j < menuOverlay[i].size(); j++)
        {
            if (menuOverlay[i][j] == '!')
            {
                return i;
            }
        }
    }

    return 0;
}

int Menu::getLastOptionLocation(std::vector <std::string> menuOverlay)
{
    for (int i = 0; i < menuOverlay.size(); i++)
    {
        for (int j = 0; j < menuOverlay[i].size(); j++)
        {
            if (menuOverlay[i][j] == '@')
            {
                return i;
            }
        }
    }

    return 0;
}

int Menu::chooseMenuOption(std::vector <std::string> menuOverlay)
{

    int line = getFirstOptionLocation(menuOverlay);

    for (int i = firstOptionLocation + 1; i <= lastOptionLocation; i++)
    {
        if (true)
        {
            menuOverlay[i][arrowLocation] = ' ';
        }
    }

    menuOverlay[firstOptionLocation][arrowLocation] = '>';
    Vector::writeVector(menuOverlay);

    while (1)
    {
        line = Menu::menuNavigation(line);

        if (line >= firstOptionLocation && line <= lastOptionLocation)
        {

            for (int i = firstOptionLocation; i <= lastOptionLocation; i++)
            {
                if (i != line)
                {
                    menuOverlay[i][arrowLocation] = ' ';
                }
            }

            menuOverlay[line][arrowLocation] = '>';
            system("cls");

            Vector::writeVector(menuOverlay);
            Sleep(50);
        }

        else if (line > choosen)
        {
            system("cls");
            return line - choosen - (firstOptionLocation - 1);
        }
    }
}