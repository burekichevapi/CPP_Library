#include "FileManager.h"

#include <iostream>
#include "FileManager.h"

bool FileManager::CanOpenFile(std::fstream &file, std::string fileName)
{
    file.open(fileName, std::ios::in | std::ios::out);
    if (file.fail())
        return false;

    return true;
}

std::string FileManager::ReadFile(std::fstream &file)
{
    std::string line;
    std::string stringBuilder;
    while (file)
    {
        getline(file, line);
        stringBuilder += line;
        std::cout << line << std::endl;
    }

    return stringBuilder;
}

std::string FileManager::ReadFile(std::fstream &file, char delimiter)
{
    std::string line;
    std::string stringBuilder;
    while (file)
    {
        getline(file, line, delimiter);
        stringBuilder += line;
        std::cout << line << std::endl;
    }

    return stringBuilder;
}

std::string FileManager::ReadFile(std::fstream &file, unsigned int numberOfLines)
{
    std::string line;
    std::string stringBuilder;
    unsigned lineNumber = 0;

    while (file)
    {
        if (lineNumber == numberOfLines)
            break;

        getline(file, line);
        stringBuilder += line;
        std::cout << line << std::endl;
        lineNumber++;
    }

    return stringBuilder;
}