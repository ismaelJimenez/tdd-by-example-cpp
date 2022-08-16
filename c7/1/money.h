#ifndef Money_H
#define Money_H

#include <typeinfo>

class Money
{
public:
  Money(unsigned int amount) : amount{amount} {}

  virtual bool operator==(const Money &rhs) const
  {
    return (this->amount == rhs.amount) && (typeid(*this) == typeid(rhs));
  }

protected:
  unsigned int amount;
};

#endif