// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C4_1_DOLLAR_HPP_
#define C4_1_DOLLAR_HPP_

class Dollar {
 public:
  explicit Dollar(unsigned int amount) : amount{amount} {}

  Dollar times(unsigned int multiplier) { return Dollar{amount * multiplier}; }

 private:
  unsigned int amount;

  friend constexpr bool operator==(const Dollar &lhs, const Dollar &rhs);
};

constexpr bool operator==(const Dollar &lhs, const Dollar &rhs) {
  return lhs.amount == rhs.amount;
}

#endif  // C4_1_DOLLAR_HPP_
