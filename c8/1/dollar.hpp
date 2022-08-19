// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C8_1_DOLLAR_H_
#define C8_1_DOLLAR_H_

#include "./money.hpp"

class Dollar : public Money {
 public:
  explicit Dollar(unsigned int amount) : Money(amount) {}

  Money* times(unsigned int multiplier) {
    return new Dollar{amount * multiplier};
  }
};

#endif  // C8_1_DOLLAR_H_
