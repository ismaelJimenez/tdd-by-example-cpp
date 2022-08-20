// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C7_1_FRANC_HPP_
#define C7_1_FRANC_HPP_

#include "./money.hpp"

class Franc : public Money {
 public:
  explicit Franc(unsigned int amount) : Money(amount) {}

  Franc times(unsigned int multiplier) { return Franc{amount * multiplier}; }
};

#endif  // C7_1_FRANC_HPP_
