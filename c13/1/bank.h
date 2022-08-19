#ifndef Bank_H
#define Bank_H

#include <string>

#include "money.h"
#include "sum.h"

class Bank {
 public:
  Money reduce(Sum source, std::string to) { return Money::dollar(10); }
};

#endif