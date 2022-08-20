// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_6_DOLLAR_HPP_
#define CHAPTER_6_DOLLAR_HPP_

#include <iostream>

#include "chapter-6/money.hpp"

class Dollar : public Money {
 public:
  explicit Dollar(int amount) : Money{} { amount_ = amount; }

  [[nodiscard]] Dollar times(int multiplier) const {
    return Dollar{amount_ * multiplier};
  }
};

#endif  // CHAPTER_6_DOLLAR_HPP_
