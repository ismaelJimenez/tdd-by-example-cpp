// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_8_MONEY_HPP_
#define CHAPTER_8_MONEY_HPP_

#include <iostream>
#include <memory>
#include <typeinfo>

class Dollar;
class Franc;

class Money {
 public:
  [[nodiscard]] constexpr int amount() const { return amount_; }

  virtual bool operator==(const Money& rhs) const {
    return (this->amount_ == rhs.amount_) && (typeid(*this) == typeid(rhs));
  }

  [[nodiscard]] virtual std::unique_ptr<Money> times(int /*multiplier*/) const {
    return nullptr;
  }

  virtual ~Money() = default;

  static std::unique_ptr<Money> dollar(int amount);
  static std::unique_ptr<Money> franc(int amount);

 protected:
  int amount_;
};

inline std::ostream& operator<<(std::ostream& out, const Money& money) {
  return out << money.amount();
}

#endif  // CHAPTER_8_MONEY_HPP_
