// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_05_DOLLAR_HPP_
#define CHAPTER_05_DOLLAR_HPP_

#include <iostream>

class Dollar {
 public:
  explicit Dollar(int amount) : amount_{amount} {}

  [[nodiscard]] Dollar times(int multiplier) const {
    return Dollar{amount_ * multiplier};
  }

  [[nodiscard]] constexpr int amount() const { return amount_; }

 private:
  const int amount_;
};

inline constexpr bool operator==(const Dollar& lhs, const Dollar& rhs) {
  return lhs.amount() == rhs.amount();
}

inline std::ostream& operator<<(std::ostream& out, const Dollar& dollar) {
  return out << dollar.amount();
}

#endif  // CHAPTER_05_DOLLAR_HPP_
