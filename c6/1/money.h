// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C6_1_MONEY_H_
#define C6_1_MONEY_H_

class Money {
 public:
  explicit Money(unsigned int amount) : amount{amount} {}

 protected:
  unsigned int amount;
};

#endif  // C6_1_MONEY_H_
