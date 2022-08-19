#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "money.h"

using ::testing::Eq;
using ::testing::Ne;
using ::testing::StrEq;

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
  Money* five = Money::franc(5);

  ASSERT_THAT(*five->times(2), Eq(*Money::franc(10)));
  ASSERT_THAT(*five->times(3), Eq(*Money::franc(15)));
}

TEST(MultipleCurrency, CanRetrieveCurrency) {
  ASSERT_THAT(Money::dollar(1)->currency(), StrEq("USD"));
  ASSERT_THAT(Money::franc(1)->currency(), StrEq("CHF"));
}