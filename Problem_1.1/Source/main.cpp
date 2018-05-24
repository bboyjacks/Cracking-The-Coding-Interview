#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <gtest/gtest.h>


void reverse(char* str)
{
  if (str != nullptr)
  {
    // count num of chars
    unsigned int arraySize = 0;
    unsigned int curIndex = 0;
    while (str[curIndex] != '\0')
    {
      arraySize++;
      curIndex++;
    }

    for (unsigned int i = 0; i < (int)(arraySize / 2); i++)
    {
      const char temp = str[i];
      str[i] = str[arraySize - 1 - i];
      str[arraySize - 1 - i] = temp;
    }
  }
}

TEST(problem_1_2)
{
  char* nullStr = nullptr;
  reverse(nullStr);
  ASSERT_TRUE(nullStr == nullptr);

  char emptyStr[] = "";
  reverse(emptyStr);
  ASSERT_STREQ("", emptyStr);

  char str[] = "String";
  reverse(str);
  ASSERT_STREQ("gnirtS", str);

  char head[] = "head";
  reverse(head);
  ASSERT_STREQ("daeh", head);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  const int result = RUN_ALL_TESTS();
  std::getchar();
  return result;
}