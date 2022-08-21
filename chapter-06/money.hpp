// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_06_MONEY_HPP_
#define CHAPTER_06_MONEY_HPP_

#include <iostream>

class Money {
 public:
  [[nodiscard]] constexpr int amount() const { return amount_; }

 protected:
  int amount_;
};

constexpr bool operator==(const Money& lhs, const Money& rhs) {
  return lhs.amount() == rhs.amount();
}

inline std::ostream& operator<<(std::ostream& out, const Money& money) {
  return out << money.amount();
}

#endif  // CHAPTER_06_MONEY_HPP_
