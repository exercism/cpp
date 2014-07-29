#if !defined(POINT_MUTATIONS_H)
#define POINT_MUTATIONS_H

#include <string>

namespace mutations
{

class dna_sequence
{
public:
    dna_sequence(std::string const& sequence);

    int hamming_distance(std::string const& other_sequence) const;

private:
    const std::string sequence_;
};

}

#endif
