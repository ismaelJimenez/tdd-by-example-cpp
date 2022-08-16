#ifndef Dollar_H
#define Dollar_h

#include "money.h"

class Dollar : public Money
{
public:
  Dollar(unsigned int amount) : Money(amount) {}

  Dollar times(unsigned int multiplier)
  {
    return {amount * multiplier};
  }

private:
  friend constexpr bool operator==(const Dollar &lhs, const Dollar &rhs);
};

constexpr bool operator==(const Dollar &lhs, const Dollar &rhs)
{
  return lhs.amount == rhs.amount;
}

#endif