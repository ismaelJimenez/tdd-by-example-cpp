// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include "chapter-13/money.hpp"
#include "chapter-13/sum.hpp"

std::unique_ptr<Expression> Money::plus(const Money& addend) {
  return std::make_unique<Sum>(*this, addend);
}
