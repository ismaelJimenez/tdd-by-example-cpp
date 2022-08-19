// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#ifndef C14_2_BANK_H_
#define C14_2_BANK_H_

#include <memory>
#include <stdexcept>
#include <string>
#include <typeinfo>

#include "./money.h"
#include "./sum.h"

class Bank {
 public:
  Money reduce(const Expression& source, const std::string& to) const {
    return *source.reduce(*this, to);
  }
};

#endif  // C14_2_BANK_H_
