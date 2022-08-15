class Dollar
{
public:
  Dollar(unsigned int amount) : amount{amount} {}
  void times(unsigned int multiplier) { amount *= multiplier; }
  unsigned int amount;
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