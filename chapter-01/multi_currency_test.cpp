// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include <gmock/gmock.h>

#include "chapter-01/dollar.hpp"

using ::testing::Eq;

TEST(MultiCurrency, Multiplication) {
  Dollar five{5};

  five.times(2);

  ASSERT_THAT(five.amount, Eq(10));
}
