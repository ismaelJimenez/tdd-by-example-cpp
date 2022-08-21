// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_12_MONEY_HPP_
#define CHAPTER_12_MONEY_HPP_

#include <iostream>
#include <string>
#include <utility>

#include "chapter-12/expression.hpp"

class Money {
 public:
  Money(int amount, std::string currency)
      : amount_{amount}, currency_{std::move(currency)} {}

  [[nodiscard]] Money times(int multiplier) const {
    return {amount_ * multiplier, currency_};
  }

  [[nodiscard]] Expression plus(const Money& addend) { return {}; }

  [[nodiscard]] constexpr int amount() const { return amount_; }

  [[nodiscard]] std::string currency() const { return currency_; }

  static Money dollar(int amount) { return {amount, "USD"}; }

  static Money franc(int amount) { return {amount, "CHF"}; }

 private:
  const int amount_;
  const std::string currency_;
};

inline constexpr bool operator==(const Money& lhs, const Money& rhs) {
  return (lhs.amount() == rhs.amount()) && (lhs.currency() == rhs.currency());
}

inline std::ostream& operator<<(std::ostream& out, const Money& money) {
  return out << money.amount() << " " << money.currency();
}

#endif  // CHAPTER_12_MONEY_HPP_
