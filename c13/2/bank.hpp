// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C13_2_BANK_HPP_
#define C13_2_BANK_HPP_

#include <string>

#include "./money.hpp"
#include "./sum.hpp"

class Bank {
 public:
  Money reduce(Sum source, std::string to) {
    return {source.augend.amount + source.addend.amount, to};
  }
};

#endif  // C13_2_BANK_HPP_
