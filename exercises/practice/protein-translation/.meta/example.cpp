#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

#include "protein_translation.h"

using namespace std;

vector<string> protein_translation::proteins(string rna) {
    unordered_map<string, string> dic;
    dic["AUG"] = "Methionine";
    dic["UUU"] = dic["UUC"] = "Phenylalanine";
    dic["UUA"] = dic["UUG"] = "Leucine";
    dic["UCU"] = dic["UCC"] = dic["UCA"] = dic["UCG"] = "Serine";
    dic["UAU"] = dic["UAC"] = "Tyrosine";
    dic["UGU"] = dic["UGC"] = "Cysteine";
    dic["UGG"] = "Tryptophan";
    dic["UAA"] = dic["UAG"] = dic["UGA"] = "STOP";

    vector<string> polypeptide;
    for (int i = 0; i < (int)rna.size() - 2; i += 3) {
        string codon = rna.substr(i, 3);
        auto it = dic.find(codon);
        if (it == dic.end() || it->second == "STOP") {
            break;
        }
        polypeptide.push_back(it->second);
    }
    return polypeptide;
}
