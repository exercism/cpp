#include "binary_search_tree.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <vector>

using tree_ptr = std::unique_ptr<binary_tree::binary_tree>;

static void test_branch(const tree_ptr &br, bool has)
{
    if (has)
        BOOST_REQUIRE_NE(nullptr, br.get());
    else
        BOOST_REQUIRE_EQUAL(nullptr, br.get());
}

static void test_leaf(const tree_ptr &tree, 
                      int data, bool has_left, bool has_right)
{
    BOOST_REQUIRE_EQUAL(data, tree->data());
    test_branch(tree->left(), has_left);
    test_branch(tree->right(), has_right);
}

static tree_ptr make_tree(const std::vector<int> &data)
{
    if (data.empty())
        return tree_ptr(nullptr);
    
    auto data_iter = data.begin();
    auto tree = tree_ptr(new binary_tree::binary_tree(*data_iter));
    ++data_iter;

    for (; data_iter != data.end(); ++data_iter)
    {
        tree->insert(*data_iter);
    }

    return std::move(tree);
}

BOOST_AUTO_TEST_CASE(data_is_retained)
{
    auto tested = make_tree({4});
    test_leaf(tested, 4, false, false);
}


BOOST_AUTO_TEST_CASE(insert_data_at_proper_node)
{
    auto tested = make_tree({4, 2});

    test_leaf(tested, 4, true, false);
    test_leaf(tested->left(), 2, false, false);
}

BOOST_AUTO_TEST_CASE(same_number_at_left_node)
{
    auto tested = make_tree({4, 4});

    test_leaf(tested, 4, true, false);
    test_leaf(tested->left(), 4, false, false);
}

// BOOST_AUTO_TEST_CASE(greater_number_at_right_node)
// {
//     auto 
// }

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif