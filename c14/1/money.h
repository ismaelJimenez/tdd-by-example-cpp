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

  std::string currency() const { return currency_; };

  std::unique_ptr<Money> reduce(const Bank& bank, const std::string &to) const override
  {
    int rate = ((currency_ == "CHF") && (to == "USD")) ? 2 : 1;
    return std::make_unique<Money>(amount / rate, to);
  }

  unsigned int amount;

protected:  
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

std::ostream& operator << ( std::ostream& outs, const Money& money )
{
  return outs << money.amount << " " << money.currency();
}

#endif