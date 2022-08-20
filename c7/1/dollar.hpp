// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C7_1_DOLLAR_HPP_
#define C7_1_DOLLAR_HPP_

#include "./money.hpp"

class Dollar : public Money {
 public:
  explicit Dollar(unsigned int amount) : Money(amount) {}

  Dollar times(unsigned int multiplier) { return Dollar{amount * multiplier}; }
};

#endif  // C7_1_DOLLAR_HPP_
