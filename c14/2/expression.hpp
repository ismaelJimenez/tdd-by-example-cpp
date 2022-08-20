// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C14_2_EXPRESSION_HPP_
#define C14_2_EXPRESSION_HPP_

#include <memory>
#include <string>

class Money;
class Bank;

class Expression {
 public:
  virtual std::unique_ptr<Money> reduce(const Bank& bank,
                                        const std::string& to) const = 0;
};

#endif  // C14_2_EXPRESSION_HPP_
