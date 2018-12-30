
#include <iostream>
#include <vector>
#include "console_management.h"

void clear_console()
{
    std::cin.clear();
    std::cin.ignore(256, '\n');
}

void validate_string_input(std::string &s)
{
    getline(std::cin, s);

    while (s.empty())
        getline(std::cin, s);
}

void validate_number_input(double &num)
{
    while (!(std::cin >> num))
        clear_console();
}

void validate_number_input(int &num)
{
    while (!(std::cin >> num))
        clear_console();
}

void validate_number_input(float &num)
{
    while (!(std::cin >> num))
        clear_console();
}

template <class T>
void validate_number_input(T &num)
{
    while (!(std::cin >> num))
        clear_console();
}