// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef CHAPTER_12_BANK_HPP_
#define CHAPTER_12_BANK_HPP_

#include <string>

class Money;
class Expression;

class Bank {
 public:
  Money reduce(const Expression& source, const std::string& to);
};

#endif  // CHAPTER_12_BANK_HPP_
