// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_10_DOLLAR_HPP_
#define CHAPTER_10_DOLLAR_HPP_

#include <string>
#include <utility>

#include "chapter-10/money.hpp"

class Dollar : public Money {
 public:
  Dollar(int amount, std::string currency)
      : Money{amount, std::move(currency)} {}
};

#endif  // CHAPTER_10_DOLLAR_HPP_
