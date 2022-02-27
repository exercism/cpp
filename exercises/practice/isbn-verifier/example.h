#if !defined(EXAMPLE_H)
#define EXAMPLE_H

#include <string>

namespace isbn_verifier {
    bool is_valid(const std::string& isbn);
} // namespace isbn_verifier

#endif // EXAMPLE_H