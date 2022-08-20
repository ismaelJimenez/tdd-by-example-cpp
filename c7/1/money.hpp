// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C7_1_MONEY_HPP_
#define C7_1_MONEY_HPP_

#include <typeinfo>

class Money {
 public:
  explicit Money(unsigned int amount) : amount{amount} {}

  virtual bool operator==(const Money &rhs) const {
    return (this->amount == rhs.amount) && (typeid(*this) == typeid(rhs));
  }

 protected:
  unsigned int amount;
};

#endif  // C7_1_MONEY_HPP_
