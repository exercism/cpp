#include "diamond.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


/*
 The tests contained within this canonical data file are suitable   
 for value-based testing, in which each test case checks that the   
 value returned by the function under test is in every way          
 identical to a given expected value.                               
                                                                    
 This exercise is also amenable to property-based testing, in which 
 each test case verifies that the value returned by the function    
 under test exhibits a specific desired property.                   
                                                                    
 Several tracks (notably, C# and Go) forgo the value-based tests    
 below in favor of property-based tests. If you are feeling         
 adventurous and would like to use this exercise to introduce the   
 concept of property-based testing to participants in your track,   
 please ignore the value-based tests below and instead reference    
 the test suites in the aforementioned tracks.                      
*/

TEST_CASE("Degenerate case with a single 'A' row", "[202fb4cc-6a38-4883-9193-a29d5cb92076]") {
	std::vector<std::string> expected{"A"};
	REQUIRE(diamond::rows('A') == expected);
}



TEST_CASE("Degenerate case with no row containing 3 distinct groups of spaces", "[bd6a6d78-9302-42e9-8f60-ac1461e9abae]") {
	std::vector<std::string> expected{" A ",
									  "B B",
									  " A "};
	REQUIRE(diamond::rows('B') == expected);
}

TEST_CASE("Smallest non-degenerate case with odd diamond side length", "[af8efb49-14ed-447f-8944-4cc59ce3fd76]") {
	std::vector<std::string> expected{"  A  ",
									  " B B ",
									  "C   C",
									  " B B ",
									  "  A  "};
	REQUIRE(diamond::rows('C') == expected);
}

TEST_CASE("Smallest non-degenerate case with even diamond side length", "[e0c19a95-9888-4d05-86a0-fa81b9e70d1d]") {
	std::vector<std::string> expected{"   A   ",
									  "  B B  ",
									  " C   C ",
									  "D     D",
									  " C   C ",
									  "  B B  ",
									  "   A   "};
	REQUIRE(diamond::rows('D') == expected);
}

TEST_CASE("Largest possible diamond", "[82ea9aa9-4c0e-442a-b07e-40204e925944]") {
	std::vector<std::string> expected{"                         A                         ",
	                                  "                        B B                        ",
									  "                       C   C                       ",
									  "                      D     D                      ",
									  "                     E       E                     ",
									  "                    F         F                    ",
									  "                   G           G                   ",
									  "                  H             H                  ",
									  "                 I               I                 ",
									  "                J                 J                ",
									  "               K                   K               ",
									  "              L                     L              ",
									  "             M                       M             ",
									  "            N                         N            ",
									  "           O                           O           ",
									  "          P                             P          ",
									  "         Q                               Q         ",
									  "        R                                 R        ",
									  "       S                                   S       ",
									  "      T                                     T      ",
									  "     U                                       U     ",
									  "    V                                         V    ",
									  "   W                                           W   ",
									  "  X                                             X  ",
									  " Y                                               Y ",
									  "Z                                                 Z",
									  " Y                                               Y ",
									  "  X                                             X  ",
									  "   W                                           W   ",
									  "    V                                         V    ",
									  "     U                                       U     ",
									  "      T                                     T      ",
									  "       S                                   S       ",
									  "        R                                 R        ",
									  "         Q                               Q         ",
									  "          P                             P          ",
									  "           O                           O           ",
									  "            N                         N            ",
									  "             M                       M             ",
									  "              L                     L              ",
									  "               K                   K               ",
									  "                J                 J                ",
									  "                 I               I                 ",
									  "                  H             H                  ",
									  "                   G           G                   ",
									  "                    F         F                    ",
									  "                     E       E                     ",
									  "                      D     D                      ",
									  "                       C   C                       ", 
									  "                        B B                        ",
									  "                         A                         "};
	REQUIRE(diamond::rows('Z') == expected);
}
#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
