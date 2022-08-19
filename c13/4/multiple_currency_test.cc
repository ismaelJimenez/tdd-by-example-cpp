#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "bank.h"
#include "money.h"
#include "sum.h"

using ::testing::Eq;
using ::testing::Ne;
using ::testing::StrEq;

TEST(MultipleCurrency, CanMultiplyMoneyByANumber) {
  Money five = Money::dollar(5);

  ASSERT_THAT(five.times(2), Eq(Money::dollar(10)));
  ASSERT_THAT(five.times(3), Eq(Money::dollar(15)));
}

TEST(MultipleCurrency, CanCompareCurrencies) {
  ASSERT_TRUE(Money::dollar(5) == Money::dollar(5));
  ASSERT_FALSE(Money::dollar(5) == Money::dollar(6));
  ASSERT_FALSE(Money::franc(5) == Money::dollar(5));
}

TEST(MultipleCurrency, CanRetrieveCurrency) {
  ASSERT_THAT(Money::dollar(1).currency(), StrEq("USD"));
  ASSERT_THAT(Money::franc(1).currency(), StrEq("CHF"));
}

TEST(MultipleCurrency, CanAddSameCurrency) {
  auto sum = Money::dollar(5) + Money::dollar(5);
  ASSERT_THAT(sum->augend, Eq(Money::dollar(5)));
  ASSERT_THAT(sum->addend, Eq(Money::dollar(5)));
}

TEST(MultipleCurrency, CanAddDifferentCurrencies) {
  auto sum = Money::dollar(3) + Money::dollar(4);
  Bank bank{};
  Money reduced = bank.reduce(*sum, "USD");
  ASSERT_THAT(reduced, Eq(Money::dollar(7)));
}

TEST(MultipleCurrency, CanReduceMoney) {
  auto dollar = Money::dollar(1);
  Bank bank{};
  Money reduced = bank.reduce(dollar, "USD");
  ASSERT_THAT(reduced, Eq(Money::dollar(1)));
}