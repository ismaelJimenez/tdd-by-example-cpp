// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C13_3_EXPRESSION_H_
#define C13_3_EXPRESSION_H_

#include <memory>
#include <string>

class Money;

class Expression {
 public:
  virtual std::unique_ptr<Money> reduce(const std::string &to) const = 0;
};

#endif  // C13_3_EXPRESSION_H_
