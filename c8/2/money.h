#ifndef Money_H
#define Money_H

#include <typeinfo>

class Dollar;

class Money
{
public:
  Money(unsigned int amount) : amount{amount} {}

  virtual bool operator==(const Money &rhs) const
  {
    return (this->amount == rhs.amount) && (typeid(*this) == typeid(rhs));
  }

  static Dollar dollar(unsigned int amount);

protected:
  unsigned int amount;
};

class Dollar : public Money
{
public:
  Dollar(unsigned int amount) : Money(amount) {}

  Money *times(unsigned int multiplier)
  {
    return new Dollar{amount * multiplier};
  }
};

Dollar Money::dollar(unsigned int amount)
{
  return Dollar{amount};
}

#endif