// Copyright 2020 Dolbnin Mikhail dolbnin@protonmail.com

#ifndef INCLUDE_DIRPARSE_HPP_
#define INCLUDE_DIRPARSE_HPP_

#include <string>
#include <boost/filesystem.hpp>
#include <iostream>
#include <vector>
#include <sstream>

namespace file = boost::filesystem;

class dirParse {
 public:
  std::stringstream printAccount(const file::path& elem) const;
  explicit dirParse(const std::string& path);
  friend std::ostream& operator <<(std::ostream& out, const dirParse& A);
 private:
  file::path pathToFtp;
  std::vector<file::path> pathArr;
};

#endif  // INCLUDE_DIRPARSE_HPP_
