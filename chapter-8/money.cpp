// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include "chapter-8/money.hpp"
#include "chapter-8/dollar.hpp"
#include "chapter-8/franc.hpp"

std::unique_ptr<Money> Money::dollar(int amount) {
  return std::make_unique<Dollar>(amount);
}
std::unique_ptr<Money> Money::franc(int amount) {
  return std::make_unique<Franc>(amount);
}
