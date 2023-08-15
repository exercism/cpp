#include "circular_buffer.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

#include <stdexcept>

// Circular-buffer exercise test case data version 1.2.0

TEST_CASE("reading_empty_buffer_should_fail") 
{
    circular_buffer::circular_buffer<int> buffer(1);

    REQUIRE_THROWS_AS(buffer.read(), std::domain_error);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("can_read_an_item_just_written") 
{
    circular_buffer::circular_buffer<int> buffer(1);

    REQUIRE_NOTHROW(buffer.write(1));

    int expected = 1;
    REQUIRE(expected == buffer.read());
}

TEST_CASE("each_item_may_only_be_read_once") 
{
    circular_buffer::circular_buffer<int> buffer(1);

    REQUIRE_NOTHROW(buffer.write(1));

    int expected = 1;
    REQUIRE(expected == buffer.read());

    REQUIRE_THROWS_AS(buffer.read(), std::domain_error);
}

TEST_CASE("items_are_read_in_the_order_they_are_written") 
{
    circular_buffer::circular_buffer<int> buffer(2);

    REQUIRE_NOTHROW(buffer.write(1));
    REQUIRE_NOTHROW(buffer.write(2));

    int expected = 1;
    REQUIRE(expected == buffer.read());

    expected = 2;
    REQUIRE(expected == buffer.read());
}

TEST_CASE("full_buffer_cant_be_written") 
{
    circular_buffer::circular_buffer<int> buffer(1);

    REQUIRE_NOTHROW(buffer.write(1));
    REQUIRE_THROWS_AS(buffer.write(2), std::domain_error);
}

TEST_CASE("a_read_frees_up_capacity_for_another_write") 
{
    circular_buffer::circular_buffer<int> buffer(1);

    REQUIRE_NOTHROW(buffer.write(1));

    int expected = 1;
    REQUIRE(expected == buffer.read());

    REQUIRE_NOTHROW(buffer.write(2));

    expected = 2;
    REQUIRE(expected == buffer.read());
}

TEST_CASE("read_position_is_maintained_even_across_multiple_writes") 
{
    circular_buffer::circular_buffer<int> buffer(3);

    REQUIRE_NOTHROW(buffer.write(1));
    REQUIRE_NOTHROW(buffer.write(2));

    int expected = 1;
    REQUIRE(expected == buffer.read());

    REQUIRE_NOTHROW(buffer.write(3));

    expected = 2;
    REQUIRE(expected == buffer.read());

    expected = 3;
    REQUIRE(expected == buffer.read());
}

TEST_CASE("items_cleared_out_of_buffer_cant_be_read") 
{
    circular_buffer::circular_buffer<int> buffer(1);

    REQUIRE_NOTHROW(buffer.write(1));

    buffer.clear();

    REQUIRE_THROWS_AS(buffer.read(), std::domain_error);
}

TEST_CASE("clear_frees_up_capacity_for_another_write") 
{
    circular_buffer::circular_buffer<int> buffer(1);

    REQUIRE_NOTHROW(buffer.write(1));

    buffer.clear();

    REQUIRE_NOTHROW(buffer.write(2));

    int expected = 2;
    REQUIRE(expected == buffer.read());
}

TEST_CASE("clear_does_nothing_on_empty_buffer") 
{
    circular_buffer::circular_buffer<int> buffer(1);

    buffer.clear();

    REQUIRE_NOTHROW(buffer.write(1));

    int expected = 1;
    REQUIRE(expected == buffer.read());
}

TEST_CASE("overwrite_acts_like_write_on_non_full_buffer") 
{
    circular_buffer::circular_buffer<int> buffer(2);

    REQUIRE_NOTHROW(buffer.write(1));

    buffer.overwrite(2);

    int expected = 1;
    REQUIRE(expected == buffer.read());

    expected = 2;
    REQUIRE(expected == buffer.read());
}

TEST_CASE("overwrite_replaces_the_oldest_item_on_full_buffer") 
{
    circular_buffer::circular_buffer<int> buffer(2);

    REQUIRE_NOTHROW(buffer.write(1));
    REQUIRE_NOTHROW(buffer.write(2));

    buffer.overwrite(3);

    int expected = 2;
    REQUIRE(expected == buffer.read());

    expected = 3;
    REQUIRE(expected == buffer.read());
}

TEST_CASE("overwrite_replaces_the_oldest_item_remaining_in_buffer_following_a_read") 
{
    circular_buffer::circular_buffer<int> buffer(3);

    REQUIRE_NOTHROW(buffer.write(1));
    REQUIRE_NOTHROW(buffer.write(2));
    REQUIRE_NOTHROW(buffer.write(3));

    int expected = 1;
    REQUIRE(expected == buffer.read());

    REQUIRE_NOTHROW(buffer.write(4));

    buffer.overwrite(5);

    expected = 3;
    REQUIRE(expected == buffer.read());

    expected = 4;
    REQUIRE(expected == buffer.read());

    expected = 5;
    REQUIRE(expected == buffer.read());
}

TEST_CASE("full_buffer_cant_be_written_after_overwrite") 
{
    circular_buffer::circular_buffer<int> buffer(1);

    REQUIRE_NOTHROW(buffer.write(1));
    buffer.overwrite(2);
    REQUIRE_THROWS_AS(buffer.write(3), std::domain_error);

    int expected = 2;
    REQUIRE(expected == buffer.read());
}

TEST_CASE("check_correctness_with_string_type") 
{
    circular_buffer::circular_buffer<std::string> buffer(3);

    REQUIRE_NOTHROW(buffer.write("hello"));
    REQUIRE_NOTHROW(buffer.write("world"));
    REQUIRE_NOTHROW(buffer.write("zombies"));

    std::string expected = "hello";
    REQUIRE(expected == buffer.read());

    REQUIRE_NOTHROW(buffer.write("pants"));

    buffer.overwrite("banana");

    expected = "zombies";
    REQUIRE(expected == buffer.read());

    expected = "pants";
    REQUIRE(expected == buffer.read());

    expected = "banana";
    REQUIRE(expected == buffer.read());
}

TEST_CASE("initial_clear_does_not_affect_wrapping_around")
{
    circular_buffer::circular_buffer<int> buffer(2);

    buffer.clear();

    REQUIRE_NOTHROW(buffer.write(1));
    REQUIRE_NOTHROW(buffer.write(2));

    buffer.overwrite(3);
    buffer.overwrite(4);

    int expected = 3;
    REQUIRE(expected == buffer.read());

    expected = 4;
    REQUIRE(expected == buffer.read());

    REQUIRE_THROWS_AS(buffer.read(), std::domain_error);
}
#endif  // !EXERCISM_RUN_ALL_TESTS
