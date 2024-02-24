#include "dnd_character.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

#include <sstream>

using namespace Catch;
using namespace Catch::Matchers;

template <typename T>
class IsBetweenMatcher : public MatcherBase<T> {
    T m_begin, m_end;
public:
    IsBetweenMatcher(T begin, T end) :
        m_begin(begin), m_end(end) {
    }
    bool match(T const& in) const override {
        return in >= m_begin && in <= m_end;
    }
    std::string describe() const override {
        std::ostringstream ss;
        ss << "should be between " << m_begin << " and " << m_end;
        return ss.str();
    }
};

TEST_CASE("ability modifier for score 3 is -4", "[1e9ae1dc-35bd-43ba-aa08-e4b94c20fa37]") {
	REQUIRE(-4 == dnd_character::modifier(3));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("ability modifier for score 4 is -3", "[cc9bb24e-56b8-4e9e-989d-a0d1a29ebb9c]") {
	REQUIRE(-3 == dnd_character::modifier(4));
}

TEST_CASE("ability modifier for score 5 is -3", "[5b519fcd-6946-41ee-91fe-34b4f9808326]") {
	REQUIRE(-3 == dnd_character::modifier(5));
}

TEST_CASE("ability modifier for score 6 is -2", "[dc2913bd-6d7a-402e-b1e2-6d568b1cbe21]") {
	REQUIRE(-2 == dnd_character::modifier(6));
}

TEST_CASE("ability modifier for score 7 is -2", "[099440f5-0d66-4b1a-8a10-8f3a03cc499f]") {
	REQUIRE(-2 == dnd_character::modifier(7));
}

TEST_CASE("ability modifier for score 8 is -1", "[cfda6e5c-3489-42f0-b22b-4acb47084df0]") {
	REQUIRE(-1 == dnd_character::modifier(8));
}

TEST_CASE("ability modifier for score 9 is -1", "[c70f0507-fa7e-4228-8463-858bfbba1754]") {
	REQUIRE(-1 == dnd_character::modifier(9));
}

TEST_CASE("ability modifier for score 10 is 0", "[6f4e6c88-1cd9-46a0-92b8-db4a99b372f7]") {
	REQUIRE(0 == dnd_character::modifier(10));
}

TEST_CASE("ability modifier for score 11 is 0", "[e00d9e5c-63c8-413f-879d-cd9be9697097]") {
	REQUIRE(0 == dnd_character::modifier(11));
}

TEST_CASE("ability modifier for score 12 is +1", "[eea06f3c-8de0-45e7-9d9d-b8cab4179715]") {
	REQUIRE(1 == dnd_character::modifier(12));
}

TEST_CASE("ability modifier for score 13 is +1", "[9c51f6be-db72-4af7-92ac-b293a02c0dcd]") {
	REQUIRE(1 == dnd_character::modifier(13));
}

TEST_CASE("ability modifier for score 14 is +2", "[94053a5d-53b6-4efc-b669-a8b5098f7762]") {
	REQUIRE(2 == dnd_character::modifier(14));
}

TEST_CASE("ability modifier for score 15 is +2", "[8c33e7ca-3f9f-4820-8ab3-65f2c9e2f0e2]") {
	REQUIRE(2 == dnd_character::modifier(15));
}

TEST_CASE("ability modifier for score 16 is +3", "[c3ec871e-1791-44d0-b3cc-77e5fb4cd33d]") {
	REQUIRE(3 == dnd_character::modifier(16));
}

TEST_CASE("ability modifier for score 17 is +3", "[3d053cee-2888-4616-b9fd-602a3b1efff4]") {
	REQUIRE(3 == dnd_character::modifier(17));
}

TEST_CASE("ability modifier for score 18 is +4", "[bafd997a-e852-4e56-9f65-14b60261faee]") {
	REQUIRE(4 == dnd_character::modifier(18));
}

TEST_CASE("random ability is within range", "[4f28f19c-2e47-4453-a46a-c0d365259c14]") {
	int result{dnd_character::ability()};
	CHECK_THAT(result, IsBetweenMatcher(3, 18));
}

TEST_CASE("random character is valid", "[385d7e72-864f-4e88-8279-81a7d75b04ad]") {
	dnd_character::Character character;
	CHECK_THAT(character.strength, IsBetweenMatcher(3, 18));
	CHECK_THAT(character.dexterity, IsBetweenMatcher(3, 18));
	CHECK_THAT(character.constitution, IsBetweenMatcher(3, 18));
	CHECK_THAT(character.intelligence, IsBetweenMatcher(3, 18));
	CHECK_THAT(character.wisdom, IsBetweenMatcher(3, 18));
	CHECK_THAT(character.charisma, IsBetweenMatcher(3, 18));
	REQUIRE(character.hitpoints == 10 + dnd_character::modifier(character.constitution));
}

#endif
