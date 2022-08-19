#include <iostream>

#include "money.h"
#include "sum.h"

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

std::ostream &operator<<(std::ostream &outs, const Money &money)
{
  return outs << money.amount << " " << money.currency();
}