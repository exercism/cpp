#include "CppUTest/TestHarness.h"

// Intentional #include of non-header file. To those learning C++,
// don't ever do this in a real project. Instead, #include only
// header files with some sort of header guard or pragma.
// Submit the following file to exercism:
#include "Hamming.cpp"

TEST_GROUP(HammingTestGroup)
{
};

TEST(HammingTestGroup, NoDifferenceBetweenEmptyStrands)
{
    CHECK_EQUAL(0, Compute("", ""));
}

TEST(HammingTestGroup, NoDifferenceBetweenIdenticalStrands)
{
    CHECK_EQUAL(0, Compute("A", "A"));
}

TEST(HammingTestGroup, CompleteDistanceForSingleNucleoTideStrands)
{
    CHECK_EQUAL(1, Compute("A", "G"));
}

TEST(HammingTestGroup, CompleteDistanceForSmallStrands)
{
    CHECK_EQUAL(2, Compute("AG", "CT"));
}

TEST(HammingTestGroup, SmallHammingDistance)
{
    CHECK_EQUAL(1, Compute("AT", "CT"));
}

TEST(HammingTestGroup, SmallHammingDistanceInLongerStrands)
{
    CHECK_EQUAL(1, Compute("GGACG", "GGTCG"));
}

TEST(HammingTestGroup, IgnoresExtraLengthOnFirstStrandWhenLonger)
{
    CHECK_EQUAL(1, Compute("AATG", "AAA"));
}

TEST(HammingTestGroup, IgnoresExtraLengthOnSecondStrandWhenLonger)
{
    CHECK_EQUAL(2, Compute("ATA", "AGTG"));
}

TEST(HammingTestGroup, LargeHammingDistance)
{
    CHECK_EQUAL(4, Compute("GATACA", "GCATAA"));
}

TEST(HammingTestGroup, HammingDistanceInVeryLongStrands)
{
    CHECK_EQUAL(9, Compute("GGACGGATTCTG", "AGGACGGATTCT"));
}

