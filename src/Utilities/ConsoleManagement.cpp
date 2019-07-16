
#include <iostream>
#include "ConsoleManagement.h"

void ClearConsole()
{
    std::cin.clear();
    std::cin.ignore(256, '\n');
}

void ValidateStringInput(std::string &s)
{
    getline(std::cin, s);

    while (s.empty())
        getline(std::cin, s);
}

void ValidateNumberInput(double &num)
{
    while (!(std::cin >> num))
        ClearConsole();
}

void ValidateNumberInput(int &num)
{
    while (!(std::cin >> num))
        ClearConsole();
}

void ValidateNumberInput(float &num)
{
    while (!(std::cin >> num))
        ClearConsole();
}

template <class T>
void ValidateNumberInput(T &num)
{
    while (!(std::cin >> num))
        ClearConsole();
}