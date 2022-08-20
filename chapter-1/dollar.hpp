// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_1_DOLLAR_HPP_
#define CHAPTER_1_DOLLAR_HPP_

class Dollar {
 public:
  explicit Dollar(int amount) : amount{amount} {}

  void times(int multiplier) { amount *= multiplier; }

  int amount;
};

#endif  // CHAPTER_1_DOLLAR_HPP_
