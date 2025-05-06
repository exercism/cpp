#include "relative_distance.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


TEST_CASE("Direct parent-child relation", "[4a1ded74-5d32-47fb-8ae5-321f51d06b5b]") {
	REQUIRE(1 == relative_distance::degreeOfSeparation("{'Vera': ['Tomoko'], 'Tomoko': ['Aditi']}", "Vera", "Tomoko"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Sibling relationship", "[30d17269-83e9-4f82-a0d7-8ef9656d8dce]") {
	REQUIRE(1 == relative_distance::degreeOfSeparation("{'Dalia': ['Olga', 'Yassin']}", "Olga", "Yassin"));
}

TEST_CASE("Two degrees of separation, grandchild", "[8dffa27d-a8ab-496d-80b3-2f21c77648b5]") {
	REQUIRE(2 == relative_distance::degreeOfSeparation("{'Khadija': ['Mateo'], 'Mateo': ['Rami']}", "Khadija", "Rami"));
}

TEST_CASE("Unrelated individuals", "[34e56ec1-d528-4a42-908e-020a4606ee60]") {
	REQUIRE("None" == relative_distance::degreeOfSeparation("{'Priya': ['Rami'], 'Kaito': ['Elif']}", "Priya", "Kaito"));
}

TEST_CASE("Complex graph, cousins", "[93ffe989-bad2-48c4-878f-3acb1ce2611b]") {
	REQUIRE(4 == relative_distance::degreeOfSeparation("{'Aiko': ['Bao', 'Carlos'], 'Bao': ['Dalia', 'Elias'], 'Carlos': ['Fatima', 'Gustavo'], 'Dalia': ['Hassan', 'Isla'], 'Elias': ['Javier'], 'Fatima': ['Khadija', 'Liam'], 'Gustavo': ['Mina'], 'Hassan': ['Noah', 'Olga'], 'Isla': ['Pedro'], 'Javier': ['Quynh', 'Ravi'], 'Khadija': ['Sofia'], 'Liam': ['Tariq', 'Uma'], 'Mina': ['Viktor', 'Wang'], 'Noah': ['Xiomara'], 'Olga': ['Yuki'], 'Pedro': ['Zane', 'Aditi'], 'Quynh': ['Boris'], 'Ravi': ['Celine'], 'Sofia': ['Diego', 'Elif'], 'Tariq': ['Farah'], 'Uma': ['Giorgio'], 'Viktor': ['Hana', 'Ian'], 'Wang': ['Jing'], 'Xiomara': ['Kaito'], 'Yuki': ['Leila'], 'Zane': ['Mateo'], 'Aditi': ['Nia'], 'Boris': ['Oscar'], 'Celine': ['Priya'], 'Diego': ['Qi'], 'Elif': ['Rami'], 'Farah': ['Sven'], 'Giorgio': ['Tomoko'], 'Hana': ['Umar'], 'Ian': ['Vera'], 'Jing': ['Wyatt'], 'Kaito': ['Xia'], 'Leila': ['Yassin'], 'Mateo': ['Zara'], 'Nia': ['Antonio'], 'Oscar': ['Bianca'], 'Priya': ['Cai'], 'Qi': ['Dimitri'], 'Rami': ['Ewa'], 'Sven': ['Fabio'], 'Tomoko': ['Gabriela'], 'Umar': ['Helena'], 'Vera': ['Igor'], 'Wyatt': ['Jun'], 'Xia': ['Kim'], 'Yassin': ['Lucia'], 'Zara': ['Mohammed']}", "Dimitri", "Fabio"));
}

TEST_CASE("Complex graph, no shortcut, far removed nephew", "[2cc2e76b-013a-433c-9486-1dbe29bf06e5]") {
	REQUIRE(15 == relative_distance::degreeOfSeparation("{'Aiko': ['Bao', 'Carlos'], 'Bao': ['Dalia', 'Elias'], 'Carlos': ['Fatima', 'Gustavo'], 'Dalia': ['Hassan', 'Isla'], 'Elias': ['Javier'], 'Fatima': ['Khadija', 'Liam'], 'Gustavo': ['Mina'], 'Hassan': ['Noah', 'Olga'], 'Isla': ['Pedro'], 'Javier': ['Quynh', 'Ravi'], 'Khadija': ['Sofia'], 'Liam': ['Tariq', 'Uma'], 'Mina': ['Viktor', 'Wang'], 'Noah': ['Xiomara'], 'Olga': ['Yuki'], 'Pedro': ['Zane', 'Aditi'], 'Quynh': ['Boris'], 'Ravi': ['Celine'], 'Sofia': ['Diego', 'Elif'], 'Tariq': ['Farah'], 'Uma': ['Giorgio'], 'Viktor': ['Hana', 'Ian'], 'Wang': ['Jing'], 'Xiomara': ['Kaito'], 'Yuki': ['Leila'], 'Zane': ['Mateo'], 'Aditi': ['Nia'], 'Boris': ['Oscar'], 'Celine': ['Priya'], 'Diego': ['Qi'], 'Elif': ['Rami'], 'Farah': ['Sven'], 'Giorgio': ['Tomoko'], 'Hana': ['Umar'], 'Ian': ['Vera'], 'Jing': ['Wyatt'], 'Kaito': ['Xia'], 'Leila': ['Yassin'], 'Mateo': ['Zara'], 'Nia': ['Antonio'], 'Oscar': ['Bianca'], 'Priya': ['Cai'], 'Qi': ['Dimitri'], 'Rami': ['Ewa'], 'Sven': ['Fabio'], 'Tomoko': ['Gabriela'], 'Umar': ['Helena'], 'Vera': ['Igor'], 'Wyatt': ['Jun'], 'Xia': ['Kim'], 'Yassin': ['Lucia'], 'Zara': ['Mohammed']}", "Lucia", "Jun"));
}

TEST_CASE("Complex graph, some shortcuts, cross-down and cross-up, cousins three times removed", "[46c9fbcb-e464-455f-a718-049ea3c7400a]") {
	REQUIRE(8 == relative_distance::degreeOfSeparation("{'Aiko': ['Bao', 'Carlos'], 'Bao': ['Dalia', 'Elias'], 'Carlos': ['Fatima', 'Gustavo'], 'Dalia': ['Hassan', 'Isla'], 'Elias': ['Javier'], 'Fatima': ['Khadija', 'Liam'], 'Gustavo': ['Mina'], 'Hassan': ['Noah', 'Olga'], 'Isla': ['Pedro'], 'Javier': ['Quynh', 'Ravi'], 'Khadija': ['Viktor'], 'Liam': ['Tariq', 'Uma'], 'Mina': ['Viktor', 'Wang'], 'Noah': ['Xiomara'], 'Olga': ['Yuki'], 'Pedro': ['Zane', 'Aditi'], 'Quynh': ['Boris'], 'Ravi': ['Celine'], 'Sofia': ['Diego', 'Elif'], 'Tariq': ['Farah'], 'Uma': ['Giorgio'], 'Viktor': ['Hana', 'Ian'], 'Wang': ['Jing'], 'Xiomara': ['Kaito'], 'Yuki': ['Leila'], 'Zane': ['Mateo'], 'Aditi': ['Nia'], 'Boris': ['Oscar'], 'Celine': ['Priya'], 'Diego': ['Qi'], 'Elif': ['Rami'], 'Farah': ['Sven'], 'Giorgio': ['Tomoko'], 'Hana': ['Umar'], 'Ian': ['Vera'], 'Jing': ['Wyatt'], 'Kaito': ['Xia'], 'Leila': ['Yassin'], 'Mateo': ['Zara'], 'Nia': ['Antonio'], 'Oscar': ['Bianca'], 'Priya': ['Cai'], 'Qi': ['Dimitri'], 'Rami': ['Ewa'], 'Sven': ['Fabio'], 'Tomoko': ['Gabriela'], 'Umar': ['Helena'], 'Vera': ['Igor'], 'Wyatt': ['Jun'], 'Xia': ['Kim'], 'Yassin': ['Lucia'], 'Zara': ['Mohammed']}", "Tomoko", "Qi"));
}

#endif
