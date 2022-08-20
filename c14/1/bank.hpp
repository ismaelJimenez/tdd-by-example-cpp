// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C14_1_BANK_HPP_
#define C14_1_BANK_HPP_

#include <memory>
#include <stdexcept>
#include <string>
#include <typeinfo>

#include "./money.hpp"
#include "./sum.hpp"

class Bank {
 public:
  Money reduce(const Expression& source, const std::string& to) const {
    return *source.reduce(*this, to);
  }
};

#endif  // C14_1_BANK_HPP_
