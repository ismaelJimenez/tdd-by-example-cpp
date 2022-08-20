// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C6_2_FRANC_HPP_
#define C6_2_FRANC_HPP_

#include "./money.hpp"

class Franc : public Money {
 public:
  explicit Franc(unsigned int amount) : Money(amount) {}

  Franc times(unsigned int multiplier) { return Franc{amount * multiplier}; }
};

#endif  // C6_2_FRANC_HPP_
