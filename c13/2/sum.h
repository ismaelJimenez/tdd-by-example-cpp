#ifndef Sum_H
#define Sum_H

#include "expression.h"
#include "money.h"

class Sum : public Expression
{
public:
  Sum(Money augend, Money addend) : augend{std::move(augend)}, addend{std::move(addend)}
  {
  }

  Money augend;
  Money addend;
};

#endif