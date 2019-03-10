/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_PHONE_NUMBER_H
#define VT_PHONE_NUMBER_H

#define EXERCISM_RUN_ALL_TESTS 1

#include <string>

class phone_number {
private:
  static constexpr std::size_t kNumLen_{ 10UL };
  std::string number_;

public:
  phone_number(const std::string& unparsed_num);

private:
  [[noreturn]] void invalid(std::string reason);
  std::string parse(const std::string& number) const;

public:
  std::string number() const noexcept;
  std::string area_code() const;
  
  std::string to_string() const;
  
public: // operator overloads
  operator std::string() const;

};

#endif

