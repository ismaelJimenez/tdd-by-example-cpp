// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C7_1_FRANC_H_
#define C7_1_FRANC_H_

#include "./money.h"

class Franc : public Money {
 public:
  explicit Franc(unsigned int amount) : Money(amount) {}

  Franc times(unsigned int multiplier) { return {amount * multiplier}; }
};

#endif  // C7_1_FRANC_H_
