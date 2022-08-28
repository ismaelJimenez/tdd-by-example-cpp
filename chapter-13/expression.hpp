// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_13_EXPRESSION_HPP_
#define CHAPTER_13_EXPRESSION_HPP_

#include <string>

class Money;

class Expression {
 public:
  [[nodiscard]] virtual Money reduce(const std::string& to) const = 0;

  virtual ~Expression() = default;
};

#endif  // CHAPTER_13_EXPRESSION_HPP_
