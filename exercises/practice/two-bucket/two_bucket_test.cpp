#include "two_bucket.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

CATCH_REGISTER_ENUM(two_bucket::bucket_id,
        two_bucket::bucket_id::one,
        two_bucket::bucket_id::two)

TEST_CASE("Measure using bucket one of size 3 and bucket two of size 5 - start with bucket one", "[a6f2b4ba-065f-4dca-b6f0-e3eee51cb661]")
{
    auto bucket1_capacity = 3;
    auto bucket2_capacity = 5;
    auto goal_volume = 1;
    auto start_bucket = two_bucket::bucket_id::one;

    auto actual = two_bucket::measure(
            bucket1_capacity, bucket2_capacity,
            goal_volume, start_bucket);

    CHECK(actual.num_moves == 4);
    CHECK(actual.goal_bucket == two_bucket::bucket_id::one);
    CHECK(actual.other_bucket_volume == 5);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Measure using bucket one of size 3 and bucket two of size 5 - start with bucket two", "[6c4ea451-9678-4926-b9b3-68364e066d40]")
{
    auto bucket1_capacity = 3;
    auto bucket2_capacity = 5;
    auto goal_volume = 1;
    auto start_bucket = two_bucket::bucket_id::two;

    auto actual = two_bucket::measure(
            bucket1_capacity, bucket2_capacity,
            goal_volume, start_bucket);

    CHECK(actual.num_moves == 8);
    CHECK(actual.goal_bucket == two_bucket::bucket_id::two);
    CHECK(actual.other_bucket_volume == 3);
}

TEST_CASE("Measure using bucket one of size 7 and bucket two of size 11 - start with bucket one", "[3389f45e-6a56-46d5-9607-75aa930502ff]")
{
    auto bucket1_capacity = 7;
    auto bucket2_capacity = 11;
    auto goal_volume = 2;
    auto start_bucket = two_bucket::bucket_id::one;

    auto actual = two_bucket::measure(
            bucket1_capacity, bucket2_capacity,
            goal_volume, start_bucket);

    CHECK(actual.num_moves == 14);
    CHECK(actual.goal_bucket == two_bucket::bucket_id::one);
    CHECK(actual.other_bucket_volume == 11);
}

TEST_CASE("Measure using bucket one of size 7 and bucket two of size 11 - start with bucket two", "[fe0ff9a0-3ea5-4bf7-b17d-6d4243961aa1]")
{
    auto bucket1_capacity = 7;
    auto bucket2_capacity = 11;
    auto goal_volume = 2;
    auto start_bucket = two_bucket::bucket_id::two;

    auto actual = two_bucket::measure(
            bucket1_capacity, bucket2_capacity,
            goal_volume, start_bucket);

    CHECK(actual.num_moves == 18);
    CHECK(actual.goal_bucket == two_bucket::bucket_id::two);
    CHECK(actual.other_bucket_volume == 7);
}

TEST_CASE("Measure one step using bucket one of size 1 and bucket two of size 3 - start with bucket two", "[0ee1f57e-da84-44f7-ac91-38b878691602]")
{
    auto bucket1_capacity = 1;
    auto bucket2_capacity = 3;
    auto goal_volume = 3;
    auto start_bucket = two_bucket::bucket_id::two;

    auto actual = two_bucket::measure(
            bucket1_capacity, bucket2_capacity,
            goal_volume, start_bucket);

    CHECK(actual.num_moves == 1);
    CHECK(actual.goal_bucket == two_bucket::bucket_id::two);
    CHECK(actual.other_bucket_volume == 0);
}

TEST_CASE("Measure using bucket one of size 2 and bucket two of size 3 - start with bucket one and end with bucket two", "[eb329c63-5540-4735-b30b-97f7f4df0f84]")
{
    auto bucket1_capacity = 2;
    auto bucket2_capacity = 3;
    auto goal_volume = 3;
    auto start_bucket = two_bucket::bucket_id::one;

    auto actual = two_bucket::measure(
            bucket1_capacity, bucket2_capacity,
            goal_volume, start_bucket);

    CHECK(actual.num_moves == 2);
    CHECK(actual.goal_bucket == two_bucket::bucket_id::two);
    CHECK(actual.other_bucket_volume == 2);
}

TEST_CASE("Not possible to reach the goal", "[449be72d-b10a-4f4b-a959-ca741e333b72]")
{
    auto bucket1_capacity = 6;
    auto bucket2_capacity = 15;
    auto goal_volume = 5;
    auto start_bucket = two_bucket::bucket_id::one;

    REQUIRE_THROWS(two_bucket::measure(
            bucket1_capacity, bucket2_capacity,
            goal_volume, start_bucket));
}

TEST_CASE("With the same buckets but a different goal, then it is possible", "[aac38b7a-77f4-4d62-9b91-8846d533b054]")
{
    auto bucket1_capacity = 6;
    auto bucket2_capacity = 15;
    auto goal_volume = 9;
    auto start_bucket = two_bucket::bucket_id::one;

    auto actual = two_bucket::measure(
            bucket1_capacity, bucket2_capacity,
            goal_volume, start_bucket);

    CHECK(actual.num_moves == 10);
    CHECK(actual.goal_bucket == two_bucket::bucket_id::two);
    CHECK(actual.other_bucket_volume == 0);
}

TEST_CASE("Goal larger than both buckets is impossible", "[74633132-0ccf-49de-8450-af4ab2e3b299]")
{
    auto bucket1_capacity = 5;
    auto bucket2_capacity = 7;
    auto goal_volume = 8;
    auto start_bucket = two_bucket::bucket_id::one;

    REQUIRE_THROWS(two_bucket::measure(
            bucket1_capacity, bucket2_capacity,
            goal_volume, start_bucket));
}

#endif  // EXERCISM_RUN_ALL_TESTS
