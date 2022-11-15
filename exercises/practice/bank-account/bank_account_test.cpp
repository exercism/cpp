#include "bank_account.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <chrono>
#include <string>
#include <thread>

TEST_CASE("newly_opened_account_has_zero_balance")
{
    Bankaccount::Bankaccount account{};
    account.open();
    REQUIRE(account.balance() == 0);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("deposit_money_increases_balance")
{
    Bankaccount::Bankaccount account{};
    account.open();
    account.deposit(100);
    REQUIRE(account.balance() == 100);
}

TEST_CASE("deposit_money_sequentially_increases_balance")
{
    Bankaccount::Bankaccount account{};
    account.open();
    account.deposit(100);
    account.deposit(50);
    REQUIRE(account.balance() == 150);
}

TEST_CASE("withdraw_money_decreases_balance")
{
    Bankaccount::Bankaccount account{};
    account.open();
    account.deposit(100);
    account.withdraw(50);
    REQUIRE(account.balance() == 50);
}

TEST_CASE("withdraw_money_sequentially_decreases_balance")
{
    Bankaccount::Bankaccount account{};
    account.open();
    account.deposit(100);
    account.withdraw(50);
    account.withdraw(30);
    REQUIRE(account.balance() == 20);
}

TEST_CASE("checking_balance_of_not_opened_account_throws_error")
{
    Bankaccount::Bankaccount account{};
    REQUIRE_THROWS_AS(account.balance(), std::runtime_error);
}

TEST_CASE("checking_balance_of_a_closed_account_throws_error")
{
    Bankaccount::Bankaccount account{};
    account.open();
    account.close();

    REQUIRE_THROWS_AS(account.balance(), std::runtime_error);
}

TEST_CASE("deposit_into_closed_account_throws_error")
{
    Bankaccount::Bankaccount account{};
    account.open();
    account.close();

    REQUIRE_THROWS_AS(account.deposit(50), std::runtime_error);
}

TEST_CASE("withdraw_from_closed_account_throws_error")
{
    Bankaccount::Bankaccount account{};
    account.open();
    account.close();

    REQUIRE_THROWS_AS(account.withdraw(50), std::runtime_error);
}

TEST_CASE("close_an_unopened_account_throws_error")
{
    Bankaccount::Bankaccount account;

    REQUIRE_THROWS_AS(account.close(), std::runtime_error);
}

TEST_CASE("close_an_already_closed_account_throws_error")
{
    Bankaccount::Bankaccount account;
    account.open();
    account.close();

    REQUIRE_THROWS_AS(account.close(), std::runtime_error);
}

TEST_CASE("open_an_already_opened_account_throws_error")
{
    Bankaccount::Bankaccount account;
    account.open();

    REQUIRE_THROWS_AS(account.open(), std::runtime_error);
}

TEST_CASE("reopened_account_does_not_retain_balance")
{
    Bankaccount::Bankaccount account;
    account.open();
    account.deposit(100);
    account.close();
    account.open();

    REQUIRE(account.balance() == 0);
}

TEST_CASE("cannot_withdraw_more_than_deposited")
{
    Bankaccount::Bankaccount account;
    account.open();
    account.deposit(100);

    REQUIRE_THROWS_AS(account.withdraw(150), std::runtime_error);
}

TEST_CASE("deposit_negativ_amount_throws_error")
{
    Bankaccount::Bankaccount account;
    account.open();

    REQUIRE_THROWS_AS(account.deposit(-100), std::runtime_error);
}

TEST_CASE("withdraw_negativ_amount_throws_error")
{
    Bankaccount::Bankaccount account;
    account.open();

    REQUIRE_THROWS_AS(account.withdraw(-100), std::runtime_error);
}

TEST_CASE("can_handle_concurrent_transactions")
{
    Bankaccount::Bankaccount account;
    account.open();
    account.deposit(1000);

    std::vector<std::thread> vec_of_threads;

    for (int i = 0; i < 1000; ++i) {
        vec_of_threads.push_back(std::thread([&]() {
            using namespace std::chrono_literals;
            account.deposit(5);
            std::this_thread::sleep_for(5ms);
            account.withdraw(5);
        }));
    }

    for (auto& th : vec_of_threads) {
        th.join();
    }

    REQUIRE(account.balance() == 1000);
}
#endif
