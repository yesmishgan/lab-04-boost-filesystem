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
