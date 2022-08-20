// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include <gmock/gmock.h>

#include "chapter-3/dollar.hpp"

using ::testing::Eq;

TEST(MultiCurrency, Multiplication) {
  Dollar five{5};

  auto product = five.times(2);
  ASSERT_THAT(product.amount, Eq(10));

  product = five.times(3);
  ASSERT_THAT(product.amount, Eq(15));
}

TEST(MultiCurrency, Equality) {
  ASSERT_TRUE(Dollar{5}.equals(Dollar{5}));
  ASSERT_FALSE(Dollar{5}.equals(Dollar{6}));
}
