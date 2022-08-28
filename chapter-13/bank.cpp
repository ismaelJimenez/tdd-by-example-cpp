// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include "chapter-13/bank.hpp"
#include "chapter-13/expression.hpp"
#include "chapter-13/money.hpp"
#include "chapter-13/sum.hpp"

Money Bank::reduce(const Expression& source, const std::string& to) {
  return source.reduce(to);
}
