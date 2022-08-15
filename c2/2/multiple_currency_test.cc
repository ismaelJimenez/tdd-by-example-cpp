class Dollar
{
public:
  Dollar(unsigned int amount) : amount{amount} {}

  Dollar times(unsigned int multiplier)
  {
    return {amount * multiplier};
  }

  unsigned int amount;
};

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Eq;

TEST(MultipleCurrencyTest, CanMultiplyAnAmountByANumber)
{
  Dollar five{5};

  auto product = five.times(2);

  ASSERT_THAT(product.amount, Eq(10));
}

TEST(MultipleCurrencyTest, CanMultiplyWithoutSideEffects)
{
  Dollar five{5};
  auto product = five.times(2);

  product = five.times(3);

  ASSERT_THAT(product.amount, Eq(15));
}