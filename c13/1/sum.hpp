// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C13_1_SUM_HPP_
#define C13_1_SUM_HPP_

#include <utility>

#include "./expression.hpp"
#include "./money.hpp"

class Sum : public Expression {
 public:
  Sum(Money augend, Money addend)
      : augend{std::move(augend)}, addend{std::move(addend)} {}

  Money augend;
  Money addend;
};

#endif  // C13_1_SUM_HPP_
