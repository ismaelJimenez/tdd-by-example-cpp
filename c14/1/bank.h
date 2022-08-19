#ifndef Bank_H
#define Bank_H

#include "money.h"
#include "sum.h"

#include <memory>
#include <stdexcept>
#include <string>
#include <typeinfo>

class Bank {
 public:
  Money reduce(const Expression& source, const std::string& to) const {
    return *source.reduce(*this, to);
  }
};

#endif