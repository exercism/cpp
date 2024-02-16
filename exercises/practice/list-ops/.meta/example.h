#pragma once

#include <functional>
#include <vector>

namespace list_ops {

template <typename T>
void append(std::vector<T>& left, const std::vector<T>& right) {
    for (auto element : right) {
        left.emplace_back(element);
    }
}

template <typename T>
std::vector<T> concat(const std::vector<std::vector<T>>& input) {
    std::vector<T> result{};
    for (auto vec : input) {
        for (auto element : vec) {
            result.emplace_back(element);
        }
    }
    return result;
}

template <typename T, typename S>
std::vector<T> filter(const std::vector<T>& input, S&& func) {
    std::vector<T> result{};
    for (auto element : input) {
        if (func(element)) {
            result.emplace_back(element);
        }
    }
    return result;
}

template <typename T>
size_t length(const std::vector<T>& input) {
    size_t counter{};
    for ([[maybe_unused]] const auto& element : input) {
        ++counter;
    }
    return counter;
}

template <typename T, typename S>
std::vector<T> map(const std::vector<T>& input, S&& func) {
    std::vector<T> result{};
    for (auto element : input) {
        result.emplace_back(func(element));
    }
    return result;
}

template <typename T, typename S>
T foldl(const std::vector<T>& input, T initial_value, S&& func) {
    T accumulator{initial_value};
    for (auto element : input) {
        accumulator = func(accumulator, element);
    }
    return accumulator;
}

template <typename T, typename S>
T foldr(const std::vector<T>& input, T initial_value, S&& func) {
    T accumulator{initial_value};
    for (unsigned i = input.size(); i-- > 0;) {
        accumulator = func(accumulator, input.at(i));
    }
    return accumulator;
}

template <typename T>
std::vector<T> reverse(const std::vector<T>& input) {
    std::vector<T> result{};
    for (unsigned i = input.size(); i-- > 0;) {
        result.emplace_back(input.at(i));
    }
    return result;
}

}  // namespace list_ops
