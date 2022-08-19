// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C12_3_MONEY_H_
#define C12_3_MONEY_H_

#include <string>
#include <typeinfo>

class Dollar;
class Franc;

class Money {
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

 protected:
  unsigned int amount;
  const std::string currency_;

  friend Money operator+(const Money &lhs, const Money &rhs);
};

Money operator+(const Money &lhs, const Money &rhs) {
  return {lhs.amount + rhs.amount, lhs.currency_};
}

Money Money::dollar(unsigned int amount) { return Money{amount, "USD"}; }

Money Money::franc(unsigned int amount) { return Money{amount, "CHF"}; }

#endif  // C12_3_MONEY_H_