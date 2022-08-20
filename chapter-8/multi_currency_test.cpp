// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include <gmock/gmock.h>

#include "chapter-8/dollar.hpp"
#include "chapter-8/franc.hpp"

using ::testing::Eq;

TEST(MultiCurrency, Multiplication) {
  auto five = Money::dollar(5);

  EXPECT_EQ(*five->times(2), *Money::dollar(10));
  EXPECT_EQ(*five->times(3), *Money::dollar(15));
}

TEST(MultiCurrency, Equality) {
  ASSERT_TRUE(*Money::dollar(5) == *Money::dollar(5));
  ASSERT_FALSE(*Money::dollar(5) == *Money::dollar(6));
  ASSERT_TRUE(*Money::franc(5) == *Money::franc(5));
  ASSERT_FALSE(*Money::franc(5) == *Money::franc(6));
  ASSERT_FALSE(*Money::franc(5) == *Money::dollar(5));
}

TEST(MultiCurrency, FrancMultiplication) {
  auto five = Money::franc(5);

  EXPECT_EQ(*five->times(2), *Money::franc(10));
  EXPECT_EQ(*five->times(3), *Money::franc(15));
}
