#include "binary_search_tree.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <vector>

// test data version: 1.0.0

template<typename T>
using tree_ptr = typename std::unique_ptr<binary_search_tree::binary_tree<T>>;

template<typename T>
static void test_leaf(const tree_ptr<T> &tree, 
                      const T& data, bool has_left, bool has_right)
{
    REQUIRE(data == tree->data());
    REQUIRE((bool) tree->left() == has_left);
    REQUIRE((bool) tree->right() == has_right);
}

template<typename T>
static tree_ptr<T> make_tree(const std::vector<T> &data)
{
    if (data.empty())
        return tree_ptr<T>(nullptr);
    
    auto data_iter = data.begin();
    auto tree = tree_ptr<T>(new binary_search_tree::binary_tree<T>(*data_iter));
    ++data_iter;

    for (; data_iter != data.end(); ++data_iter)
    {
        tree->insert(*data_iter);
    }

    return tree;
}

TEST_CASE("data_is_retained")
{
    auto tested = make_tree<uint32_t>({4});
    test_leaf<uint32_t>(tested, 4, false, false);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("smaller_number_at_left_node")
{
    auto tested = make_tree<uint32_t>({4, 2});

    test_leaf<uint32_t>(tested, 4, true, false);
    test_leaf<uint32_t>(tested->left(), 2, false, false);
}

TEST_CASE("same_number_at_left_node")
{
    auto tested = make_tree<uint32_t>({4, 4});

    test_leaf<uint32_t>(tested, 4, true, false);
    test_leaf<uint32_t>(tested->left(), 4, false, false);
}

TEST_CASE("greater_number_at_right_node")
{
    auto tested = make_tree<uint32_t>({4, 5});
    
    test_leaf<uint32_t>(tested, 4, false, true);
    test_leaf<uint32_t>(tested->right(), 5, false, false);
}

TEST_CASE("can_create_complex_tree")
{
    auto tested = make_tree<uint32_t>({4, 2, 6, 1, 3, 5, 7});

    test_leaf<uint32_t>(tested, 4, true, true);
    test_leaf<uint32_t>(tested->left(), 2, true, true);
    test_leaf<uint32_t>(tested->right(), 6, true, true);

    test_leaf<uint32_t>(tested->left()->left(), 1, false, false);
    test_leaf<uint32_t>(tested->left()->right(), 3, false, false);

    test_leaf<uint32_t>(tested->right()->left(), 5, false, false);
    test_leaf<uint32_t>(tested->right()->right(), 7, false, false);
}

// The tests below require an implementation of an iterator.
// You can get more details here: http://www.cplusplus.com/reference/iterator/

template<typename T>
static void test_sort(const tree_ptr<T> &tree, const std::vector<T> &expected)
{
    std::vector<T> actual;
    for (auto& x : *tree) {
        actual.push_back(x);
    }
    REQUIRE(expected == actual);
}


TEST_CASE("can_sort_single_number")
{
    test_sort(make_tree<uint32_t>({2}), {2});
}

TEST_CASE("can_sort_if_second_number_is_smaller_than_first")
{
    test_sort(make_tree<uint32_t>({2, 1}), {1, 2});
}

TEST_CASE("can_sort_if_second_number_is_same_as_first")
{
    test_sort(make_tree<uint32_t>({2, 2}), {2, 2});
}

TEST_CASE("can_sort_if_second_number_is_greater_than_first")
{
    test_sort(make_tree<uint32_t>({2, 3}), {2, 3});
}

TEST_CASE("can_sort_complex_tree")
{
    test_sort(make_tree<uint32_t>({2, 1, 3, 6, 7, 5}), {1, 2, 3, 5, 6, 7});
}

// strings

TEST_CASE("can_create_complex_tree_strings")
{
    auto tested = make_tree<std::string>({"delicious", "ballon", "flag", "apple", "cat", "elispsis", "grains"});

    test_leaf<std::string>(tested, "delicious", true, true);
    test_leaf<std::string>(tested->left(), "ballon", true, true);
    test_leaf<std::string>(tested->right(), "flag", true, true);

    test_leaf<std::string>(tested->left()->left(), "apple", false, false);
    test_leaf<std::string>(tested->left()->right(), "cat", false, false);

    test_leaf<std::string>(tested->right()->left(), "elispsis", false, false);
    test_leaf<std::string>(tested->right()->right(), "grains", false, false);
}

TEST_CASE("can_sort_complex_tree_strings")
{
    test_sort(make_tree<std::string>({"A", "few", "random", "strings", "that", "should", "be", "sorted"}), {"A", "be", "few", "random", "should", "sorted", "strings", "that"});
}

#endif
