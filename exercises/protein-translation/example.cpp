#include "protein_translation.h"
#include <string>
#include <vector>

namespace protein_translation
{
//creates codons and checks if codon has valid protein translation, if it does
//then it adds to vector of proteins and returns the vector 
std::vector <std::string> protein_translation(std::string rna)
{
    std::vector<std::string> proteins;
    std::vector <std::string> methionine = {"AUG"};
    std::vector <std::string> phenylalanine= {"UUU", "UUC"};
    std::vector <std::string> leucine = {"UUA","UUG"};
    std::vector <std::string> serine = {"UCU","UCC","UCA","UCG"};
    std::vector <std::string> tyrosine = {"UAU", "UAC"};
    std::vector <std::string> cysteine = {"UGU", "UGC"};
    std::vector <std::string> tryptophan = {"UGG"};
    std::vector <std::string> stop = {"UAA", "UAG", "UGA"};
    std::vector<std::string>::iterator it;
    for(int i = 0; i < rna.length(); i = i+3)
    {
        std::string codon;
        codon += rna[i];
        codon += rna[i+1];
        codon += rna[i+2];
        if(isProtein(methionine, codon) == true)
        {
            proteins.push_back("Methionine");
        }
        else if(isProtein(phenylalanine, codon) == true)
        {
            proteins.push_back("Phenylalanine");
        }
        else if(isProtein(leucine, codon) == true)
        {
            proteins.push_back("Leucine");
        }
        else if(isProtein(serine, codon) == true)
        {
            proteins.push_back("Serine");
        }
        else if(isProtein(tyrosine, codon) == true)
        {
            proteins.push_back("Tyrosine");
        }
        else if(isProtein(cysteine, codon) == true)
        {
            proteins.push_back("Cysteine");
        }
        else if(isProtein(tryptophan, codon) == true)
        {
            proteins.push_back("Tryptophan");
        }
        else if (isProtein(stop, codon) == true)
        {
            break;
        }
        else
        {
            cout<<"invalid input\n";
        }
    }
    return proteins;
}
//helper function to check if the codon has a valid protein translation
bool isProtein(std::vector<std::string> tofind, std::string codon)
{
    bool check;
    check = (std::find(tofind.begin(), tofind.end(), codon) != tofind.end());
    return check;
}
    
}
