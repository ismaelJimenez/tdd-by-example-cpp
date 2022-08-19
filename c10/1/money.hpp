// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C10_1_MONEY_H_
#define C10_1_MONEY_H_

#include <string>
#include <typeinfo>

class Dollar;
class Franc;

class Money {
 public:
  Money(unsigned int amount, std::string currency)
      : amount{amount}, currency_{std::move(currency)} {}

  virtual bool operator==(const Money &rhs) const {
    return (this->amount == rhs.amount) && (this->currency_ == rhs.currency_);
  }

  Money *times(unsigned int multiplier) {
    return new Money{amount * multiplier, currency_};
  }

  static Dollar *dollar(unsigned int amount);
  static Franc *franc(unsigned int amount);

  std::string currency() { return currency_; }

 protected:
  unsigned int amount;
  const std::string currency_;
};

class Dollar : public Money {
 public:
  Dollar(unsigned int amount, std::string currency) : Money(amount, currency) {}
};

class Franc : public Money {
 public:
  Franc(unsigned int amount, std::string currency) : Money(amount, currency) {}
};

Dollar *Money::dollar(unsigned int amount) { return new Dollar{amount, "USD"}; }

Franc *Money::franc(unsigned int amount) { return new Franc{amount, "CHF"}; }

#endif  // C10_1_MONEY_H_