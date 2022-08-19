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

  std::unique_ptr<Money> reduce(const Bank& bank, const std::string &to) const override
  {
    return std::make_unique<Money>(augend.amount + addend.amount, to);
  }

  Money augend;
  Money addend;
};

#endif