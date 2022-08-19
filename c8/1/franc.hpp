// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C8_1_FRANC_H_
#define C8_1_FRANC_H_

#include "./money.hpp"

class Franc : public Money {
 public:
  explicit Franc(unsigned int amount) : Money(amount) {}

  Money* times(unsigned int multiplier) {
    return new Franc{amount * multiplier};
  }
};

#endif  // C8_1_FRANC_H_