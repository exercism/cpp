#include "twelve_days.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("first day a partridge in a pear tree",
          "[c0b5a5e6-c89d-49b1-a6b2-9f523bff33f7]") {
    std::string const expected =
        "On the first day of Christmas my true love gave to me: a Partridge in "
        "a Pear Tree.\n";
    REQUIRE(expected == twelve_days::recite(1, 1));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("second day two turtle doves",
          "[1c64508a-df3d-420a-b8e1-fe408847854a]") {
    std::string const expected =
        "On the second day of Christmas my true love gave to me: two Turtle "
        "Doves, and a Partridge in a Pear Tree.\n";
    REQUIRE(expected == twelve_days::recite(2, 2));
}

TEST_CASE("third day three french hens",
          "[a919e09c-75b2-4e64-bb23-de4a692060a8]") {
    std::string const expected =
        "On the third day of Christmas my true love gave to me: three French "
        "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n";
    REQUIRE(expected == twelve_days::recite(3, 3));
}

TEST_CASE("fourth day four calling birds",
          "[9bed8631-ec60-4894-a3bb-4f0ec9fbe68d]") {
    std::string const expected =
        "On the fourth day of Christmas my true love gave to me: four Calling "
        "Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear "
        "Tree.\n";
    REQUIRE(expected == twelve_days::recite(4, 4));
}

TEST_CASE("fifth day five gold rings",
          "[cf1024f0-73b6-4545-be57-e9cea565289a]") {
    std::string const expected =
        "On the fifth day of Christmas my true love gave to me: five Gold "
        "Rings, four Calling Birds, three French Hens, two Turtle Doves, and a "
        "Partridge in a Pear Tree.\n";
    REQUIRE(expected == twelve_days::recite(5, 5));
}

TEST_CASE("sixth day six geese-a-laying",
          "[50bd3393-868a-4f24-a618-68df3d02ff04]") {
    std::string const expected =
        "On the sixth day of Christmas my true love gave to me: six "
        "Geese-a-Laying, five Gold Rings, four Calling Birds, three French "
        "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n";
    REQUIRE(expected == twelve_days::recite(6, 6));
}

TEST_CASE("seventh day seven swans-a-swimming",
          "[8f29638c-9bf1-4680-94be-e8b84e4ade83]") {
    std::string const expected =
        "On the seventh day of Christmas my true love gave to me: seven "
        "Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling "
        "Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear "
        "Tree.\n";
    REQUIRE(expected == twelve_days::recite(7, 7));
}

TEST_CASE("eighth day eight maids-a-milking",
          "[7038d6e1-e377-47ad-8c37-10670a05bc05]") {
    std::string const expected =
        "On the eighth day of Christmas my true love gave to me: eight "
        "Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five "
        "Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, "
        "and a Partridge in a Pear Tree.\n";
    REQUIRE(expected == twelve_days::recite(8, 8));
}

TEST_CASE("ninth day nine ladies dancing",
          "[37a800a6-7a56-4352-8d72-0f51eb37cfe8]") {
    std::string const expected =
        "On the ninth day of Christmas my true love gave to me: nine Ladies "
        "Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six "
        "Geese-a-Laying, five Gold Rings, four Calling Birds, three French "
        "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n";
    REQUIRE(expected == twelve_days::recite(9, 9));
}

TEST_CASE("tenth day ten lords-a-leaping",
          "[10b158aa-49ff-4b2d-afc3-13af9133510d]") {
    std::string const expected =
        "On the tenth day of Christmas my true love gave to me: ten "
        "Lords-a-Leaping, nine Ladies Dancing, eight Maids-a-Milking, seven "
        "Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling "
        "Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear "
        "Tree.\n";
    REQUIRE(expected == twelve_days::recite(10, 10));
}

TEST_CASE("eleventh day eleven pipers piping",
          "[08d7d453-f2ba-478d-8df0-d39ea6a4f457]") {
    std::string const expected =
        "On the eleventh day of Christmas my true love gave to me: eleven "
        "Pipers Piping, ten Lords-a-Leaping, nine Ladies Dancing, eight "
        "Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five "
        "Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, "
        "and a Partridge in a Pear Tree.\n";
    REQUIRE(expected == twelve_days::recite(11, 11));
}

TEST_CASE("twelfth day twelve drummers drumming",
          "[0620fea7-1704-4e48-b557-c05bf43967f0]") {
    std::string const expected =
        "On the twelfth day of Christmas my true love gave to me: twelve "
        "Drummers Drumming, eleven Pipers Piping, ten Lords-a-Leaping, nine "
        "Ladies Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six "
        "Geese-a-Laying, five Gold Rings, four Calling Birds, three French "
        "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n";
    REQUIRE(expected == twelve_days::recite(12, 12));
}

TEST_CASE("recites first three verses of the song",
          "[da8b9013-b1e8-49df-b6ef-ddec0219e398]") {
    std::string const expected =
        "On the first day of Christmas my true love gave to me: a Partridge in "
        "a Pear Tree.\n"
        "\n"
        "On the second day of Christmas my true love gave to me: two Turtle "
        "Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the third day of Christmas my true love gave to me: three French "
        "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n";
    REQUIRE(expected == twelve_days::recite(1, 3));
}

TEST_CASE("recites three verses from the middle of the song",
          "[c095af0d-3137-4653-ad32-bfb899eda24c]") {
    std::string const expected =
        "On the fourth day of Christmas my true love gave to me: four Calling "
        "Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear "
        "Tree.\n"
        "\n"
        "On the fifth day of Christmas my true love gave to me: five Gold "
        "Rings, four Calling Birds, three French Hens, two Turtle Doves, and a "
        "Partridge in a Pear Tree.\n"
        "\n"
        "On the sixth day of Christmas my true love gave to me: six "
        "Geese-a-Laying, five Gold Rings, four Calling Birds, three French "
        "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n";
    REQUIRE(expected == twelve_days::recite(4, 6));
}

TEST_CASE("recites the whole song", "[20921bc9-cc52-4627-80b3-198cbbfcf9b7]") {
    std::string const expected =
        "On the first day of Christmas my true love gave to me: a Partridge in "
        "a Pear Tree.\n"
        "\n"
        "On the second day of Christmas my true love gave to me: two Turtle "
        "Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the third day of Christmas my true love gave to me: three French "
        "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the fourth day of Christmas my true love gave to me: four Calling "
        "Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear "
        "Tree.\n"
        "\n"
        "On the fifth day of Christmas my true love gave to me: five Gold "
        "Rings, four Calling Birds, three French Hens, two Turtle Doves, and a "
        "Partridge in a Pear Tree.\n"
        "\n"
        "On the sixth day of Christmas my true love gave to me: six "
        "Geese-a-Laying, five Gold Rings, four Calling Birds, three French "
        "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the seventh day of Christmas my true love gave to me: seven "
        "Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling "
        "Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear "
        "Tree.\n"
        "\n"
        "On the eighth day of Christmas my true love gave to me: eight "
        "Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five "
        "Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, "
        "and a Partridge in a Pear Tree.\n"
        "\n"
        "On the ninth day of Christmas my true love gave to me: nine Ladies "
        "Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six "
        "Geese-a-Laying, five Gold Rings, four Calling Birds, three French "
        "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"
        "\n"
        "On the tenth day of Christmas my true love gave to me: ten "
        "Lords-a-Leaping, nine Ladies Dancing, eight Maids-a-Milking, seven "
        "Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling "
        "Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear "
        "Tree.\n"
        "\n"
        "On the eleventh day of Christmas my true love gave to me: eleven "
        "Pipers Piping, ten Lords-a-Leaping, nine Ladies Dancing, eight "
        "Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five "
        "Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, "
        "and a Partridge in a Pear Tree.\n"
        "\n"
        "On the twelfth day of Christmas my true love gave to me: twelve "
        "Drummers Drumming, eleven Pipers Piping, ten Lords-a-Leaping, nine "
        "Ladies Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six "
        "Geese-a-Laying, five Gold Rings, four Calling Birds, three French "
        "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n";
    REQUIRE(expected == twelve_days::recite(1, 12));
}
#endif
