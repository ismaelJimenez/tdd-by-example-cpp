#ifndef Franc_H
#define Franc_H

#include "money.h"

class Franc: public Money
{
public:
  Franc(unsigned int amount) : Money(amount) {}

  Franc times(unsigned int multiplier)
  {
    return {amount * multiplier};
  }
};

#endif