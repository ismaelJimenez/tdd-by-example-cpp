// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include "c14/2/money.hpp"

#include <iostream>

#include "./sum.hpp"

std::unique_ptr<Sum> operator+(const Money &lhs, const Money &rhs) {
  return std::make_unique<Sum>(lhs, rhs);
}

Money Money::dollar(unsigned int amount) { return Money{amount, "USD"}; }

Money Money::franc(unsigned int amount) { return Money{amount, "CHF"}; }

std::ostream &operator<<(std::ostream &outs, const Money &money) {
  return outs << money.amount << " " << money.currency();
}
