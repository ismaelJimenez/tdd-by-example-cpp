// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include <gmock/gmock.h>

#include "chapter-10/dollar.hpp"
#include "chapter-10/franc.hpp"

using ::testing::Eq;
using ::testing::StrEq;

TEST(MultiCurrency, Multiplication) {
  auto five = Money::dollar(5);

  ASSERT_THAT(five->times(2), Eq(*Money::dollar(10)));
  ASSERT_THAT(five->times(3), Eq(*Money::dollar(15)));
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

  ASSERT_THAT(five->times(2), Eq(*Money::franc(10)));
  ASSERT_THAT(five->times(3), Eq(*Money::franc(15)));
}

TEST(MultiCurrency, Currency) {
  ASSERT_THAT(Money::dollar(1)->currency(), StrEq("USD"));
  ASSERT_THAT(Money::franc(1)->currency(), StrEq("CHF"));
}
