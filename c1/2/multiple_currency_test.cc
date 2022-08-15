#include <cstdint>

class Dollar
{
public:
  Dollar(std::uint32_t amount) : amount{amount} {}
  void times(std::uint32_t multiplier) { amount *= multiplier; }
  std::uint32_t amount{};
};

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Eq;

TEST(MultipleCurrencyTest, CanMultiplyAnAmountByANumber)
{
  Dollar five{5};

  five.times(2);

  ASSERT_THAT(five.amount, Eq(10));
}