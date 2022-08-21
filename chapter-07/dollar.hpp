// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_07_DOLLAR_HPP_
#define CHAPTER_07_DOLLAR_HPP_

#include "chapter-07/money.hpp"

class Dollar : public Money {
 public:
  explicit Dollar(int amount) { amount_ = amount; }

  [[nodiscard]] Dollar times(int multiplier) const {
    return Dollar{amount_ * multiplier};
  }
};

#endif  // CHAPTER_07_DOLLAR_HPP_
