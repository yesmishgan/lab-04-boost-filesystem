// Copyright 2020 Dolbnin Mikhail dolbnin@protonmail.com

#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
#include "dirParse.hpp"
#include <utility>

//int argc, char* argv[]
int main(){
  //if(argc > 1){
  //  std::string A(argv[1]);
  //  std::cout << A;
  //}
  //if(argc > 1)
  //dirParse B("aaaa");
  dirParse A("/Users/mishadolbnin/lab-04-boost-filesystem/ftp");
  std::cout << "test!";
  std::cout << A;
  return 0;
}
