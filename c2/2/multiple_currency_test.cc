// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

class Dollar {
 public:
  explicit Dollar(unsigned int amount) : amount{amount} {}

  Dollar times(unsigned int multiplier) { return {amount * multiplier}; }

  unsigned int amount;
};

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;

TEST(MultipleCurrency, CanMultiplyAnAmountByANumber) {
  Dollar five{5};

  auto product = five.times(2);

  ASSERT_THAT(product.amount, Eq(10));
}

TEST(MultipleCurrency, CanMultiplyWithoutSideEffects) {
  Dollar five{5};
  auto product = five.times(2);

  product = five.times(3);

  ASSERT_THAT(product.amount, Eq(15));
}
