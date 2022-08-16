#ifndef Money_H
#define Money_H

class Money {
public:
    Money(unsigned int amount) : amount{amount} {}

protected:
  unsigned int amount;

  friend constexpr bool operator==(const Money &lhs, const Money &rhs);
};

constexpr bool operator==(const Money &lhs, const Money &rhs)
{
  return lhs.amount == rhs.amount;
}

#endif