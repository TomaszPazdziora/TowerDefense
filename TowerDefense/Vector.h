#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Point.h"

namespace Vector
{
    void writeVector(std::vector <std::string> Vec);
    std::vector <std::string> loadWholeFile(std::string fileName, std::string fileFormat);
    std::vector <Point> getPointVector(std::vector <std::string> dataVector, std::string purposeChars);
};