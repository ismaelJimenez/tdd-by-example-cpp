// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_8_DOLLAR_HPP_
#define CHAPTER_8_DOLLAR_HPP_

#include <memory>

#include "chapter-8/money.hpp"

class Dollar : public Money {
 public:
  explicit Dollar(int amount) { amount_ = amount; }

  [[nodiscard]] std::unique_ptr<Money> times(int multiplier) const override {
    return std::make_unique<Dollar>(amount_ * multiplier);
  }
};

#endif  // CHAPTER_8_DOLLAR_HPP_
