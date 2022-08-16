#ifndef Money_H
#define Money_H

#include <typeinfo>

class Dollar;
class Franc;

class Money
{
public:
  Money(unsigned int amount) : amount{amount} {}

  virtual bool operator==(const Money &rhs) const
  {
    return (this->amount == rhs.amount) && (typeid(*this) == typeid(rhs));
  }

  virtual Money *times(unsigned int multiplier) { return nullptr; }

  static Dollar *dollar(unsigned int amount);
  static Franc *franc(unsigned int amount);

protected:
  unsigned int amount;
};

class Dollar : public Money
{
public:
  Dollar(unsigned int amount) : Money(amount) {}

  Money *times(unsigned int multiplier) override
  {
    return new Dollar{amount * multiplier};
  }
};

class Franc: public Money
{
public:
  Franc(unsigned int amount) : Money(amount) {}

  Money* times(unsigned int multiplier)
  {
    return new Franc{amount * multiplier};
  }
};

Dollar *Money::dollar(unsigned int amount)
{
  return new Dollar{amount};
}

Franc *Money::franc(unsigned int amount)
{
  return new Franc{amount};
}

#endif