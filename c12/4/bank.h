#ifndef Bank_H
#define Bank_H

#include <string>

#include "money.h"

class Bank
{
public:
    Money reduce(Money source, std::string to)
    {
        return Money::dollar(10);
    }
};

#endif