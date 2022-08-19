#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "franc.h"
#include "money.h"

using ::testing::Eq;
using ::testing::Ne;

TEST(MultipleCurrency, CanMultiplyADollarByANumber) {
  Money* five = Money::dollar(5);

  ASSERT_THAT(*five->times(2), Eq(*Money::dollar(10)));
  ASSERT_THAT(*five->times(3), Eq(*Money::dollar(15)));
}

TEST(MultipleCurrency, CanCompareCurrencies) {
  ASSERT_TRUE(*Money::dollar(5) == *Money::dollar(5));
  ASSERT_FALSE(*Money::dollar(5) == *Money::dollar(6));
  ASSERT_TRUE(Franc{5} == Franc{5});
  ASSERT_FALSE(Franc{5} == Franc{6});
  ASSERT_FALSE(Franc{5} == *Money::dollar(5));
}

TEST(MultipleCurrency, CanMultiplyAFrancByANumber) {
  Franc five{5};

  ASSERT_THAT(*five.times(2), Eq(Franc{10}));
  ASSERT_THAT(*five.times(3), Eq(Franc{15}));
}