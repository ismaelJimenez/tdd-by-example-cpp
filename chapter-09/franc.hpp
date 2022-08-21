// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_09_FRANC_HPP_
#define CHAPTER_09_FRANC_HPP_

#include <memory>
#include <string>
#include <utility>

#include "chapter-09/money.hpp"

class Franc : public Money {
 public:
  Franc(int amount, std::string currency)
      : Money{amount, std::move(currency)} {}

  [[nodiscard]] std::unique_ptr<Money> times(int multiplier) const override;
};

#endif  // CHAPTER_09_FRANC_HPP_
