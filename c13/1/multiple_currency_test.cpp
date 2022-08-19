// Copyright 2022 Ismael Jimenez
// Copyright 2003 Kent Beck
// All rights reserved.

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <utility>

#include "./bank.hpp"
#include "./money.hpp"
#include "./sum.hpp"

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
  Money five = Money::dollar(5);
  auto sum = five + five;
  Bank bank{};
  Money reduced = bank.reduce(*sum, "USD");
  ASSERT_THAT(reduced, Eq(Money::dollar(10)));
}