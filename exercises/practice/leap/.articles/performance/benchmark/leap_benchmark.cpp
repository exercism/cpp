#include <benchmark/benchmark.h>

#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

#include "boost/date_time/gregorian/gregorian_types.hpp"

static std::vector<int> generate_data(size_t size) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(1400, 9999);

    std::vector<int> data(size);
    std::generate(data.begin(), data.end(), [&distribution, &generator]() {
        return distribution(generator);
    });
    return data;
}

const int limit = 1000;
const std::vector<int> data{generate_data(limit)};
bool result = true;

static void BM_Leap_boolean_chain(benchmark::State& state) {
    for (auto _ : state) {
        for (size_t i = 0; i < limit; ++i) {
            result = (data.at(i) % 4 == 0) &&
                     (data.at(i) % 100 != 0 || data.at(i) % 400 == 0);
        }
    }
}
BENCHMARK(BM_Leap_boolean_chain);

static void BM_Leap_boolean_chain_inverse(benchmark::State& state) {
    for (auto _ : state) {
        for (size_t i = 0; i < limit; ++i) {
            result = (data.at(i) % 400 == 0) ||
                     (data.at(i) % 100 != 0 && data.at(i) % 4 == 0);
        }
    }
}
BENCHMARK(BM_Leap_boolean_chain_inverse);

static void BM_Leap_ternary(benchmark::State& state) {
    for (auto _ : state) {
        for (size_t i = 0; i < limit; ++i) {
            result = data.at(i) % 100 == 0 ? data.at(i) % 400 == 0
                                           : data.at(i) % 4 == 0;
        }
    }
}
BENCHMARK(BM_Leap_ternary);

static void BM_Leap_chrono(benchmark::State& state) {
    for (auto _ : state) {
        for (size_t i = 0; i < limit; ++i) {
            result = std::chrono::year{data.at(i)}.is_leap();
        }
    }
}
BENCHMARK(BM_Leap_chrono);

static void BM_Leap_boost(benchmark::State& state) {
    for (auto _ : state) {
        for (size_t i = 0; i < limit; ++i) {
            result =
                boost::gregorian::gregorian_calendar::is_leap_year(data.at(i));
        }
    }
}
BENCHMARK(BM_Leap_boost);

// How much does the iteration of the array cost?
static void BM_empty_read(benchmark::State& state) {
    for (auto _ : state) {
        for (size_t i = 0; i < limit; ++i) {
            result = true;
        }
    }
}
BENCHMARK(BM_empty_read);

BENCHMARK_MAIN();
