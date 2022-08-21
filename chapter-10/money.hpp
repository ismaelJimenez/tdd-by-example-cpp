// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_10_MONEY_HPP_
#define CHAPTER_10_MONEY_HPP_

#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Dollar;
class Franc;

class Money {
 public:
  Money(int amount, std::string currency)
      : amount_{amount}, currency_{std::move(currency)} {}

  virtual ~Money() = default;

  [[nodiscard]] Money times(int multiplier) const {
    return {amount_ * multiplier, currency_};
  }

  [[nodiscard]] constexpr int amount() const { return amount_; }

  [[nodiscard]] std::string currency() const { return currency_; }

  virtual bool operator==(const Money& rhs) const {
    return (this->amount_ == rhs.amount_) && (currency_ == rhs.currency_);
  }

  static std::unique_ptr<Money> dollar(int amount);

  static std::unique_ptr<Money> franc(int amount);

 private:
  const int amount_;
  const std::string currency_;
};

inline std::ostream& operator<<(std::ostream& out, const Money& money) {
  return out << money.amount() << " " << money.currency();
}

#endif  // CHAPTER_10_MONEY_HPP_
