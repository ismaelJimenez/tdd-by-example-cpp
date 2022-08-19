#ifndef Money_H
#define Money_H

#include <memory>
#include <string>

#include "expression.h"

class Sum;

class Money : public Expression {
 public:
  Money(unsigned int amount, std::string currency)
      : amount{amount}, currency_{currency} {}

  virtual bool operator==(const Money &rhs) const {
    return (this->amount == rhs.amount) && (this->currency_ == rhs.currency_);
  }

  Money times(unsigned int multiplier) {
    return Money{amount * multiplier, currency_};
  }

  static Money dollar(unsigned int amount);
  static Money franc(unsigned int amount);

  std::string currency() const { return currency_; };

  std::unique_ptr<Money> reduce(const Bank &bank,
                                const std::string &to) const override {
    int rate = ((currency_ == "CHF") && (to == "USD")) ? 2 : 1;
    return std::make_unique<Money>(amount / rate, to);
  }

  unsigned int amount;

 protected:
  const std::string currency_;

  friend std::unique_ptr<Sum> operator+(const Money &lhs, const Money &rhs);
  friend std::ostream &operator<<(std::ostream &os, const Money &money);
};

std::ostream &operator<<(std::ostream &outs, const Money &money);

#endif