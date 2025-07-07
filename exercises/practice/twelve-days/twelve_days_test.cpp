#include "twelve_days.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;

TEST_CASE("verse_first_day_a_partridge_in_a_pear_tree", "[c0b5a5e6-c89d-49b1-a6b2-9f523bff33f7]") {
    string expected = "On the first day of Christmas my true love gave to me: a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::verse(1));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("verse_second_day_two_turtle_doves", "[1c64508a-df3d-420a-b8e1-fe408847854a]") {
    string expected = "On the second day of Christmas my true love gave to me: two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::verse(2));
}

TEST_CASE("verse_third_day_three_french_hens", "[a919e09c-75b2-4e64-bb23-de4a692060a8]") {
    string expected = "On the third day of Christmas my true love gave to me: three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::verse(3));
}

TEST_CASE("verse_fourth_day_four_calling_birds", "[9bed8631-ec60-4894-a3bb-4f0ec9fbe68d]") {
    string expected = "On the fourth day of Christmas my true love gave to me: four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::verse(4));
}

TEST_CASE("verse_fifth_day_five_gold_rings", "[cf1024f0-73b6-4545-be57-e9cea565289a]") {
    string expected = "On the fifth day of Christmas my true love gave to me: five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::verse(5));
}

TEST_CASE("verse_sixth_day_six_geese_a_laying", "[50bd3393-868a-4f24-a618-68df3d02ff04]") {
    string expected = "On the sixth day of Christmas my true love gave to me: six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::verse(6));
}

TEST_CASE("verse_seventh_day_seven_swans_a_swimming", "[8f29638c-9bf1-4680-94be-e8b84e4ade83]") {
    string expected = "On the seventh day of Christmas my true love gave to me: seven Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::verse(7));
}

TEST_CASE("verse_eighth_day_eight_maids_a_milking", "[7038d6e1-e377-47ad-8c37-10670a05bc05]") {
    string expected = "On the eighth day of Christmas my true love gave to me: eight Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::verse(8));
}

TEST_CASE("verse_ninth_day_nine_ladies_dancing", "[37a800a6-7a56-4352-8d72-0f51eb37cfe8]") {
    string expected = "On the ninth day of Christmas my true love gave to me: nine Ladies Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::verse(9));
}

TEST_CASE("verse_tenth_day_ten_lords_a_leaping", "[10b158aa-49ff-4b2d-afc3-13af9133510d]") {
    string expected = "On the tenth day of Christmas my true love gave to me: ten Lords-a-Leaping, nine Ladies Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::verse(10));
}

TEST_CASE("verse_eleventh_day_eleven_pipers_piping", "[08d7d453-f2ba-478d-8df0-d39ea6a4f457]") {
    string expected = "On the eleventh day of Christmas my true love gave to me: eleven Pipers Piping, ten Lords-a-Leaping, nine Ladies Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::verse(11));
}

TEST_CASE("verse_twelfth_day_twelve_drummers_drumming", "[0620fea7-1704-4e48-b557-c05bf43967f0]") {
    string expected = "On the twelfth day of Christmas my true love gave to me: twelve Drummers Drumming, eleven Pipers Piping, ten Lords-a-Leaping, nine Ladies Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::verse(12));
}

TEST_CASE("lyrics_recites_first_three_verses_of_the_song", "[da8b9013-b1e8-49df-b6ef-ddec0219e398]") {
    string expected = 
        "On the first day of Christmas my true love gave to me: a Partridge in a Pear Tree.\n"
        "\n"
        "On the second day of Christmas my true love gave to me: two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the third day of Christmas my true love gave to me: three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::lyrics(1, 3));
}

TEST_CASE("lyrics_recites_three_verses_from_the_middle_of_the_song", "[c095af0d-3137-4653-ad32-bfb899eda24c]") {
    string expected = 
        "On the fourth day of Christmas my true love gave to me: four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the fifth day of Christmas my true love gave to me: five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the sixth day of Christmas my true love gave to me: six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::lyrics(4, 6));
}

TEST_CASE("lyrics_recites_the_whole_song", "[20921bc9-cc52-4627-80b3-198cbbfcf9b7]") {
    string expected = 
        "On the first day of Christmas my true love gave to me: a Partridge in a Pear Tree.\n"
        "\n"
        "On the second day of Christmas my true love gave to me: two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the third day of Christmas my true love gave to me: three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the fourth day of Christmas my true love gave to me: four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the fifth day of Christmas my true love gave to me: five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the sixth day of Christmas my true love gave to me: six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the seventh day of Christmas my true love gave to me: seven Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the eighth day of Christmas my true love gave to me: eight Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the ninth day of Christmas my true love gave to me: nine Ladies Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the tenth day of Christmas my true love gave to me: ten Lords-a-Leaping, nine Ladies Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the eleventh day of Christmas my true love gave to me: eleven Pipers Piping, ten Lords-a-Leaping, nine Ladies Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the twelfth day of Christmas my true love gave to me: twelve Drummers Drumming, eleven Pipers Piping, ten Lords-a-Leaping, nine Ladies Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear Tree.";
    REQUIRE(expected == twelve_days::lyrics(12));
}
#endif
