#include "list_ops.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


TEST_CASE("append: empty lists", "[485b9452-bf94-40f7-a3db-c3cf4850066a]") {
	std::vector<int> left{};
	std::vector<int> right{};
	list_ops::append(left, right);

	std::vector<int> expected{};
	REQUIRE(left == expected);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("append: list to empty list", "[2c894696-b609-4569-b149-8672134d340a]") {
	std::vector<int> left{};
	std::vector<int> right{1, 2, 3, 4};
	list_ops::append(left, right);

	std::vector<int> expected{1, 2, 3, 4};
	REQUIRE(left == expected);
}

TEST_CASE("append: empty list to list", "[e842efed-3bf6-4295-b371-4d67a4fdf19c]") {
	std::vector<int> left{1, 2, 3, 4};
	std::vector<int> right{};
	list_ops::append(left, right);

	std::vector<int> expected{1, 2, 3, 4};
	REQUIRE(left == expected);
}

TEST_CASE("append: non-empty lists", "[71dcf5eb-73ae-4a0e-b744-a52ee387922f]") {
	std::vector<int> left{1, 2};
	std::vector<int> right{2, 3, 4, 5};
	list_ops::append(left, right);

	std::vector<int> expected{1, 2, 2, 3, 4, 5};
	REQUIRE(left == expected);
}

TEST_CASE("concat: empty list", "[28444355-201b-4af2-a2f6-5550227bde21]") {
	std::vector<std::vector<int>> input{};
	auto result {list_ops::concat(input)};

	std::vector<int> expected{};
	REQUIRE(result == expected);
}

TEST_CASE("concat: list of lists", "[331451c1-9573-42a1-9869-2d06e3b389a9]") {
	std::vector<std::vector<int>> input{{1, 2}, {3}, {}, {4, 5, 6}};
	auto result {list_ops::concat(input)};

	std::vector<int> expected{1, 2, 3, 4, 5, 6};
	REQUIRE(result == expected);
}

TEST_CASE("concat: list of nested lists", "[d6ecd72c-197f-40c3-89a4-aa1f45827e09]") {
	std::vector<std::vector<std::vector<int>>> input{{{1}, {2}}, {{3}}, {{}}, {{4, 5, 6}}};
	auto result {list_ops::concat(input)};

	std::vector<std::vector<int>> expected{{1}, {2}, {3}, {}, {4, 5, 6}};
	REQUIRE(result == expected);
}

TEST_CASE("filter: empty list", "[0524fba8-3e0f-4531-ad2b-f7a43da86a16]") {
	std::vector<int> input{};
	auto lambda_func = [] (int x) { return x % 2 == 1;};
	auto result {list_ops::filter(input, lambda_func)};

	std::vector<int> expected{};
	REQUIRE(result == expected);
}

TEST_CASE("filter: non-empty list", "[88494bd5-f520-4edb-8631-88e415b62d24]") {
	std::vector<int> input{1, 2, 3, 5};
	auto lambda_func = [] (int x) { return x % 2 == 1;};
	auto result {list_ops::filter(input, lambda_func)};

	std::vector<int> expected{1, 3, 5};
	REQUIRE(result == expected);
}

TEST_CASE("length: empty list", "[1cf0b92d-8d96-41d5-9c21-7b3c37cb6aad]") {
	std::vector<int> input{};
	auto result {list_ops::length(input)};
	size_t expected{0};

	REQUIRE(result == expected);
}

TEST_CASE("length: non-empty list", "[d7b8d2d9-2d16-44c4-9a19-6e5f237cb71e]") {
	std::vector<int> input{1, 2, 3, 4};
	auto result {list_ops::length(input)};
	size_t expected{4};

	REQUIRE(result == expected);
}

TEST_CASE("map: empty list", "[c0bc8962-30e2-4bec-9ae4-668b8ecd75aa]") {
	std::vector<int> input{};
	auto lambda_func = [] (int x) { return x + 1;};
	auto result {list_ops::map(input, lambda_func)};

	std::vector<int> expected{};
	REQUIRE(result == expected);
}

TEST_CASE("map: non-empty list", "[11e71a95-e78b-4909-b8e4-60cdcaec0e91]") {
	std::vector<int> input{1, 3, 5, 7};
	auto lambda_func = [] (int x) { return x + 1;};
	auto result {list_ops::map(input, lambda_func)};

	std::vector<int> expected{2, 4, 6, 8};
	REQUIRE(result == expected);
}

TEST_CASE("foldl: empty list", "[36549237-f765-4a4c-bfd9-5d3a8f7b07d2]") {
	std::vector<int> input{};
	auto lambda_func = [] (int x, int y) { return x * y;};
	auto result {list_ops::foldl(input, 2, lambda_func)};

	int expected{2};
	REQUIRE(result == expected);
}

TEST_CASE("foldl: direction independent function applied to non-empty list", "[7a626a3c-03ec-42bc-9840-53f280e13067]") {
	std::vector<int> input{1, 2, 3, 4};
	auto lambda_func = [] (int x, int y) { return x + y;};
	auto result {list_ops::foldl(input, 5, lambda_func)};

	int expected{15};
	REQUIRE(result == expected);
}

TEST_CASE("foldl: direction dependent function applied to non-empty list", "[d7fcad99-e88e-40e1-a539-4c519681f390]") {
	std::vector<double> input{1.0, 2.0, 3.0, 4.0};
	auto lambda_func = [] (double acc, double el) { return el / acc;};
	auto result {list_ops::foldl(input, 24.0, lambda_func)};

	double expected{64.0};
	REQUIRE(result == expected);
}

TEST_CASE("foldr: empty list", "[17214edb-20ba-42fc-bda8-000a5ab525b0]") {
	std::vector<int> input{};
	auto lambda_func = [] (int acc, int el) { return el * acc;};
	auto result {list_ops::foldr(input, 2, lambda_func)};

	int expected{2};
	REQUIRE(result == expected);
}

TEST_CASE("foldr: direction independent function applied to non-empty list", "[e1c64db7-9253-4a3d-a7c4-5273b9e2a1bd]") {
	std::vector<int> input{1, 2, 3, 4};
	auto lambda_func = [] (int acc, int el) { return el + acc;};
	auto result {list_ops::foldr(input, 5, lambda_func)};

	int expected{15};
	REQUIRE(result == expected);
}

TEST_CASE("foldr: direction dependent function applied to non-empty list", "[8066003b-f2ff-437e-9103-66e6df474844]") {
	std::vector<double> input{1.0, 2.0, 3.0, 4.0};
	auto lambda_func = [] (double acc, double el) { return el / acc;};
	auto result {list_ops::foldr(input, 24.0, lambda_func)};

	double expected{9.0};
	REQUIRE(result == expected);
}

TEST_CASE("reverse: empty list", "[94231515-050e-4841-943d-d4488ab4ee30]") {
	std::vector<int> input{};
	auto result {list_ops::reverse(input)};

	std::vector<int> expected{};
	REQUIRE(result == expected);
}

TEST_CASE("reverse: non-empty list", "[fcc03d1e-42e0-4712-b689-d54ad761f360]") {
	std::vector<int> input{1, 3, 5, 7};
	auto result {list_ops::reverse(input)};

	std::vector<int> expected{7, 5, 3, 1};
	REQUIRE(result == expected);
}

TEST_CASE("reverse: list of lists is not flattened", "[40872990-b5b8-4cb8-9085-d91fc0d05d26]") {
	std::vector<std::vector<int>> input{{1, 2}, {3}, {}, {4, 5, 6}};
	auto result {list_ops::reverse(input)};

	std::vector<std::vector<int>> expected{{4, 5, 6,}, {}, {3}, {1, 2}};
	REQUIRE(result == expected);
	//REQUIRE({[4, 5, 6], [], [3], [1, 2]} == list_ops::reverse({[1, 2], [3], [], [4, 5, 6]}));
}

#endif
