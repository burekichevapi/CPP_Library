#ifndef AMER_DELIC_CONSOLE_MANAGEMENT_H
#define AMER_DELIC_CONSOLE_MANAGEMENT_H


#include <string>

void clear_console();

void validate_string_input(std::string &s);

void validate_number_input(double &num);

void validate_number_input(int &num);

void validate_number_input(float &num);

template <class T>
void validate_number_input(T &num);


#endif //AMER_DELIC_CONSOLE_MANAGEMENT_H
