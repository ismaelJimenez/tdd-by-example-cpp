// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include <gmock/gmock.h>

#include "chapter-7/dollar.hpp"
#include "chapter-7/franc.hpp"

using ::testing::Eq;

TEST(MultiCurrency, Multiplication) {
  Dollar five{5};

  ASSERT_THAT(five.times(2), Eq(Dollar{10}));
  ASSERT_THAT(five.times(3), Eq(Dollar{15}));
}

TEST(MultiCurrency, Equality) {
  ASSERT_TRUE(Dollar{5} == Dollar{5});
  ASSERT_FALSE(Dollar{5} == Dollar{6});
  ASSERT_TRUE(Franc{5} == Franc{5});
  ASSERT_FALSE(Franc{5} == Franc{6});
  ASSERT_FALSE(Franc{5} == Dollar{5});
}

TEST(MultiCurrency, FrancMultiplication) {
  Franc five{5};

  ASSERT_THAT(five.times(2), Eq(Franc{10}));
  ASSERT_THAT(five.times(3), Eq(Franc{15}));
}
