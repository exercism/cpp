#include "protein_translation.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(methionine)
{
  BOOST_REQUIRE_EQUAL("Methionine", protein_translation::protein_translation("AUG"));
}
BOOST_AUTO_TEST_CASE(phenylalanine)
{
  BOOST_REQUIRE_EQUAL("Phenylalanine", protein_translation::protein_translation("UUU"));
}
BOOST_AUTO_TEST_CASE(phenylalaine2)
{
  BOOST_REQUIRE_EQUAL("Phenylalanine", protein_translation::protein_translation("UUC"));
}
BOOST_AUTO_TEST_CASE(leucine1)
{
  BOOST_REQUIRE_EQUAL("Leucine", protein_translation::protein_translation("UUA"));
}
BOOST_AUTO_TEST_CASE(leucine2)
{
  BOOST_REQUIRE_EQUAL("Leucine", protein_translation::protein_translation("UUG"));
}
BOOST_AUTO_TEST_CASE(serine1)
{
  BOOST_REQUIRE_EQUAL("Serine", protein_translation::protein_translation("UCU"));
}
BOOST_AUTO_TEST_CASE(serine2)
{
  BOOST_REQUIRE_EQUAL("Serine", protein_translation::protein_translation("UCC"));
}
BOOST_AUTO_TEST_CASE(serine3)
{
  BOOST_REQUIRE_EQUAL("Serine", protein_translation::protein_translation("UCA"));
}
BOOST_AUTO_TEST_CASE(serine4)
{
  BOOST_REQUIRE_EQUAL("Serine", protein_translation::protein_translation("UCG"));
}
BOOST_AUTO_TEST_CASE(tryosine1)
{
  BOOST_REQUIRE_EQUAL("Tryosine", protein_translation::protein_translation("UAU"));
}
BOOST_AUTO_TEST_CASE(tryosine2)
{
  BOOST_REQUIRE_EQUAL("Tryosine", protein_translation::protein_translation("UAC"));
}
BOOST_AUTO_TEST_CASE(cysteine1)
{
  BOOST_REQUIRE_EQUAL("Cysteine", protein_translation::protein_translation("UGU"));
}
BOOST_AUTO_TEST_CASE(cysteine2)
{
  BOOST_REQUIRE_EQUAL("Cysteine", protein_translation::protein_translation("UGC"));
}
BOOST_AUTO_TEST_CASE(tryptophan)
{
  BOOST_REQUIRE_EQUAL("Tryptophan", protein_translation::protein_translation("UGG"));
}
BOOST_AUTO_TEST_CASE(stop1)
{
  BOOST_REQUIRE_EQUAL("", protein_translation::protein_translation("UAA"));
}
BOOST_AUTO_TEST_CASE(stop2)
{
  BOOST_REQUIRE_EQUAL("", protein_translation::protein_translation("UAG"));
}
BOOST_AUTO_TEST_CASE(stop3)
{
  BOOST_REQUIRE_EQUAL("", protein_translation::protein_translation("UGA"));
}
BOOST_AUTO_TEST_CASE(list1)
{
  BOOST_REQUIRE_EQUAL("Methionine","Phenylalanine","Tryptophan", protein_translation::protein_translation("AUGUUUUGG"));
}
BOOST_AUTO_TEST_CASE(list2)
{
  BOOST_REQUIRE_EQUAL("", protein_translation::protein_translation("UAGUGG"));
}
BOOST_AUTO_TEST_CASE(list3)
{
  BOOST_REQUIRE_EQUAL("Tryptophan", protein_translation::protein_translation("UGGUAG"));
}
BOOST_AUTO_TEST_CASE(list4)
{
  BOOST_REQUIRE_EQUAL("Methionine","Phenylalanine", protein_translation::protein_translation("AUGUUUUAA"));
}
BOOST_AUTO_TEST_CASE(list5)
{
  BOOST_REQUIRE_EQUAL("Tryptophan", protein_translation::protein_translation("UGGUAGUGG"));
}
BOOST_AUTO_TEST_CASE(list6)
{
  BOOST_REQUIRE_EQUAL("Tryptophan","Cysteine","Tyrosine", protein_translation::protein_translation("UGGUGUUAUUAAUGGUUU"));
}
#endif
