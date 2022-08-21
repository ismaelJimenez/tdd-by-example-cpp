// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include "chapter-9/dollar.hpp"
#include "chapter-9/money.hpp"

[[nodiscard]] std::unique_ptr<Money> Dollar::times(int multiplier) const {
  return Money::dollar(amount_ * multiplier);
}
