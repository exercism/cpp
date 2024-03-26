#if !defined(TWO_FER_H)
#define TWO_FER_H

#include <string>

namespace two_fer {
inline std::string two_fer(const std::string& name = "you") {
    return "One for " + name + ", one for me.";
}
}  // namespace two_fer

#endif  // TWO_FER_H
