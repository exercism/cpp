#include "circular_buffer.hpp"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

//This is some simple book-keeping to let people who are giving feedback know which version of the exercise you solved.
BOOST_AUTO_TEST_CASE(version_test)
{
   BOOST_CHECK_EQUAL( containers::VERSION, 1 );
}

#if defined(EXERCISM_RUN_ALL_TESTS)

BOOST_AUTO_TEST_CASE(push_back_until_bounds_overrun)
{
   containers::circular_buffer<char,2UL> buffer;
   buffer.push_back( 'a' );
   buffer.push_back( 'b' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'a' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'b' );
   BOOST_CHECK_THROW( buffer.push_back('c'), std::exception );
}

BOOST_AUTO_TEST_CASE(push_front_until_bounds_overrun)
{
   containers::circular_buffer<char,2UL> buffer;
   buffer.push_front( 'a' );
   buffer.push_front( 'b' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'b' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'a' );
   BOOST_CHECK_THROW( buffer.push_back('c'), std::exception );
}
BOOST_AUTO_TEST_CASE(push_back_and_front_intersperses_order)
{
   containers::circular_buffer<char,4UL> buffer;
   BOOST_CHECK_THROW( buffer.at(0UL), std::out_of_range );
   buffer.push_back ( 'a' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'a' );
   BOOST_CHECK_THROW( buffer.at(1UL), std::out_of_range );
   buffer.push_front( 'b' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'b' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'a' );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
   buffer.push_back ( 'c' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'b' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'a' );
   BOOST_CHECK_EQUAL( buffer.at(2UL), 'c' );
   BOOST_CHECK_THROW( buffer.at(3UL), std::out_of_range );
   buffer.push_front( 'd' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'd' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'b' );
   BOOST_CHECK_EQUAL( buffer.at(2UL), 'a' );
   BOOST_CHECK_EQUAL( buffer.at(3UL), 'c' );
   BOOST_CHECK_THROW( buffer.at(4UL), std::out_of_range );
}
BOOST_AUTO_TEST_CASE(pop_back_undoes_push_back)
{
   containers::circular_buffer<char,2UL> buffer;
   BOOST_CHECK_THROW( buffer.at(0UL), std::out_of_range );
   buffer.push_back( 'a' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'a' );
   BOOST_CHECK_THROW( buffer.at(1UL), std::out_of_range );
   buffer.push_back( 'b' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'a' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'b' );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
   buffer.pop_back();
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'a' );
   BOOST_CHECK_THROW( buffer.at(1UL), std::out_of_range );
   buffer.pop_back();
   BOOST_CHECK_THROW( buffer.at(0UL), std::out_of_range );
   BOOST_CHECK_THROW( buffer.pop_back(), std::exception );
}
BOOST_AUTO_TEST_CASE(pop_front_undoes_push_front)
{
   containers::circular_buffer<char,2UL> buffer;
   BOOST_CHECK_THROW( buffer.at(0UL), std::out_of_range );
   buffer.push_front( 'a' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'a' );
   BOOST_CHECK_THROW( buffer.at(1UL), std::out_of_range );
   buffer.push_front( 'b' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'b' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'a' );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
   buffer.pop_front();
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'a' );
   BOOST_CHECK_THROW( buffer.at(1UL), std::out_of_range );
   buffer.pop_front();
   BOOST_CHECK_THROW( buffer.at(0UL), std::out_of_range );
   BOOST_CHECK_THROW( buffer.pop_front(), std::exception );
}
BOOST_AUTO_TEST_CASE(forward_fifo)
{
   containers::circular_buffer<char,4UL> buffer;
   BOOST_CHECK_THROW( buffer.at(0UL), std::out_of_range );
   buffer.push_back( 'a' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'a' );
   BOOST_CHECK_THROW( buffer.at(1UL), std::out_of_range );
   buffer.push_back( 'b' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'a' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'b' );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
   buffer.pop_front();
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'b' );
   BOOST_CHECK_THROW( buffer.at(1UL), std::out_of_range );
   buffer.push_back( 'c' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'b' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'c' );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
   buffer.push_back( 'd' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'b' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'c' );
   BOOST_CHECK_EQUAL( buffer.at(2UL), 'd' );
   BOOST_CHECK_THROW( buffer.at(3UL), std::out_of_range );
   buffer.pop_front();
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'c' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'd' );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
   buffer.push_back( 'e' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'c' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'd' );
   BOOST_CHECK_EQUAL( buffer.at(2UL), 'e' );
   BOOST_CHECK_THROW( buffer.at(3UL), std::out_of_range );
   buffer.push_back( 'f' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'c' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'd' );
   BOOST_CHECK_EQUAL( buffer.at(2UL), 'e' );
   BOOST_CHECK_EQUAL( buffer.at(3UL), 'f' );
   BOOST_CHECK_THROW( buffer.at(4UL), std::out_of_range );
   buffer.pop_front();
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'd' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'e' );
   BOOST_CHECK_EQUAL( buffer.at(2UL), 'f' );
   BOOST_CHECK_THROW( buffer.at(3UL), std::out_of_range );
   buffer.push_back( 'g' );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 'd' );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 'e' );
   BOOST_CHECK_EQUAL( buffer.at(2UL), 'f' );
   BOOST_CHECK_EQUAL( buffer.at(3UL), 'g' );
   BOOST_CHECK_THROW( buffer.at(4UL), std::out_of_range );
   BOOST_CHECK_THROW( buffer.push_back('h'), std::out_of_range );
}
BOOST_AUTO_TEST_CASE(forward_force_back_wraps)
{
   containers::circular_buffer<int,2UL> buffer;
   BOOST_CHECK_THROW( buffer.at(0UL), std::out_of_range );
   buffer.force_back( 1 );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 1 );
   BOOST_CHECK_THROW( buffer.at(1UL), std::out_of_range );
   buffer.force_back( 2 );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 1 );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 2 );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
   buffer.force_back( 3 );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 2 );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 3 );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
   buffer.force_back( 4 );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 3 );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 4 );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
   buffer.pop_back();
   BOOST_CHECK_EQUAL( buffer.at(0UL), 3 );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
}
BOOST_AUTO_TEST_CASE(forward_force_front_wraps)
{
   containers::circular_buffer<int,2UL> buffer;
   BOOST_CHECK_THROW( buffer.at(0UL), std::out_of_range );
   buffer.force_front( 1 );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 1 );
   BOOST_CHECK_THROW( buffer.at(1UL), std::out_of_range );
   buffer.force_front( 2 );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 2 );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 1 );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
   buffer.force_front( 3 );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 3 );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 2 );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
   buffer.force_front( 4 );
   BOOST_CHECK_EQUAL( buffer.at(0UL), 4 );
   BOOST_CHECK_EQUAL( buffer.at(1UL), 3 );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
   buffer.pop_front();
   BOOST_CHECK_EQUAL( buffer.at(0UL), 3 );
   BOOST_CHECK_THROW( buffer.at(2UL), std::out_of_range );
}
BOOST_AUTO_TEST_CASE(range_based_for)
{
   std::vector<int> expected = { 1, 2, 3 };
   containers::circular_buffer<int,3UL> buffer;
   buffer.force_back( 0 );
   buffer.force_back( 1 );
   buffer.force_back( 2 );
   buffer.force_back( 3 );
   for ( auto i : buffer )
   {
      BOOST_CHECK_EQUAL( i, expected.at(0UL) );
      expected.erase( expected.begin() );
   }
   //The loop should not consume elements or change state
   BOOST_CHECK_EQUAL(buffer.at(0UL),1);
   BOOST_CHECK_EQUAL(buffer.at(1UL),2);
   BOOST_CHECK_EQUAL(buffer.at(2UL),3);
   BOOST_CHECK_THROW( buffer.at(3UL), std::out_of_range );
}

#endif //EXERCISM_RUN_ALL_TESTS
