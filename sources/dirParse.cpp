// Copyright 2020 Dolbnin Mikhail dolbnin@protonmail.com

#include "dirParse.hpp"

namespace file = boost::filesystem;

dirParse::dirParse(const std::string& path){
  if (!path.empty()) {
    if (file::exists(path)) {
      pathToFtp = path;
    }
  } else {
    pathToFtp = file::current_path();
  }
  for (const file::directory_entry& x : file::directory_iterator{pathToFtp})
  {
    if (file::is_directory(x.path())){
      for (const file::directory_entry& y : file::directory_iterator{x.path()}){
        if ((y.path().stem().extension() == "")
            && (y.path().extension() == ".txt")) // std::regex "balance_[*]"
        std::cout << y.path().parent_path().filename().string()
                  << " "
                  << y.path().filename().string() << '\n';
      }
    }
  }
  file::file_status a(file::status(path));
  std::cout << a.type();
}

std::ostream& operator <<(std::ostream& out, const dirParse& path){
  out << path.pathToFtp.string();
  return out;
}
