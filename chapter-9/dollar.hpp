// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_9_DOLLAR_HPP_
#define CHAPTER_9_DOLLAR_HPP_

#include <memory>
#include <string>
#include <utility>

#include "chapter-9/money.hpp"

class Dollar : public Money {
 public:
  Dollar(int amount, std::string currency)
      : Money{amount, std::move(currency)} {}

  [[nodiscard]] std::unique_ptr<Money> times(int multiplier) const override;
};

#endif  // CHAPTER_9_DOLLAR_HPP_
