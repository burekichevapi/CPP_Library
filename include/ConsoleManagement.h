#ifndef AMER_DELIC_CONSOLE_MANAGEMENT_H
#define AMER_DELIC_CONSOLE_MANAGEMENT_H


#include <string>

void ClearConsole();

void ValidateStringInput(std::string &s);

void ValidateNumberInput(double &num);

void ValidateNumberInput(int &num);

void ValidateNumberInput(float &num);

template <class T>
void ValidateNumberInput(T &num);

#endif //AMER_DELIC_CONSOLE_MANAGEMENT_H
