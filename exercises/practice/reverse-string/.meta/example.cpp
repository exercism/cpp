#include "reverse_string.h"

namespace reverse_string {

std::string reverse_string(const std::string& text) {
    return std::string(text.rbegin(), text.rend());
}

}  // namespace reverse_string
