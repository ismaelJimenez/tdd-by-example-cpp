// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C14_2_SUM_H_
#define C14_2_SUM_H_

#include <memory>
#include <string>
#include <utility>

#include "./expression.hpp"
#include "./money.hpp"

class Sum : public Expression {
 public:
  Sum(Money augend, Money addend)
      : augend{std::move(augend)}, addend{std::move(addend)} {}

  std::unique_ptr<Money> reduce(const Bank& bank,
                                const std::string& to) const override {
    return std::make_unique<Money>(augend.amount + addend.amount, to);
  }

  Money augend;
  Money addend;
};

#endif  // C14_2_SUM_H_
