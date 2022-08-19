// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C6_2_MONEY_H_
#define C6_2_MONEY_H_

class Money {
 public:
  explicit Money(unsigned int amount) : amount{amount} {}

 protected:
  unsigned int amount;

  friend constexpr bool operator==(const Money &lhs, const Money &rhs);
};

constexpr bool operator==(const Money &lhs, const Money &rhs) {
  return lhs.amount == rhs.amount;
}

#endif  // C6_2_MONEY_H_
