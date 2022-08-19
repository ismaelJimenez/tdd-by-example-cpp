class Dollar {
 public:
  Dollar(unsigned int amount) {}
  void times(unsigned int times) {}
  unsigned int amount{10};
};

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;

TEST(MultipleCurrency, CanMultiplyAnAmountByANumber) {
  Dollar five{5};

  five.times(2);

  ASSERT_THAT(five.amount, Eq(10));
}