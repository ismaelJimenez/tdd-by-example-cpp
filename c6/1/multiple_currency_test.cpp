// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "./dollar.hpp"
#include "./franc.hpp"

using ::testing::Eq;
using ::testing::Ne;

TEST(MultipleCurrency, CanMultiplyADollarByANumber) {
  Dollar five{5};

  ASSERT_THAT(five.times(2), Eq(Dollar{10}));
  ASSERT_THAT(five.times(3), Eq(Dollar{15}));
}

TEST(MultipleCurrency, CanCompareDollars) {
  ASSERT_TRUE(Dollar{5} == Dollar{5});
  ASSERT_FALSE(Dollar{5} == Dollar{6});
}

TEST(MultipleCurrency, CanMultiplyAFrancByANumber) {
  Franc five{5};

  ASSERT_THAT(five.times(2), Eq(Franc{10}));
  ASSERT_THAT(five.times(3), Eq(Franc{15}));
}