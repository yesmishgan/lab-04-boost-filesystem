// Copyright 2020 Dolbnin Mikhail dolbnin@protonmail.com

#include "dirParse.hpp"
#include <regex>
#include <iomanip>


namespace file = boost::filesystem;

dirParse::dirParse(const std::string& path){
  const std::regex re(
      "^(balance_)\\d\\d\\d\\d\\d\\d\\d\\d_\\d\\d\\d\\d\\d\\d\\d\\d");
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
            && (y.path().extension() == ".txt")
            && (std::regex_search(y.path().stem().string(), re))) {
          std::cout << std::left << std::setw(10)
                    << y.path().parent_path().filename().string() << " "
                    << y.path().filename().string() << '\n';
          pathArr.push_back(y.path());
          nameAccounts.insert(y.path().stem().string().substr(8, 8));
        }
      }
    }
  }
}

std::stringstream dirParse::printAccount(const file::path& elem,
                                         const size_t& n) const{
  std::stringstream ss;
  ss << "broker: " << std::left << std::setw(8)
     << elem.parent_path().filename().string()
     << " account: " << elem.stem().string().substr(8, 8)
     << " files: " << std::setw(3) << n
     << " lastdate: " << elem.stem().string().substr(17, 8);
  return ss;
}

std::ostream& operator <<(std::ostream& out, const dirParse& A){
  for (const auto & el : A.nameAccounts) {
    std::vector<file::path> temp;
    for (const auto & i : A.pathArr) {
      if (el == i.stem().string().substr(8, 8)){
        temp.push_back(i);
      }
    }
    file::path max = temp[0];
    size_t n = 0;
    for (const auto & j : temp) {
      if (max.stem().string().substr(17, 8)
          < j.stem().string().substr(17, 8)) {
        max = j;
      }
      n++;
    }
    out << A.printAccount(max, n).str() << std::endl;
  }
  return out;
}

dirParse::~dirParse() {}

const file::path& dirParse::getPathToAccount(const size_t& n) const {
  return pathArr[n];
}
