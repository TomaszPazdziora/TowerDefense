#include "Vector.h"

void Vector::writeVector(std::vector <std::string> Vec)
{
    for (int i = 0; i < Vec.size(); i++)
    {
        std::cout << Vec[i] << std::endl;
    }
}

std::vector <std::string> Vector::loadWholeFile(std::string pathToFile, std::string readingFile)
{
    std::vector <std::string> wholeFile;
    std::string oneStringBuffer;
    std::fstream myFile;

    myFile.open(pathToFile + "\\" + readingFile + ".txt", std::ios::in);

    if (myFile.is_open())
    {
        while (getline(myFile, oneStringBuffer))
        {
            wholeFile.push_back(oneStringBuffer);
        }
    }

    myFile.close();
    return wholeFile;
}

std::vector <Point> Vector::getPointVector(std::vector <std::string> dataVector, std::string purposeChars)
{
    std::vector <Point> pointVector;

    for (int x = 0; x < dataVector.size(); x++)
    {
        for (int y = 0; y < dataVector[x].size(); y++)
        {
            for (int i = 0; i < purposeChars.size(); i++)
            {
                if (dataVector[x][y] == purposeChars[i])
                {
                    pointVector.push_back(Point(x, y));
                }
            }
        }
    }

    return pointVector;
}