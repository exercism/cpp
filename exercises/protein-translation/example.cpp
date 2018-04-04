#include "protein_translation.h"
#include <string>

namespace protein_translation
{
   void protein_translation(std::string rna)
   {
      int i;
      std::vector<string> codons;
      std::string sequence;
      std::vector< std::make_pair<string, string> > table;
      table.push_back(std::make_pair("AUG", "Methionine"));
      table.push_back(std::make_pair("UUU", "Phenylalanine"));
      table.push_back(std::make_pair("UUC", "Phenylalanine"));
      table.push_back(std::make_pair("UUA", "Leucine"));
      table.push_back(std::make_pair("UUG", "Leucine"));
      table.push_back(std::make_pair("UCU", "Serine"));
      table.push_back(std::make_pair("UCC", "Serine"));
      table.push_back(std::make_pair("UCA", "Serine"));
      table.push_back(std::make_pair("UCG", "Serine"));
      table.push_back(std::make_pair("UAU", "Tyrosine"));
      table.push_back(std::make_pair("UAC", "Tyrosine"));
      table.push_back(std::make_pair("UGU", "Cysteine"));
      table.push_back(std::make_pair("UGC", "Cysteine"));
      table.push_back(std::make_pair("UGG", "Tryptophan"));
      table.push_back(std::make_pair("UAA", "STOP"));
      table.push_back(std::make_pair("UAG", "STOP"));
      table.push_back(std::make_pair("UGA", "STOP"));
      for(i = 0; i < strlen(rna); i = i+3)
      {
          sequence += rna[i];
          sequence += rna[i+1];
          sequence += rna[i+2];
          codons.push_back(sequence);
          sequence.clear();
      }
      
      
      
   }
}
