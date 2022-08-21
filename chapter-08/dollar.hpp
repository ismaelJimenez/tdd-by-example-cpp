// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_08_DOLLAR_HPP_
#define CHAPTER_08_DOLLAR_HPP_

#include <memory>

#include "chapter-08/money.hpp"

class Dollar : public Money {
 public:
  explicit Dollar(int amount) { amount_ = amount; }

  [[nodiscard]] std::unique_ptr<Money> times(int multiplier) const override {
    return std::make_unique<Dollar>(amount_ * multiplier);
  }
};

#endif  // CHAPTER_08_DOLLAR_HPP_
