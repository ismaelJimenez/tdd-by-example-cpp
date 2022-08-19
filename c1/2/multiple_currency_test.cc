// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

class Dollar {
 public:
  explicit Dollar(unsigned int amount) : amount{amount} {}
  void times(unsigned int multiplier) { amount *= multiplier; }
  unsigned int amount;
};

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;

TEST(MultipleCurrency, CanMultiplyAnAmountByANumber) {
  Dollar five{5};

  five.times(2);

  ASSERT_THAT(five.amount, Eq(10));
}
