// Copyright 2020 Dolbnin Mikhail dolbnin@protonmail.com

#ifndef INCLUDE_DIRPARSE_HPP_
#define INCLUDE_DIRPARSE_HPP_

#include <string>
#include <boost/filesystem.hpp>
#include <iostream>

namespace file = boost::filesystem;

class dirParse {
 public:
  explicit dirParse(const std::string& path);
  friend std::ostream& operator <<(std::ostream& out, const dirParse& path);
 private:
  file::path pathToFtp;
};

#endif  // INCLUDE_DIRPARSE_HPP_
