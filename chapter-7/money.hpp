// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_7_MONEY_HPP_
#define CHAPTER_7_MONEY_HPP_

#include <iostream>
#include <typeinfo>

class Money {
 public:
  [[nodiscard]] constexpr int amount() const { return amount_; }

  virtual bool operator==(const Money& rhs) const {
    return (this->amount_ == rhs.amount_) && (typeid(*this) == typeid(rhs));
  }

  virtual ~Money() = default;

 protected:
  int amount_;
};

inline std::ostream& operator<<(std::ostream& out, const Money& money) {
  return out << money.amount();
}

#endif  // CHAPTER_7_MONEY_HPP_
