// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include "chapter-12/bank.hpp"
#include "chapter-12/expression.hpp"
#include "chapter-12/money.hpp"

Money Bank::reduce(const Expression& source, const std::string& to) {
  return Money::dollar(10);
}
