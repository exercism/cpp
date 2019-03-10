/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT
 * <http://www.opensource.org/licenses/MIT>
 */

#include "phone_number.h"

#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <cctype>

void phone_number::invalid(std::string reason = "")
{
  std::string error{ "error: " + reason };
  throw std::domain_error(error);
}


std::string phone_number::parse(const std::string& number) const
{
  std::string parsed_number{};
  for (const auto c: number) {
    if (c >= '0' and c <= '9')
      parsed_number += c;
  }
  return parsed_number;
}

phone_number::phone_number(const std::string& unparsed_num)
{
  std::string num{ phone_number::parse(unparsed_num) };
  
  const std::size_t num_len{ num.length() };
  
  const std::size_t first{
    static_cast<std::size_t>(num_len == kNumLen_ + 1)
  };
  
  if (((num_len == kNumLen_) or (first == 1 and num[0] == '1'))
  and num[first + 3] >= '2' and num[first] >= '2') {
    this->number_ = std::string(num.begin() + first, num.end());
  } else {
    phone_number::invalid("reasons");
  }
}

std::string phone_number::number() const noexcept
{ return this->number_; }

std::string phone_number::area_code() const
{ return this->number_.substr(0, 3); }

std::string phone_number::to_string() const
{
  std::stringstream num;
  
  num << "(" << this->number_.substr(0, 3) << ") "
      << number_.substr(3, 3) << "-" << number_.substr(6)
  ;
  
  return num.str();
}

phone_number::operator std::string() const
{ return phone_number::to_string(); }
