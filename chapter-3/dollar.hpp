// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_3_DOLLAR_HPP_
#define CHAPTER_3_DOLLAR_HPP_

class Dollar {
 public:
  explicit Dollar(int amount) : amount{amount} {}

  [[nodiscard]] Dollar times(int multiplier) const {
    return Dollar{amount * multiplier};
  }

  [[nodiscard]] bool equals(const Dollar& dollar) const {
    return amount == dollar.amount;
  }

  int amount;
};

#endif  // CHAPTER_3_DOLLAR_HPP_
