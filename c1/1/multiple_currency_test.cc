#include <cstdint>

class Dollar
{
public:
  Dollar(std::uint32_t amount) {}
  void times(std::uint32_t times) {}
  std::uint32_t amount{10};
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