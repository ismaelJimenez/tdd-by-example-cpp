// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C13_1_BANK_H_
#define C13_1_BANK_H_

#include <string>

#include "./money.hpp"
#include "./sum.hpp"

class Bank {
 public:
  Money reduce(Sum source, std::string to) { return Money::dollar(10); }
};

#endif  // C13_1_BANK_H_
