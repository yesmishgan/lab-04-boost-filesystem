// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <dirParse.hpp>

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(dirParse, testFuncPrint){
  dirParse A("/home/travis/build/yesmishgan/lab-04-boost-filesystem//ftp");
  ASSERT_EQ(
      A.printAccount(A.getPathToAccount(0), 1).str(),
      "broker: ip       account: 00001234 files: 1   lastdate: 20181001");
}

TEST(dirParse, testOverload){
  std::ostringstream output;
  dirParse A("/home/travis/build/yesmishgan/lab-04-boost-filesystem//ftp");
  output << A;
  EXPECT_EQ(output.str(), R"(
\nbroker: ip       account: 00001234 files: 1   lastdate: 20181001
\nbroker: ip       account: 00001346 files: 2   lastdate: 20181018
\nbroker: ip       account: 00003333 files: 1   lastdate: 20181001
\nbroker: ip.dos   account: 00003335 files: 1   lastdate: 20181001
\nbroker: ip.dos   account: 00003336 files: 1   lastdate: 20181001
\nbroker: bcs      account: 12341234 files: 1   lastdate: 20181001)");
}
