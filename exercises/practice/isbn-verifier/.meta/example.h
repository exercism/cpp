#if !defined(ISBN_VERIFIER_H)
#define ISBN_VERIFIER_H

#include <string>

namespace isbn_verifier {
bool is_valid(const std::string& isbn);
}  // namespace isbn_verifier

#endif  // ISBN_VERIFIER_H
