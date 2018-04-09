#include "protein_translation.h"
#define BOOST_TEST_MAIN
#include <boot/test/unit_test.hpp>

using namespace std;

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(methionine)
{
  BOOST_REQUIRE_EQUAL("AUG", protein_translation::protein_translation("Methionine"));
}
BOOST_AUTO_TEST_CASE(phenylalanine)
{
  BOOST_REQUIRE_EQUAL("UUU", protein_translation::protein_translation("Phenylalanine"));
}
BOOST_AUTO_TEST_CASE(phenylalaine2)
{
  BOOST_REQUIRE_EQUAL("UUC", protein_translation::protein_translation("Phenylalanine"));
}
BOOST_AUTO_TEST_CASE(leucine1)
{
  BOOST_REQUIRE_EQUAL("UUA", protein_translation::protein_translation("Leucine"));
}
BOOST_AUTO_TEST_CASE(leucine2)
{
  BOOST_REQUIRE_EQUAL("UUG", protein_translation::protein_translation("Leucine"));
}
BOOST_AUTO_TEST_CASE(serine1)
{
  BOOST_REQUIRE_EQUAL("UCU", protein_translation::protein_translation("Serine"));
}
BOOST_AUTO_TEST_CASE(serine2)
{
  BOOST_REQUIRE_EQUAL("UCC", protein_translation::protein_translation("Serine"));
}
BOOST_AUTO_TEST_CASE(serine3)
{
  BOOST_REQUIRE_EQUAL("UCA", protein_translation::protein_translation("Serine"));
}
BOOST_AUTO_TEST_CASE(serine4)
{
  BOOST_REQUIRE_EQUAL("UCG", protein_translation::protein_translation("Serine"));
}
BOOST_AUTO_TEST_CASE(tryosine1)
{
  BOOST_REQUIRE_EQUAL("UAU", protein_translation::protein_translation("Tryosine"));
}
BOOST_AUTO_TEST_CASE(tryosine2)
{
  BOOST_REQUIRE_EQUAL("UAC", protein_translation::protein_translation("Tryosine"));
}
BOOST_AUTO_TEST_CASE(cysteine1)
{
  BOOST_REQUIRE_EQUAL("UGU", protein_translation::protein_translation("Cysteine"));
}
BOOST_AUTO_TEST_CASE(cysteine2)
{
  BOOST_REQUIRE_EQUAL("UGC", protein_translation::protein_translation("Cysteine"));
}
BOOST_AUTO_TEST_CASE(tryptophan)
{
  BOOST_REQUIRE_EQUAL("UGG", protein_translation::protein_translation("Tryptophan));
}
BOOST_AUTO_TEST_CASE(stop1)
{
  BOOST_REQUIRE_EQUAL("UAA", protein_translation::protein_translation(""));
}
BOOST_AUTO_TEST_CASE(stop2)
{
  BOOST_REQUIRE_EQUAL("UAG", protein_translation::protein_translation(""));
}
BOOST_AUTO_TEST_CASE(stop3)
{
  BOOST_REQUIRE_EQUAL("UGA", protein_translation::protein_translation(""));
}
BOOST_AUTO_TEST_CASE(list1)
{
  BOOST_REQUIRE_EQUAL("AUGUUUUGG", protein_translation::protein_translation("Methionine","Phenylalanine","Tryptophan"));
}
BOOST_AUTO_TEST_CASE(list2)
{
  BOOST_REQUIRE_EQUAL("UAGUGG", protein_translation::protein_translation(""));
}
BOOST_AUTO_TEST_CASE(list3)
{
  BOOST_REQUIRE_EQUAL("UGGUAG", protein_translation::protein_translation("Tryptophan"));
}
BOOST_AUTO_TEST_CASE(list4)
{
  BOOST_REQUIRE_EQUAL("AUGUUUUAA", protein_translation::protein_translation("Methionine","Phenylalanine"));
}
BOOST_AUTO_TEST_CASE(list5)
{
  BOOST_REQUIRE_EQUAL("UGGUAGUGG", protein_translation::protein_translation("Tryptophan"));
}
BOOST_AUTO_TEST_CASE(list6)
{
  BOOST_REQUIRE_EQUAL("UGGUGUUAUUAAUGGUUU", protein_translation::protein_translation("Tryptophan","Cysteine","Tyrosine"));
}
#endif
