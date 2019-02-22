#include "binary_search_tree.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

static void test_branch(const std::unique_ptr<binary_tree::binary_tree> &br, bool has)
{
    if (has)
        BOOST_REQUIRE_NE(nullptr, br.get());
    else
        BOOST_REQUIRE_EQUAL(nullptr, br.get());
}

static void test_leaf(const std::unique_ptr<binary_tree::binary_tree> &tree, 
                      int data, bool has_left, bool has_right)
{
    BOOST_REQUIRE_EQUAL(data, tree->data());
    test_branch(tree->left(), has_left);
    test_branch(tree->right(), has_right);
}

static std::unique_ptr<binary_tree::binary_tree> make_tree(int data)
{
    return std::unique_ptr<binary_tree::binary_tree>(new binary_tree::binary_tree(data));
}

BOOST_AUTO_TEST_CASE(data_is_retained)
{
    auto tested = make_tree(4);
    test_leaf(tested, 4, false, false);
}


BOOST_AUTO_TEST_CASE(insert_data_at_proper_node)
{
    auto tested = make_tree(4);
    tested->insert(2);

    test_leaf(tested, 4, true, false);
    test_leaf(tested->left(), 2, false, false);
}

BOOST_AUTO_TEST_CASE(same_number_at_left_node)
{
    auto tested = make_tree(4);
    tested->insert(4);

    test_leaf(tested, 4, true, false);
    test_leaf(tested->left(), 4, false, false);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif