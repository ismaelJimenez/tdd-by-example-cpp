// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_13_SUM_HPP_
#define CHAPTER_13_SUM_HPP_

#include <string>
#include <utility>

#include "chapter-13/expression.hpp"
#include "chapter-13/money.hpp"

class Sum : public Expression {
 public:
  Sum(Money augend, Money addend)
      : augend{std::move(augend)}, addend{std::move(addend)} {}

  [[nodiscard]] Money reduce(const std::string& to) const override {
    auto amount = augend.amount() + addend.amount();

    return Money(amount, to);
  }

  Money augend;
  Money addend;
};

#endif  // CHAPTER_13_SUM_HPP_
