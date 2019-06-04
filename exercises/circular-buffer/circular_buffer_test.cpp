#include "test/catch.hpp"
#include "circular_buffer.h"
#include <stdexcept>

// Circular-buffer exercise test case data version 1.1.0

TEST_CASE("reading_empty_buffer_should_fail") 
{
    circular_buffer::circular_buffer buffer(1);

    REQUIRE_THROWS_AS(buffer.read(), std::domain_error);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("can_read_an_item_just_written") 
{
    circular_buffer::circular_buffer buffer(1);

    REQUIRE_NOTHROW(buffer.write(1));

    int expected = 1;
    REQUIRE_NOTHROW(expected == buffer.read());
}


TEST_CASE("items_are_read_in_the_order_they_are_written") 
{
    circular_buffer::circular_buffer buffer(2);

    REQUIRE_NOTHROW(buffer.write(1));
    REQUIRE_NOTHROW(buffer.write(2));

    int expected = 1;
    REQUIRE_NOTHROW(expected == buffer.read());

    expected = 2;
    REQUIRE_NOTHROW(expected == buffer.read());
}

TEST_CASE("full_buffer_cant_be_written") 
{
    circular_buffer::circular_buffer buffer(1);

    REQUIRE_NOTHROW(buffer.write(1));
    REQUIRE_THROWS_AS(buffer.write(2), std::domain_error);
}

TEST_CASE("a_read_frees_up_capacity_for_another_write") 
{
    circular_buffer::circular_buffer buffer(1);

    REQUIRE_NOTHROW(buffer.write(1));

    int expected = 1;
    REQUIRE(expected == buffer.read());

    REQUIRE_NOTHROW(buffer.write(2));
    expected = 2;
    REQUIRE_NOTHROW(expected == buffer.read());
}

TEST_CASE("read_position_is_maintained_even_across_multiple_writes") 
{
    circular_buffer::circular_buffer buffer(3);

    REQUIRE_NOTHROW(buffer.write(1));
    REQUIRE_NOTHROW(buffer.write(2));

    int expected = 1;
    REQUIRE_NOTHROW(expected == buffer.read());

    REQUIRE_NOTHROW(buffer.write(3));

    expected = 2;
    REQUIRE_NOTHROW(expected == buffer.read());

    expected = 3;
    REQUIRE_NOTHROW(expected == buffer.read());
}

TEST_CASE("items_cleared_out_of_buffer_cant_be_read") 
{
    circular_buffer::circular_buffer buffer(1);

    REQUIRE_NOTHROW(buffer.write(1));

    buffer.clear();

    REQUIRE_THROWS_AS(buffer.read(), std::domain_error);
}

TEST_CASE("clear_frees_up_capacity_for_another_write") 
{
    circular_buffer::circular_buffer buffer(1);

    REQUIRE_NOTHROW(buffer.write(1));

    buffer.clear();

    REQUIRE_NOTHROW(buffer.write(2));

    int expected = 2;
    REQUIRE_NOTHROW(expected == buffer.read());
}

TEST_CASE("clear_does_nothing_on_empty_buffer") 
{
    circular_buffer::circular_buffer buffer(1);

    buffer.clear();

    REQUIRE_NOTHROW(buffer.write(1));

    int expected = 1;
    REQUIRE_NOTHROW(expected == buffer.read());
}

TEST_CASE("overwrite_acts_like_write_on_non_full_buffer") 
{
    circular_buffer::circular_buffer buffer(2);

    REQUIRE_NOTHROW(buffer.write(1));

    buffer.overwrite(2);

    int expected = 1;
    REQUIRE_NOTHROW(expected == buffer.read());

    expected = 2;
    REQUIRE_NOTHROW(expected == buffer.read());
}

TEST_CASE("overwrite_replaces_the_oldest_item_on_full_buffer") 
{
    circular_buffer::circular_buffer buffer(2);

    REQUIRE_NOTHROW(buffer.write(1));
    REQUIRE_NOTHROW(buffer.write(2));

    buffer.overwrite(3);

    int expected = 2;
    REQUIRE_NOTHROW(expected == buffer.read());

    expected = 3;
    REQUIRE_NOTHROW(expected == buffer.read());
}

TEST_CASE("overwrite_replaces_the_oldest_item_remaining_in_buffer_following_a_read") 
{
    circular_buffer::circular_buffer buffer(3);

    REQUIRE_NOTHROW(buffer.write(1));
    REQUIRE_NOTHROW(buffer.write(2));
    REQUIRE_NOTHROW(buffer.write(3));

    int expected = 1;
    REQUIRE_NOTHROW(expected == buffer.read());

    REQUIRE_NOTHROW(buffer.write(4));

    buffer.overwrite(5);

    expected = 3;
    REQUIRE_NOTHROW(expected == buffer.read());

    expected = 4;
    REQUIRE_NOTHROW(expected == buffer.read());

    expected = 5;
    REQUIRE_NOTHROW(expected == buffer.read());
}
#endif  // !EXERCISM_RUN_ALL_TESTS
