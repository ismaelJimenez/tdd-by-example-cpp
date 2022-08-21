// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include <gmock/gmock.h>

#include "chapter-04/dollar.hpp"

using ::testing::Eq;

TEST(MultiCurrency, Multiplication) {
  Dollar five{5};

  ASSERT_THAT(five.times(2), Eq(Dollar{10}));
  ASSERT_THAT(five.times(3), Eq(Dollar{15}));
}

TEST(MultiCurrency, Equality) {
  ASSERT_TRUE(Dollar{5} == Dollar{5});
  ASSERT_FALSE(Dollar{5} == Dollar{6});
}
