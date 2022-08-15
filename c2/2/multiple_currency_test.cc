#include <cstdint>

class Dollar
{
public:
  Dollar(std::uint32_t amount) : amount{amount} {}

  Dollar times(std::uint32_t multiplier)
  {
    return {amount * multiplier};
  }

  std::uint32_t amount;
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