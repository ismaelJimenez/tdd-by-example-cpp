#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "dollar.h"

using ::testing::Eq;

TEST(MultipleCurrency, CanMultiplyAnAmountByANumber)
{
  Dollar five{5};

  auto product = five.times(2);

  ASSERT_THAT(product.amount, Eq(10));
}

TEST(MultipleCurrency, CanMultiplyWithoutSideEffects)
{
  Dollar five{5};
  auto product = five.times(2);

  product = five.times(3);

  ASSERT_THAT(product.amount, Eq(15));
}

TEST(MultipleCurrency, CanCompareForEqualAmounts) {
  ASSERT_THAT(Dollar{5}, Eq(Dollar{5}));
}