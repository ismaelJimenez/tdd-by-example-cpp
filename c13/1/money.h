#ifndef Money_H
#define Money_H

#include <string>
#include <memory>

#include "expression.h"

class Sum;

class Money : public Expression
{
public:
  Money(unsigned int amount, std::string currency) : amount{amount}, currency_{currency} {}

  virtual bool operator==(const Money &rhs) const
  {
    return (this->amount == rhs.amount) && (this->currency_ == rhs.currency_);
  }

  Money times(unsigned int multiplier)
  {
    return Money{amount * multiplier, currency_};
  }

  static Money dollar(unsigned int amount);
  static Money franc(unsigned int amount);

  std::string currency() { return currency_; };

protected:
  unsigned int amount;
  const std::string currency_;

  friend std::unique_ptr<Sum> operator+(const Money &lhs, const Money &rhs);
};

std::unique_ptr<Sum> operator+(const Money &lhs, const Money &rhs)
{
  return std::make_unique<Sum>(lhs, rhs);
}

Money Money::dollar(unsigned int amount)
{
  return Money{amount, "USD"};
}

Money Money::franc(unsigned int amount)
{
  return Money{amount, "CHF"};
}

#endif