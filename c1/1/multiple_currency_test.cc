class Dollar
{
public:
  Dollar(unsigned int amount) {}
  void times(unsigned int times) {}
  unsigned int amount{10};
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