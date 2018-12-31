//
// Created by amer on 12/31/18.
//

#ifndef AMER_DELIC_NOSTOREDVALUESEXCEPTION_H
#define AMER_DELIC_NOSTOREDVALUESEXCEPTION_H


#include <exception>

class NoStoredValuesException: public std::exception
{
public:
    const char * what () const throw () override
    {
        return "No stored values.";
    }
};


#endif //AMER_DELIC_NOSTOREDVALUESEXCEPTION_H
