#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <map>
#include <string>

namespace dna
{

class counter
{
public:
    counter(std::string const& sequence);

    std::map<char, int> const& nucleotide_counts() const
    {
        return counts_;
    }

    int count(char nucleotide) const;

private:
    std::map<char, int> counts_;
};

}

#endif
