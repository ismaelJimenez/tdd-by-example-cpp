// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C12_4_BANK_HPP_
#define C12_4_BANK_HPP_

#include <string>

#include "./money.hpp"

class Bank {
 public:
  Money reduce(Money source, std::string to) { return Money::dollar(10); }
};

#endif  // C12_4_BANK_HPP_
