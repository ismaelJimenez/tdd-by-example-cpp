// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C3_1_DOLLAR_H_
#define C3_1_DOLLAR_H_

class Dollar {
 public:
  explicit Dollar(unsigned int amount) : amount{amount} {}

  Dollar times(unsigned int multiplier) { return Dollar{amount * multiplier}; }

  unsigned int amount;
};

constexpr bool operator==(const Dollar& lhs, const Dollar& rhs) { return true; }

#endif  // C3_1_DOLLAR_H_
