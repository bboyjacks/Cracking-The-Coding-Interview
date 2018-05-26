#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <gtest/gtest.h>

// Problem 1.2
void Reverse(char* str)
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

// Problem 1.3
bool IsPermutation(std::string _str1, std::string _str2)
{
  bool isPermutation{ false };
  if (_str1.size() == _str2.size())
  {
    std::sort(_str1.begin(), _str1.end());
    std::sort(_str2.begin(), _str2.end());
    if (_str1 == _str2)
      isPermutation = true;
  }
  return isPermutation;
}

// Problem 1.4
void ReplaceSpaceWithTwenty(char* _str, const unsigned int _strSize)
{
  char* end = _str;
  unsigned int total_str_space = 0;
  while (*end)
  {
    total_str_space++;
    ++end;
  }
  total_str_space--;
  for (unsigned int real_index = _strSize - 1; real_index > 0; real_index--)
  {
    if (_str[real_index] != ' ')
      _str[total_str_space] = _str[real_index];
    else
    {
      _str[total_str_space] = '0';
      _str[--total_str_space] = '2';
      _str[--total_str_space] = '%';
    }
    total_str_space--;
  }
}

// Problem 1.5
std::string CompressStr(const std::string& _str)
{
  char cur_char = '\0';
  int cur_char_count = 0;
  std::vector<char> comp_result;

  const auto flush_comp_chars = [&comp_result, &cur_char, &cur_char_count]()
  {
    comp_result.push_back(cur_char);
    comp_result.push_back('0' + cur_char_count);
    cur_char_count = 1;
  };

  for (unsigned int i = 0; i < _str.size(); i++)
  {
    if (_str[i] == cur_char || i == 0)
    {
      cur_char_count++;
    }
    else
    {
      if (i != 0)
      {
        flush_comp_chars();
      }
    }
    cur_char = _str[i];
  }

  flush_comp_chars();

  if (comp_result.size() >= _str.size())
    return _str;
  else
  {
    std::string result(comp_result.begin(), comp_result.end());
    return result;
  }
}

TEST(problem_1_2)
{
  char* nullStr = nullptr;
  Reverse(nullStr);
  ASSERT_TRUE(nullStr == nullptr);

  char emptyStr[] = "";
  Reverse(emptyStr);
  ASSERT_STREQ("", emptyStr);

  char str[] = "String";
  Reverse(str);
  ASSERT_STREQ("gnirtS", str);

  char head[] = "head";
  Reverse(head);
  ASSERT_STREQ("daeh", head);
}

TEST(problem_1_3)
{
  ASSERT_TRUE(IsPermutation("", ""));
  ASSERT_TRUE(IsPermutation("string", "rginst"));
}

TEST(problem_1_4)
{
  char str[] = "Mr John Smith    ";
  ReplaceSpaceWithTwenty(str, 13);
  ASSERT_STREQ("Mr%20John%20Smith", str);
}

TEST(problem_1_5)
{
  const std::string result1 = CompressStr("aabcccccaaa");
  ASSERT_STREQ("a2b1c5a3", result1.c_str());

  const std::string result2 = CompressStr("abc");
  ASSERT_STREQ("abc", result2.c_str());

  const std::string result3 = CompressStr("");
  ASSERT_STREQ("", result3.c_str());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  const int result = RUN_ALL_TESTS();
  std::getchar();
  return result;
}