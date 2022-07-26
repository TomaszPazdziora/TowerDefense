#include "MainLoop.h"

void MainLoop::run()
{
    Map newMap(MainLoop::menu());
    MainLoop::presentMap(newMap);
}


std::string MainLoop::menu()
{
    std::vector <std::string> mainMenuOverlay = Vector::loadWholeFile("MainMenu", "MainMenu");
    std::vector <std::string> mapMenuOverlay = Vector::loadWholeFile("MapMenu", "MapMenu");

    Menu mainMenu(mainMenuOverlay);
    Menu mapMenu(mapMenuOverlay);

    switch (mainMenu.chooseMenuOption(mainMenuOverlay))
    {
    case 1:
        switch (mapMenu.chooseMenuOption(mapMenuOverlay))
        {
        case 1:
            return ("SnakeTrail");
        case 2:
            return ("DarkMaze");
        case 3:
            return ("RoundSentry");
        }
    case 2:
        return ("New Game");
    case 3:
        return ("Exit");
    }

    return ("Exit");
}

Wave MainLoop::updatePossitions(Map map, int currentWaveNumber)
{
    for (int i = 0; i < map.waveVector[currentWaveNumber].attackerVector.size(); i++)
    {

        if (map.waveVector[currentWaveNumber].attackerVector[i].delay >= 0)
        {
            --map.waveVector[currentWaveNumber].attackerVector[i].delay;
        }

        else
        {
            ++map.waveVector[currentWaveNumber].attackerVector[i].pathIndex;
        }

        if (map.waveVector[currentWaveNumber].attackerVector[i].delay == 0)
        {
            map.waveVector[currentWaveNumber].attackerVector[i].pathIndex = 0;
        }

    }
    return map.waveVector[currentWaveNumber];
}

void MainLoop::presentMap(Map newMap)
{
    // loop for every wave

    for (int i = 0; i < newMap.waveVector.size(); i++)
    {
        int attVecSize = int(newMap.waveVector[i].attackerVector.size()) - 1;

        // while last attacker location != last path index

        while (newMap.waveVector[i].attackerVector[attVecSize].pathIndex < newMap.pathVectorLastIndex + 1)
        {
            newMap.waveVector[i] = MainLoop::updatePossitions(newMap, 0);
            Point attackerLocation = Point(0, 0);

            // loop for every attacker in current wave

            for (int j = 0; j < newMap.waveVector[i].attackerVector.size(); j++)
            {
                newMap.mapOverlay = newMap.setFirstAndLastPathChar();

                if (newMap.waveVector[i].attackerVector[j].pathIndex < newMap.pathVector.size())
                {
                    // write current attacker

                    attackerLocation = getAttackerLocation(newMap, i, j, 0);

                    newMap.mapOverlay[attackerLocation.y][attackerLocation.x] = '0' + newMap.waveVector[i].attackerVector[j].power;

                    // clean cell before

                    if (newMap.waveVector[i].attackerVector[j].pathIndex > 0)
                    {
                        attackerLocation = getAttackerLocation(newMap, i, j, -1);
                        newMap.mapOverlay[attackerLocation.y][attackerLocation.x] = ' ';
                    }
                }
            }

            newMap.mapOverlay = newMap.setFirstAndLastPathChar();

            system("cls");
            Vector::writeVector(newMap.mapOverlay);
            Sleep(40);
        }
    }
}

Point MainLoop::getAttackerLocation(Map map, int waveVecCounter, int attackerVecCounter, int shift)
{
    Point attackerLocation = Point(0, 0);

    attackerLocation.x = map.pathVector[map.waveVector[waveVecCounter].attackerVector[attackerVecCounter].pathIndex + shift].x;
    attackerLocation.y = map.pathVector[map.waveVector[waveVecCounter].attackerVector[attackerVecCounter].pathIndex + shift].y;

    return attackerLocation;
}