// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include "chapter-10/money.hpp"
#include "chapter-10/dollar.hpp"
#include "chapter-10/franc.hpp"

std::unique_ptr<Money> Money::dollar(int amount) {
  return std::make_unique<Dollar>(amount, "USD");
}

std::unique_ptr<Money> Money::franc(int amount) {
  return std::make_unique<Franc>(amount, "CHF");
}
