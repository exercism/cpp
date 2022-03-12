#include ".meta/example.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <string>

TEST_CASE("newly_opened_account_has_zero_balance") {
    Bankaccount account{};
    account.open();
    REQUIRE(account.balance() == 0);
}

TEST_CASE("deposit_money_increases_balance") {
    Bankaccount account{};
    account.open();
    account.deposit(100);
    REQUIRE(account.balance() == 100);
}

TEST_CASE("deposit_money_sequentially_increases_balance") {
    Bankaccount account{};
    account.open();
    account.deposit(100);
    account.deposit(50);
    REQUIRE(account.balance() == 150);
}

TEST_CASE("withdraw_money_decreases_balance") {
    Bankaccount account{};
    account.open();
    account.deposit(100);
    account.withdraw(50);
    REQUIRE(account.balance() == 50);
}

TEST_CASE("withdraw_money_sequentially_decreases_balance") {
    Bankaccount account{};
    account.open();
    account.deposit(100);
    account.withdraw(50);
    account.withdraw(30);
    REQUIRE(account.balance() == 20);
}