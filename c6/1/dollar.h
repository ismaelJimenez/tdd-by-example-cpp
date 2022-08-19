// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C6_1_DOLLAR_H_
#define C6_1_DOLLAR_H_

#include "./money.h"

class Dollar : public Money {
 public:
  explicit Dollar(unsigned int amount) : Money(amount) {}

  Dollar times(unsigned int multiplier) { return {amount * multiplier}; }

 private:
  friend constexpr bool operator==(const Dollar &lhs, const Dollar &rhs);
};

constexpr bool operator==(const Dollar &lhs, const Dollar &rhs) {
  return lhs.amount == rhs.amount;
}

#endif  // C6_1_DOLLAR_H_
