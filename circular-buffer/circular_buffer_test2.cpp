#include "circular_buffer.hpp"

/**
* @file Including in a second .cpp to check for improper linkage in 
*     header-defined items, an extremely common problem on Exercism.
*/

#if defined(EXERCISM_RUN_ALL_TESTS)

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(initially_empty)
{
   containers::circular_buffer<int,9> buffer;
   BOOST_CHECK_MESSAGE( buffer.empty(), "A container which has had nothing added to it should be empty." );
}

#endif //EXERCISM_RUN_ALL_TESTS
