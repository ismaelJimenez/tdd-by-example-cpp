#ifndef Money_H
#define Money_H

#include <typeinfo>
#include <string>

class Dollar;
class Franc;

class Money
{
public:
  Money(unsigned int amount, std::string currency) : amount{amount}, currency_{currency} {}

  virtual bool operator==(const Money &rhs) const
  {
    return (this->amount == rhs.amount) && (this->currency_ == rhs.currency_);
  }

  Money *times(unsigned int multiplier)
  {
    return new Money{amount * multiplier, currency_};
  }

  static Money *dollar(unsigned int amount);
  static Money *franc(unsigned int amount);

  std::string currency() { return currency_; };

protected:
  unsigned int amount;
  const std::string currency_;

  friend Money operator+(const Money &lhs, const Money &rhs);
};

Money operator+(const Money &lhs, const Money &rhs)
{
  return {lhs.amount + rhs.amount, lhs.currency_};
}

Money *Money::dollar(unsigned int amount)
{
  return new Money{amount, "USD"};
}

Money *Money::franc(unsigned int amount)
{
  return new Money{amount, "CHF"};
}

#endif