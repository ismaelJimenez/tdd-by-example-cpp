// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C8_2_MONEY_HPP_
#define C8_2_MONEY_HPP_

#include <typeinfo>

class Dollar;

class Money {
 public:
  explicit Money(unsigned int amount) : amount{amount} {}

  virtual bool operator==(const Money &rhs) const {
    return (this->amount == rhs.amount) && (typeid(*this) == typeid(rhs));
  }

  static Dollar dollar(unsigned int amount);

 protected:
  unsigned int amount;
};

class Dollar : public Money {
 public:
  explicit Dollar(unsigned int amount) : Money(amount) {}

  Money *times(unsigned int multiplier) {
    return new Dollar{amount * multiplier};
  }
};

Dollar Money::dollar(unsigned int amount) { return Dollar{amount}; }

#endif  // C8_2_MONEY_HPP_
