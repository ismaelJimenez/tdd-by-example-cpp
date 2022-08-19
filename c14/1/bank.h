#ifndef Bank_H
#define Bank_H

#include <memory>
#include <string>
#include <typeinfo>
#include <stdexcept>

#include "money.h"
#include "sum.h"

class Bank
{
public:
    Money reduce(const Expression& source, const std::string& to) const
    {
        return *source.reduce(*this, to);
    }
};

#endif