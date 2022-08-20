// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C9_1_MONEY_HPP_
#define C9_1_MONEY_HPP_

#include <string>
#include <typeinfo>

class Dollar;
class Franc;

class Money {
 public:
  explicit Money(unsigned int amount) : amount{amount} {}

  virtual bool operator==(const Money &rhs) const {
    return (this->amount == rhs.amount) && (typeid(*this) == typeid(rhs));
  }

  virtual Money *times(unsigned int multiplier) { return nullptr; }

  static Dollar *dollar(unsigned int amount);
  static Franc *franc(unsigned int amount);

  virtual std::string currency() { return {}; }

 protected:
  unsigned int amount;
};

class Dollar : public Money {
 public:
  explicit Dollar(unsigned int amount) : Money(amount), currency_{"USD"} {}

  Money *times(unsigned int multiplier) override {
    return new Dollar{amount * multiplier};
  }

  std::string currency() override { return currency_; }

 private:
  const std::string currency_;
};

class Franc : public Money {
 public:
  explicit Franc(unsigned int amount) : Money(amount), currency_{"CHF"} {}

  Money *times(unsigned int multiplier) {
    return new Franc{amount * multiplier};
  }

  std::string currency() override { return currency_; };

 private:
  const std::string currency_;
};

Dollar *Money::dollar(unsigned int amount) { return new Dollar{amount}; }

Franc *Money::franc(unsigned int amount) { return new Franc{amount}; }

#endif  // C9_1_MONEY_HPP_
