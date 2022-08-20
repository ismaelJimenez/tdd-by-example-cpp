// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_5_FRANC_HPP_
#define CHAPTER_5_FRANC_HPP_

#include <iostream>

class Franc {
 public:
  explicit Franc(int amount) : amount_{amount} {}

  [[nodiscard]] Franc times(int multiplier) const {
    return Franc{amount_ * multiplier};
  }

  [[nodiscard]] constexpr int amount() const { return amount_; }

 private:
  const int amount_;
};

constexpr bool operator==(const Franc& lhs, const Franc& rhs) {
  return lhs.amount() == rhs.amount();
}

inline std::ostream& operator<<(std::ostream& out, const Franc& franc) {
  return out << franc.amount();
}

#endif  // CHAPTER_5_FRANC_HPP_
