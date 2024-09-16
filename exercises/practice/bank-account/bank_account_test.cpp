#include "bank_account.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <chrono>
#include <string>
#include <thread>

TEST_CASE("Newly opened account has zero balance", "[983a1528-4ceb-45e5-8257-8ce01aceb5ed]") {
    Bankaccount::Bankaccount account{};
    account.open();
    REQUIRE(account.balance() == 0);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("Single deposit", "[e88d4ec3-c6bf-4752-8e59-5046c44e3ba7]") {
    Bankaccount::Bankaccount account{};
    account.open();
    account.deposit(100);
    REQUIRE(account.balance() == 100);
}

TEST_CASE("Multiple deposits", "[3d9147d4-63f4-4844-8d2b-1fee2e9a2a0d]") {
    Bankaccount::Bankaccount account{};
    account.open();
    account.deposit(100);
    account.deposit(50);
    REQUIRE(account.balance() == 150);
}

TEST_CASE("Withdraw once", "[08f1af07-27ae-4b38-aa19-770bde558064]") {
    Bankaccount::Bankaccount account{};
    account.open();
    account.deposit(100);
    account.withdraw(75);
    REQUIRE(account.balance() == 25);
}

TEST_CASE("Withdraw twice", "[6f6d242f-8c31-4ac6-8995-a90d42cad59f]") {
    Bankaccount::Bankaccount account{};
    account.open();
    account.deposit(100);
    account.withdraw(80);
    account.withdraw(20);
    REQUIRE(account.balance() == 0);
}

TEST_CASE("Can do multiple operations sequentially", "[45161c94-a094-4c77-9cec-998b70429bda]") {
    Bankaccount::Bankaccount account{};
    account.open();
    account.deposit(100);
    account.deposit(110);
    account.withdraw(200);
    account.deposit(60);
    account.withdraw(50);
    REQUIRE(account.balance() == 20);
}

TEST_CASE("annot check balance of closed account", "[f9facfaa-d824-486e-8381-48832c4bbffd]") {
    Bankaccount::Bankaccount account{};
    account.open();
    account.close();

    REQUIRE_THROWS_AS(account.balance(), std::runtime_error);
}

TEST_CASE("Cannot deposit into closed account", "[7a65ba52-e35c-4fd2-8159-bda2bde6e59c]") {
    Bankaccount::Bankaccount account{};
    account.open();
    account.close();

    REQUIRE_THROWS_AS(account.deposit(50), std::runtime_error);
}

TEST_CASE("Cannot deposit into unopened account", "[a0a1835d-faae-4ad4-a6f3-1fcc2121380b]") {
    Bankaccount::Bankaccount account{};
    REQUIRE_THROWS_AS(account.deposit(50), std::runtime_error);
}

TEST_CASE("Cannot withdraw from closed account", "[570dfaa5-0532-4c1f-a7d3-0f65c3265608]") {
    Bankaccount::Bankaccount account{};
    account.open();
    account.close();

    REQUIRE_THROWS_AS(account.withdraw(50), std::runtime_error);
}

TEST_CASE("Cannot close an account that was not opened", "[c396d233-1c49-4272-98dc-7f502dbb9470]") {
    Bankaccount::Bankaccount account;

    REQUIRE_THROWS_AS(account.close(), std::runtime_error);
}

TEST_CASE("Cannot open an already opened account", "[c06f534f-bdc2-4a02-a388-1063400684de]") {
    Bankaccount::Bankaccount account;
    account.open();

    REQUIRE_THROWS_AS(account.open(), std::runtime_error);
}


TEST_CASE("Reopened account does not retain balance", "[0722d404-6116-4f92-ba3b-da7f88f1669c]") {
    Bankaccount::Bankaccount account;
    account.open();
    account.deposit(50);
    account.close();
    account.open();

    REQUIRE(account.balance() == 0);
}

TEST_CASE("Cannot withdraw more than deposited", "[ec42245f-9361-4341-8231-a22e8d19c52f]") {
    Bankaccount::Bankaccount account;
    account.open();
    account.deposit(25);

    REQUIRE_THROWS_AS(account.withdraw(50), std::runtime_error);
}

TEST_CASE("Cannot withdraw negative", "[4f381ef8-10ef-4507-8e1d-0631ecc8ee72]") {
    Bankaccount::Bankaccount account;
    account.open();
    account.deposit(100);
    REQUIRE_THROWS_AS(account.withdraw(-50), std::runtime_error);
}

TEST_CASE("Cannot deposit negative", "[d45df9ea-1db0-47f3-b18c-d365db49d938]") {
    Bankaccount::Bankaccount account;
    account.open();

    REQUIRE_THROWS_AS(account.deposit(-50), std::runtime_error);
}

TEST_CASE("Can handle concurrent transactions", "[ba0c1e0b-0f00-416f-8097-a7dfc97871ff]") {
    Bankaccount::Bankaccount account;
    account.open();

    std::vector<std::thread> vec_of_threads;

    for (int i = 0; i < 1000; ++i) {
        vec_of_threads.push_back(std::thread([&]() {
            using namespace std::chrono_literals;
            account.deposit(1);
            std::this_thread::sleep_for(5ms);
            account.withdraw(1);
        }));
    }

    for (auto& th : vec_of_threads) {
        th.join();
    }

    REQUIRE(account.balance() == 0);
}
#endif