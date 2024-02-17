#pragma once

#include <string>
#include <string_view>

namespace pig_latin {

[[nodiscard]] std::string translate(std::string_view sentence);

}  // namespace pig_latin
