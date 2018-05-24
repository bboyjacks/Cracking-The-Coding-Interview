#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <gtest/gtest.h>


namespace
{
  class ArraysChallenge : public ::testing::Test
  {

  };

  TEST_F(ArraysChallenge, test_something)
  {
    ASSERT_TRUE(true);
  }
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  const int result = RUN_ALL_TESTS();
  std::getchar();
  return result;
}