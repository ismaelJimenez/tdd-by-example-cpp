// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C13_3_MONEY_HPP_
#define C13_3_MONEY_HPP_

#include <memory>
#include <string>
#include <utility>

#include "./expression.hpp"

class Sum;

class Money : public Expression {
 public:
  Money(unsigned int amount, std::string currency)
      : amount{amount}, currency_{std::move(currency)} {}

  virtual bool operator==(const Money &rhs) const {
    return (this->amount == rhs.amount) && (this->currency_ == rhs.currency_);
  }

  Money times(unsigned int multiplier) {
    return Money{amount * multiplier, currency_};
  }

  static Money dollar(unsigned int amount);
  static Money franc(unsigned int amount);

  std::string currency() { return currency_; }

  std::unique_ptr<Money> reduce(const std::string &to) const override {
    return std::make_unique<Money>(*this);
  }

  unsigned int amount;

 protected:
  const std::string currency_;

  friend std::unique_ptr<Sum> operator+(const Money &lhs, const Money &rhs);
};

std::unique_ptr<Sum> operator+(const Money &lhs, const Money &rhs) {
  return std::make_unique<Sum>(lhs, rhs);
}

Money Money::dollar(unsigned int amount) { return Money{amount, "USD"}; }

Money Money::franc(unsigned int amount) { return Money{amount, "CHF"}; }

#endif  // C13_3_MONEY_HPP_
