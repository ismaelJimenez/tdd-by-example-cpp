// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_08_FRANC_HPP_
#define CHAPTER_08_FRANC_HPP_

#include <memory>

#include "chapter-08/money.hpp"

class Franc : public Money {
 public:
  explicit Franc(int amount) { amount_ = amount; }

  [[nodiscard]] std::unique_ptr<Money> times(int multiplier) const override {
    return std::make_unique<Franc>(amount_ * multiplier);
  }
};

#endif  // CHAPTER_08_FRANC_HPP_
