// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C13_4_BANK_HPP_
#define C13_4_BANK_HPP_

#include <memory>
#include <stdexcept>
#include <string>
#include <typeinfo>

#include "./money.hpp"
#include "./sum.hpp"

class Bank {
 public:
  Money reduce(const Expression& source, const std::string& to) const {
    return *source.reduce(to);
  }
};

#endif  // C13_4_BANK_HPP_
