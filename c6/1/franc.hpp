// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C6_1_FRANC_H_
#define C6_1_FRANC_H_

class Franc {
 public:
  explicit Franc(unsigned int amount) : amount{amount} {}

  Franc times(unsigned int multiplier) { return Franc{amount * multiplier}; }

 private:
  unsigned int amount;

  friend constexpr bool operator==(const Franc &lhs, const Franc &rhs);
};

constexpr bool operator==(const Franc &lhs, const Franc &rhs) {
  return lhs.amount == rhs.amount;
}

#endif  // C6_1_FRANC_H_
