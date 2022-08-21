// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include "chapter-9/franc.hpp"
#include "chapter-9/money.hpp"

[[nodiscard]] std::unique_ptr<Money> Franc::times(int multiplier) const {
  return Money::franc(amount_ * multiplier);
}
