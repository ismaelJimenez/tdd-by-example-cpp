#ifndef Franc_H
#define Franc_H

#include "money.h"

class Franc : public Money {
 public:
  Franc(unsigned int amount) : Money(amount) {}

  Money* times(unsigned int multiplier) {
    return new Franc{amount * multiplier};
  }
};

#endif