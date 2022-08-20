// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_7_FRANC_HPP_
#define CHAPTER_7_FRANC_HPP_

#include "chapter-7/money.hpp"

class Franc : public Money {
 public:
  explicit Franc(int amount) { amount_ = amount; }

  [[nodiscard]] Franc times(int multiplier) const {
    return Franc{amount_ * multiplier};
  }
};

#endif  // CHAPTER_7_FRANC_HPP_
